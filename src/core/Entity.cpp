/**
 * @file     Entity.cpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Methods of class Entity.
 */

#include "Entity.hpp"
#include "Player.hpp"
#include "Mob.hpp"
#include "Data.hpp"
#include "../EngineEvent.hpp"

using namespace std ;

Entity::Entity() : _integrity(0), _maxIntegrity(0), _armor(0), _typeEntity(""),_position(0), _direction(0), _delayedAction(false)
{
    _delayedActions = std::vector<Action*>() ;
    _parts = std::vector<Part>() ;
    _tmpEffects = std::vector<Effect>() ;
}

Entity::~Entity()
{
    _parts.clear() ;
    _tmpEffects.clear() ;
    _delayedActions.clear() ;
}

const Part& Entity::GetPart(const unsigned short int i) const
{
        return _parts[i] ;
}

void Entity::SetPosition(const short int value)
{
    if(value>7)
    {
        _position = 7 ;
    }
    else if(value< 0)
    {
        _position = 0 ;
    }
    else
    {
        _position = value ;
    }
}

void Entity::AddIntegrity(const int value, const bool checkPart)
{
    _integrity += value ;
    if(_integrity+value>_maxIntegrity)
    {
        _integrity = _maxIntegrity ;
    }
    if(!checkPart)
    {
        EngineEvent* message0 = new EngineEvent() ;
        message0->_type = _typeEntity.append("RushIntegrity") ;
        message0->_stringData.insert(pair<string,string>("value",Data::ToString(_integrity))) ;
        EngineEvent::SendToGraphic(message0) ;
    }

}

void Entity::AddMaxIntegrity(const int value)
{
    _maxIntegrity += value ;
    if(_integrity>_maxIntegrity)
    {
        _integrity = _maxIntegrity ;
    }
}

void Entity::AddArmor(const short int value, const bool checkPart)
{
    _armor += value ;
    if(_typeEntity.compare("Player")==0 && !checkPart)
    {
        EngineEvent* message0 = new EngineEvent() ;
        message0->_type = _typeEntity.append("RushArmor") ;
        message0->_stringData.insert(pair<string,string>("value",Data::ToString(_integrity))) ;
        EngineEvent::SendToGraphic(message0) ;
    }
}

void Entity::AddTmpEffect(const int value, const string typeEffect)
{
    Effect tmp(value, 0, typeEffect, 0) ;
    _tmpEffects.push_back(tmp) ;
}

void Entity::TakeDamage(const unsigned int damage, const bool armorIgnored)
{
    if (armorIgnored)
    {
        AddIntegrity(-damage) ;
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = _typeEntity.append("TakeDamage") ;
        message1->_stringData.insert(pair<string,string>("value",Data::ToString(damage))) ;
        EngineEvent::SendToCore(message1) ;
    }
    else
    {
        AddIntegrity(-damage+_armor) ;
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = _typeEntity.append("TakeDamage") ;
        message1->_stringData.insert(pair<string,string>("value",Data::ToString(damage-_armor))) ;
        EngineEvent::SendToCore(message1) ;
    }
    if(_typeEntity.compare("Player")==0 && _integrity<=0)
    {
        EngineEvent* message0 = new EngineEvent() ;
        message0->_type = "endRush" ;
        EngineEvent::SendToCore(message0) ;
    }
    else if(_typeEntity.compare("Mob")==0 && _integrity<=0)
    {
        EngineEvent* message0 = new EngineEvent() ;
        message0->_type = "endBattle" ;
        EngineEvent::SendToCore(message0) ;
    }
}

void Entity::AddPart(const string type, Player& player)
{
    Part tmp;
    tmp.LoadPart(type, player) ;
    _parts.push_back(tmp) ;
}

void Entity::AddPart(const string type, Mob& mob, string biome, const unsigned short int difficulty)
{
    Part tmp;
    tmp.LoadPart(type, mob, biome, difficulty) ;
    _parts.push_back(tmp) ;
}

void Entity::SendPositionToGraphic()
{
    EngineEvent* message0 = new EngineEvent() ;
    message0->_type = _typeEntity.append("RushMove") ;
    message0->_stringData.insert(pair<string,string>("position",Data::ToString(_position))) ;
    EngineEvent::SendToGraphic(message0) ;
}

void Entity::MoveLeft(Entity& enemy)
{
    if(_position!=0 && enemy.GetPosition()!=(_position-1))
    {
        _position-- ;
        SendPositionToGraphic() ;
        if(_direction!=0)
        {
            Rotate() ;
        }
    }
}

void Entity::MoveRight(Entity& enemy)
{
    if(_position!=7 && enemy.GetPosition()!=(_position+1))
    {
        _position++ ;
        SendPositionToGraphic() ;
        if(_direction!=1)
        {
            Rotate() ;
        }
    }
}

void Entity::MoveLeftx2(Entity& enemy)
{
    if(_position!=0 && _position!=1 && enemy.GetPosition()!=(_position-2))
    {
        _position-=2 ;
        SendPositionToGraphic() ;
        if(_direction!=0)
        {
            Rotate() ;
        }
    }
}

void Entity::MoveRightx2(Entity& enemy)
{
    if(_position!=7 && _position!=6 && enemy.GetPosition()!=(_position+2))
    {
        _position+=2 ;
        SendPositionToGraphic() ;
        if(_direction!=1)
        {
            Rotate() ;
        }
    }
}

void Entity::MoveToEnemy(Entity& enemy, const int value)
{
    if(_position<enemy.GetPosition())
    {
        for(int i=0; i<value; i++)
        {
            MoveRight(enemy) ;
        }
    }
    else
    {
        for(int i=0; i<value; i++)
        {
            MoveLeft(enemy) ;
        }
    }
    SendPositionToGraphic() ;
}

void Entity::Rotate()
{
    if(_direction==0)
    {
        _direction = 1 ;
    }
    else
    {
        _direction = 0 ;
    }
    EngineEvent* message0 = new EngineEvent() ;
    message0->_type = _typeEntity.append("RushRotate") ;
    message0->_stringData.insert(pair<string,string>("direction",Data::ToString(_direction))) ;
    EngineEvent::SendToGraphic(message0) ;
}

void Entity::DisplayEntity(std::string typeMessage)
{
    for(unsigned short int i=0;i<_parts.size();i++)
    {
        _parts[i].DisplayPart(typeMessage) ;
    }
}

void Entity::AddDelayedAction(Action* action)
{
    _delayedActions.push_back(action) ;
}

