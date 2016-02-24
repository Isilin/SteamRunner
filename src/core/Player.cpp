/**
 * @file     Player.cpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Methods of class Player.
 */

#include "Player.hpp"
#include "Mob.hpp"
#include "Part.hpp"
#include "Data.hpp"
#include "../EngineEvent.hpp"

using namespace std ;

Player::Player() : Entity(), _pressure(0), _maxPressure(0), _initialPressure(0), _pressurePerTurn(0), _steam(0), _convertionRate(0), _enteringInBuilding(false), _partActive("")
{
    _typeEntity = "Player" ;
    _initialPressure = Data::ToInt(Data::SearchInString(Data::Read("Save","initialPressure"),"value0")) ;
    _maxPressure = Data::ToInt(Data::SearchInString(Data::Read("Save","maxPressure"),"value0")) ;
    _convertionRate = Data::ToInt(Data::SearchInString(Data::Read("Save","convertionRate"),"value0")) ;
    for(int i=0;i<5;i++)
    {
        switch(i)
        {
            case 0 : AddPart("head",*this) ; break ;
            case 1 : AddPart("chest",*this) ; break ;
            case 2 : AddPart("arm",*this) ; break ;
            case 3 : AddPart("legs",*this) ; break ;
            case 4 : AddPart("leftArm",*this) ; break ;
            default : break ;
        }
    }

}

Player::~Player()
{

}

void Player::AddPressurePerTurn(const short int value, const bool checkPart)
{
    _pressurePerTurn += value ;
    if(_pressurePerTurn<0)
    {
        _pressurePerTurn = 0 ;
    }
    if(!checkPart)
    {
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "rushPressurePerTurn" ;
        message1->_stringData.insert(pair<string,string>("value",Data::ToString(_pressurePerTurn))) ;
        EngineEvent::SendToGraphic(message1) ;
    }

}

void Player::AddSteam(const int value, const bool checkPart)
{
    _steam += value ;
    if(!checkPart)
    {
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "rushSteam" ;
        message1->_stringData.insert(pair<string,string>("value",Data::ToString(_steam))) ;
        EngineEvent::SendToGraphic(message1) ;
    }
}

void Player::AddPressure(int value, const bool checkPart)
{
    if(_steam-value<0)
    {
        value = _steam ;
    }
    _steam -= value ;

    if(_pressure+value>_maxPressure)
    {
        _pressure = _maxPressure ;
    }
    else
    {
        _pressure += value ;
    }
    if(!checkPart)
    {
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "rushPressure" ;
        message1->_stringData.insert(pair<string,string>("value",Data::ToString(_pressure))) ;
        EngineEvent::SendToGraphic(message1) ;
    }

}

void Player::SubPressure(const int value)
{
    if(_pressure>=value)
    {
        _pressure -= value ;
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "rushPressure" ;
        message1->_stringData.insert(pair<string,string>("value",Data::ToString(_pressure))) ;
        EngineEvent::SendToGraphic(message1) ;
    }
    else
    {
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "pressureError" ;
        EngineEvent::SendToGraphic(message1) ;
    }
}

void Player::Reroll(string typePart)
{
    string tmp ;

    for(unsigned short int i=0;i<_parts.size();i++)
    {
        tmp = _parts[i].GetType() ;
        tmp = tmp.substr(0,tmp.size()-2) ;
        if(tmp.compare(typePart)==0)
        {
            _parts[i].ReloadPart(*this) ;
        }
    }
}

void Player::StartBattle()
{
    _pressure = 0 ;
    AddPressure(_initialPressure) ;
    _delayedActions.clear() ;
    _tmpEffects.clear() ;
}

void Player::EndBattle()
{
    _steam += _pressure ;
    _pressure = 0 ;
    _delayedActions.clear() ;
    _tmpEffects.clear() ;
}

void Player::StartTurn(Mob& enemy)
{
    AddPressure(_pressurePerTurn) ;
    DoStartTurnAction(enemy) ;
}

