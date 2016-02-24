/**
 * @file     Mob.cpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Methods of class Mob.
 */

#include "Mob.hpp"
#include "Player.hpp"
#include "../EngineEvent.hpp"
#include "Data.hpp"

using namespace std ;

Mob::Mob(const string biome, unsigned short int difficulty) : Entity(), _numberOfAction(0), _currentNumberOfAction(0)
{
    _typeEntity = "Mob" ;
    for(int i=0;i<4;i++)
    {
        switch(i)
        {
            case 0 : AddPart("head",*this,biome, difficulty) ; break ;
            case 1 : AddPart("chest",*this,biome, difficulty) ; break ;
            case 2 : AddPart("arm",*this,biome, difficulty) ; break ;
            case 3 : AddPart("legs",*this,biome, difficulty) ; break ;
            default : break ;
        }
    }
    if(difficulty<1)
    {
        _numberOfAction += 1 ;
    }
    else if(difficulty<4)
    {
        _numberOfAction += 2 ;
    }
    else if(difficulty<7)
    {
        _numberOfAction += 3 ;
    }
    else if(difficulty<10)
    {
        _numberOfAction += 4 ;
    }
    else
    {
        _numberOfAction += 5 ;
    }
}

Mob::~Mob()
{

}

void Mob::DoTurn(Player& enemy)
{
    vector<string> tmp ;
    string type ;
    if(!_tmpEffects.empty())
    {
        DoTmpEffect(enemy) ;
    }
    for(unsigned short int i=0;i<_delayedActions.size();i++)
    {
        _delayedActions[i]->DoActionDelayed(enemy, *this, true) ;
        _delayedActions.erase(_delayedActions.begin()+i) ;
    }
    tmp = Data::SplitString(_parts[2].GetDescription(),"+") ;
    _currentNumberOfAction = _numberOfAction ;
    for(unsigned short int  i=0;i<tmp.size()||_currentNumberOfAction>0;i++)
    {
        type = Data::ToString(i) ;
        if(tmp[i].compare("special")==0)
        {
            MoveToDoAction(enemy, type) ;
            if(_currentNumberOfAction>0)
            {
                _parts[2].DoAction(type, enemy, *this, true) ;
                SubAction() ;
            }
        }
        else if(tmp[i].compare("run")==0)
        {
            short int enemyPosition = enemy.GetPosition() ;
            short int mobPosition = GetPosition() ;
            if(enemyPosition>mobPosition && enemyPosition-mobPosition<2)
            {
                Mob::MoveLeft(enemy) ;
                SubAction() ;
            }
            else if(enemyPosition<mobPosition && mobPosition-enemyPosition<2)
            {
                Mob::MoveRight(enemy) ;
                SubAction() ;
            }
        }
        else if(tmp[i].compare("push")==0)
        {
            short int enemyPosition = enemy.GetPosition() ;
            short int mobPosition = GetPosition() ;
            if(enemyPosition==(mobPosition-1))
            {
                if(_direction!=0)
                {
                    Rotate() ;
                    SubAction() ;
                }
                if(_currentNumberOfAction>0)
                {
                    _parts[2].DoAction(type, enemy, *this, true) ;
                    SubAction() ;
                }
            }
            else if(enemyPosition==(mobPosition+1))
            {
                if(_direction!=1)
                {
                    Rotate() ;
                    SubAction() ;
                }
                if(_currentNumberOfAction>0)
                {
                    _parts[2].DoAction(type, enemy, *this, true) ;
                    SubAction() ;
                }
            }
        }
        else
        {
            MoveToDoAction(enemy, type) ;
            if(_currentNumberOfAction>0)
            {
                while(_currentNumberOfAction>0)
                {
                    _parts[2].DoAction(type, enemy, *this, true) ;
                    SubAction() ;
                }
            }
        }
    }
}



void Mob::DoTmpEffect(Player& enemy)
{
    for(unsigned short int i=0;i<_tmpEffects.size();i++)
    {
        _tmpEffects[i].DoEffect(enemy, *this, true) ;
    }
    _tmpEffects.clear() ;
}

void Mob::MoveToDoAction(Player& enemy, string type)
{
    _parts[2].MoveToDoAction(enemy, *this, type) ;
}

void Mob::MoveRight(Player& enemy)
{
    if(_immobilize)
    {
        _immobilize = false ;
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "mobNotImmobilize" ;
        EngineEvent::SendToGraphic(message1) ;
    }
    else
    {
        Entity::MoveRight(enemy) ;
    }
}

void Mob::MoveLeft(Player& enemy)
{
    if(_immobilize)
    {
        _immobilize = false ;
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "mobNotImmobilize" ;
        EngineEvent::SendToGraphic(message1) ;
    }
    else
    {
        Entity::MoveLeft(enemy) ;
    }

}

void Mob::MoveLeftx2(Player& enemy)
{
    if(_immobilize)
    {
        _immobilize = false ;
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "mobNotImmobilize" ;
        EngineEvent::SendToGraphic(message1) ;
    }
    else
    {
        Entity::MoveLeftx2(enemy) ;
    }

}

void Mob::MoveRightx2(Player& enemy)
{
    if(_immobilize)
    {
        _immobilize = false ;
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "mobNotImmobilize" ;
        EngineEvent::SendToGraphic(message1) ;
    }
    else
    {
        Entity::MoveRightx2(enemy) ;
    }

}

void Mob::MoveToEnemy(Player& enemy, const int value)
{
    if(_immobilize)
    {
        _immobilize = false ;
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "mobNotImmobilize" ;
        EngineEvent::SendToGraphic(message1) ;
    }
    else
    {
        Entity::MoveToEnemy(enemy, value) ;
    }

}

void Mob::AddMaxAction(const short int value)
{
    _numberOfAction += value ;
    if(_numberOfAction<0)
    {
        _numberOfAction = 0 ;
    }
}
