/**
 * @file     Action.cpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Methods of class Action.
 */

#include "Action.hpp"
#include "Mob.hpp"
#include "Player.hpp"
#include "Data.hpp"
#include "../EngineEvent.hpp"

using namespace std ;

Action::Action(const unsigned short int pressureCost, const short int minDistance, const short int maxDistance, std::string infoEffects, const std::string direction, const unsigned short int level)
               : _pressureCost(pressureCost), _direction(direction), _minDistance(minDistance), _maxDistance(maxDistance)
{
    for(int i=0;infoEffects.find(string("value").append(Data::ToString(i)))!= string::npos;i++)
    {
        AddEffect(Data::ToInt(Data::SearchInString(infoEffects,string("value").append(Data::ToString(i)))),
                  Data::ToInt(Data::SearchInString(infoEffects, string("perLevel").append(Data::ToString(i)))),
                  Data::SearchInString(infoEffects,string("typeEffect").append(Data::ToString(i))),
                  level) ;
    }
}

Action::~Action()
{
    _effects.clear() ;
}

void Action::DoAction(Player& player, Mob& enemy, bool mobTurn)
{
    short int enemyPosition = enemy.GetPosition() ;
    short int playerPosition = player.GetPosition() ;
    if(mobTurn)
    {
        if(playerPosition>enemyPosition+_minDistance && playerPosition<enemyPosition+_maxDistance && ((enemyPosition<playerPosition && enemy.GetDirection()==1) || (enemyPosition>playerPosition && enemy.GetDirection()==0)) )
        {
            for(unsigned short int i=0;i<_effects.size();i++)
            {
                _effects[i].DoEffect(player, enemy, mobTurn) ;
            }
            if(enemy.GetDelayedAction())
            {
                enemy.AddDelayedAction(this);
            }
        }
    }
    else
    {
        if(player.GetPressure()>_pressureCost)
        {
            if(_direction.compare("left")==0 || _direction.compare("right")==0)
            {
                player.Rotate() ;
            }
            if((enemyPosition>=playerPosition+_minDistance && enemyPosition<=playerPosition+_maxDistance && ((playerPosition<enemyPosition && player.GetDirection()==1) || (playerPosition>enemyPosition && player.GetDirection()==0)))
               || (_minDistance==0 && _maxDistance==0))
            {
                for(unsigned short int i=0;i<_effects.size();i++)
                {
                    _effects[i].DoEffect(player, enemy) ;
                }
                if(_pressureCost==-1)
                {
                    player.SubPressure(player.GetPressure()) ;
                }
                else
                {
                    player.SubPressure(_pressureCost) ;
                }
                if(player.GetPressure()==0)
                {
                    player.ProcHead("0pressure", enemy) ;
                }
                if(player.GetDelayedAction())
                {
                    player.AddDelayedAction(this);
                }
            }
            else
            {
                EngineEvent* message1 = new EngineEvent() ;
                message1->_type = "targetError" ;
                EngineEvent::SendToGraphic(message1) ;
            }
        }
        else
        {
            EngineEvent* message1 = new EngineEvent() ;
            message1->_type = "pressureError" ;
            EngineEvent::SendToGraphic(message1) ;
        }
    }
}

void Action::DoActionDelayed(Player& player, Mob& enemy, bool mobTurn)
{
    short int enemyPosition = enemy.GetPosition() ;
    short int playerPosition = player.GetPosition() ;
    if(mobTurn)
    {
        if(playerPosition>enemyPosition+_minDistance && playerPosition<enemyPosition+_maxDistance && ((enemyPosition<playerPosition && enemy.GetDirection()==1) || (enemyPosition>playerPosition && enemy.GetDirection()==0)) )
        {
            for(unsigned short int i=0;i<_effects.size();i++)
            {
                _effects[i].DoEffectDelayed(player, enemy, mobTurn) ;
            }
        }
        else
        {
            if(_minDistance==0 && _maxDistance==0)
            {
                EngineEvent* message1 = new EngineEvent() ;
                message1->_type = string("explosion#At=").append(Data::ToString(_minDistance).append("~")) ;
                EngineEvent::SendToGraphic(message1) ;
            }
            else
            {
                EngineEvent* message1 = new EngineEvent() ;
                message1->_type = string("rushIntegrity#At=").append(Data::ToString(player.GetPosition()).append("~")) ;
                EngineEvent::SendToGraphic(message1) ;
            }
        }
    }
    else
    {
        if((enemyPosition>=playerPosition+_minDistance && enemyPosition<=playerPosition+_maxDistance && ((playerPosition<enemyPosition && player.GetDirection()==1) || (playerPosition>enemyPosition && player.GetDirection()==0)))
               || (_minDistance==0 && _maxDistance==0))
            {
                for(unsigned short int i=0;i<_effects.size();i++)
                {
                    _effects[i].DoEffectDelayed(player, enemy, mobTurn) ;
                }
            }
            else
            {
                if(_minDistance==0 && _maxDistance==0)
                {
                    EngineEvent* message1 = new EngineEvent() ;
                    message1->_type = string("explosion#At=").append(Data::ToString(_minDistance).append("~")) ;
                    EngineEvent::SendToGraphic(message1) ;
                }
                else
                {
                    EngineEvent* message1 = new EngineEvent() ;
                    message1->_type = string("rushIntegrity#At=").append(Data::ToString(player.GetPosition()).append("~")) ;
                    EngineEvent::SendToGraphic(message1) ;
                }
            }
    }
}

void Action::AddEffect(const int value, const int perLevel, const string typeEffect, const unsigned short int level)
{
    Effect tmp(value, perLevel, typeEffect, level) ;
    _effects.push_back(tmp) ;
}

void Action::CheckAction(Player& player, const bool forReloadPart)
{
    for(unsigned short int i=0;i<_effects.size();i++)
    {
        _effects[i].CheckEffect(player, forReloadPart) ;
    }
}

void Action::CheckAction(Mob& mob, const unsigned short int difficulty)
{
    for(unsigned short int i=0;i<_effects.size();i++)
    {
        _effects[i].CheckEffect(mob, difficulty) ;
    }
}

void Action::MoveToDoAction(Player& enemy, Mob& mob) const
{
    short int enemyPosition = enemy.GetPosition() ;
    short int mobPosition = mob.GetPosition() ;
    bool done = false ;
    while(mob.GetAction()>0 || !done)
    {
        if(enemyPosition<mobPosition && enemyPosition>mobPosition-_minDistance)
        {
            mob.MoveRight(enemy) ;
            mob.SubAction() ;
        }
        else if(enemyPosition>mobPosition && enemyPosition<mobPosition+_minDistance)
        {
            mob.MoveLeft(enemy) ;
            mob.SubAction() ;
        }
        else if(enemyPosition>mobPosition && enemyPosition>mobPosition+_maxDistance)
        {
            mob.MoveRight(enemy) ;
            mob.SubAction() ;
        }
        else if(enemyPosition<mobPosition && enemyPosition<mobPosition-_maxDistance)
        {
            mob.MoveLeft(enemy) ;
            mob.SubAction() ;
        }
        else
        {
            done = true ;
        }
    }
    if((enemyPosition<mobPosition && mob.GetDirection()!=0) || (enemyPosition>mobPosition && mob.GetDirection()!=1))
    {
        mob.Rotate() ;
        mob.SubAction() ;
    }
}