void Player::DoAction(const string part, const string direction, Mob& enemy)
{
    string tmp ;
    for(unsigned int i=0 ; i<_parts.size() ; i++)
    {
        tmp = _parts[i].GetType() ;
        tmp = tmp.substr(0,tmp.size()-2) ;
        if (tmp.compare(part)==0)
        {
            _partActive = _parts[i].GetType() ;
            _parts[i].DoAction(direction, *this, enemy) ;
            _partActive = "" ;
        }
    }
}

void Player::DoTmpEffect(Mob& enemy)
{
    for(unsigned short int i=0;i<_tmpEffects.size();i++)
    {
        _tmpEffects[i].DoEffect(*this, enemy) ;
    }
    _tmpEffects.clear() ;
}

void Player::DoStartTurnAction(Mob& enemy)
{
    if(!_tmpEffects.empty())
    {
        DoTmpEffect(enemy) ;
    }
    for(unsigned short int i=0;i<_delayedActions.size();i++)
    {
        _delayedActions[i]->DoActionDelayed(*this, enemy) ;
        _delayedActions.erase(_delayedActions.begin()+i) ;
    }
}

void Player::MoveLeft(Mob& enemy)
{
    if(_immobilize)
    {
        _immobilize = false ;
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "playerNotImmobilize" ;
        EngineEvent::SendToGraphic(message1) ;
    }
    else
    {
        Entity::MoveLeft(enemy) ;
        if((_position-enemy.GetPosition())==1)
        {
            ProcHead("cac", enemy) ;
        }
    }

}

void Player::MoveRight(Mob& enemy)
{
    if(_immobilize)
    {
        _immobilize = false ;
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "playerNotImmobilize" ;
        EngineEvent::SendToGraphic(message1) ;
    }
    else
    {
        Entity::MoveRight(enemy) ;
        if((enemy.GetPosition()-_position)==1)
        {
            ProcHead("cac", enemy) ;
        }
    }
}

void Player::MoveLeftx2(Mob& enemy)
{
    if(_immobilize)
    {
        _immobilize = false ;
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "playerNotImmobilize" ;
        EngineEvent::SendToGraphic(message1) ;
    }
    else
    {
        Entity::MoveLeftx2(enemy) ;
        if((_position-enemy.GetPosition())==1)
        {
            ProcHead("cac", enemy) ;
        }
    }
}

void Player::MoveRightx2(Mob& enemy)
{
    if(_immobilize)
    {
        _immobilize = false ;
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "playerNotImmobilize" ;
        EngineEvent::SendToGraphic(message1) ;
    }
    else
    {
        Entity::MoveRightx2(enemy) ;
        if((enemy.GetPosition()-_position)==1)
        {
            ProcHead("cac", enemy) ;
        }
    }
}

void Player::MoveToEnemy(Mob& enemy, const int value)
{
    if(_immobilize)
    {
        _immobilize = false ;
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "playerNotImmobilize" ;
        EngineEvent::SendToGraphic(message1) ;
    }
    else if(_position<enemy.GetPosition())
    {
        for(int i=0; i<value; i++)
        {
            Player::MoveRight(enemy) ;
        }
    }
    else
    {
        for(int i=0; i<value; i++)
        {
            Player::MoveLeft(enemy) ;
        }
    }
}

void Player::ProcHead(string type, Mob& enemy)
{
    if(_parts[0].GetName().compare("RH1-N0")==0 && type.compare("cac")==0)
    {
        _parts[0].DoAction("up", *this, enemy) ;
    }
    if(_parts[0].GetName().compare("OV3-RL04D")==0 && type.compare("0pressure")==0)
    {
        _parts[0].DoAction("up", *this, enemy) ;
    }
    if(_parts[0].GetName().compare("LA-53R")==0 && type.compare("4actions")==0)
    {
        _parts[0].DoAction("up", *this, enemy) ;
    }
    if(_parts[0].GetName().compare("PRO-707-YP3")==0 && type.compare("0actions")==0)
    {
        _parts[0].DoAction("up", *this, enemy) ;
    }
    if(_parts[0].GetName().compare("PRO-707-YP3")==0 && type.compare("1actions")==0)
    {
        _parts[0].DoAction("right", *this, enemy) ;
    }
}
