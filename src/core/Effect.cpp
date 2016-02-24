/**
 * @file     Effect.cpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Methods of class Effect.
 */

#include "Effect.hpp"
#include "Player.hpp"
#include "Rush.hpp"
#include "Mob.hpp"
#include "../EngineEvent.hpp"

using namespace std ;

Effect::Effect(const int value, const int perLevel, const string typeEffect, const unsigned short int level) : _value(value), _perLevel(perLevel), _typeEffect(typeEffect)
{
    float tmp ;
    if(_perLevel<0)
    {
        tmp = (-_perLevel) ;
    }
    else
    {
        tmp = _perLevel ;
    }
    _value += level*tmp ;
}

Effect::~Effect()
{

}

void Effect::DoEffect(Player& player, Mob& enemy, bool mobTurn)
{
    if(_typeEffect.compare("attack")==0)
    {
        if(mobTurn)
        {
            player.TakeDamage(_value) ;
            EngineEvent* message1 = new EngineEvent() ;
            message1->_type = "effect" ;
            message1->_stringData.insert(pair<string,string>("type", "mobAttack")) ;
            EngineEvent::SendToGraphic(message1) ;
        }
        else
        {
            enemy.TakeDamage(_value) ;
            EngineEvent* message1 = new EngineEvent() ;
            message1->_type = "effect" ;
            message1->_stringData.insert(pair<string,string>("type", "playerAttack")) ;
            message1->_stringData.insert(pair<string,string>("part", player.GetActivePart())) ;
            EngineEvent::SendToGraphic(message1) ;
        }
    }
    else if(_typeEffect.compare("attackArmorIgnored")==0)
    {
        if(mobTurn)
        {
            player.TakeDamage(_value, true) ;
            EngineEvent* message1 = new EngineEvent() ;
            message1->_type = "mobAttack" ;
            message1->_stringData.insert(pair<string,string>("type", "mobAttack")) ;
            EngineEvent::SendToGraphic(message1) ;
        }
        else
        {
            enemy.TakeDamage(_value, true) ;
            EngineEvent* message1 = new EngineEvent() ;
            message1->_type = "effect" ;
            message1->_stringData.insert(pair<string,string>("type", "playerAttack")) ;
            message1->_stringData.insert(pair<string,string>("part", player.GetActivePart())) ;
            EngineEvent::SendToGraphic(message1) ;
        }
    }
    else if(_typeEffect.compare("pull")==0)
    {
        if(mobTurn)
        {
            if(enemy.GetPosition()<player.GetPosition() )
            {
                player.MoveLeft(enemy) ;
            }
            else
            {
                player.MoveRight(enemy) ;
            }
        }
        else
        {
            if(player.GetPosition()<enemy.GetPosition())
            {
                enemy.MoveLeft(player) ;
            }
            else
            {
                enemy.MoveRight(player) ;
            }
        }
    }
    else if(_typeEffect.compare("push")==0)
    {
        if(mobTurn)
        {
            if(enemy.GetPosition()<player.GetPosition() )
            {
                player.MoveRight(enemy) ;
            }
            else
            {
                player.MoveLeft(enemy) ;
            }
        }
        else
        {
            if(player.GetPosition()<enemy.GetPosition())
            {
                enemy.MoveRight(player) ;
            }
            else
            {
                enemy.MoveLeft(player) ;
            }
        }
    }
    else if(_typeEffect.compare("moveLeft")==0)
    {
        if(mobTurn)
        {
            enemy.MoveLeft(player) ;
        }
        else
        {
            player.MoveLeft(enemy) ;
        }
    }
    else if(_typeEffect.compare("moveRight")==0)
    {
        if(mobTurn)
        {
            enemy.MoveRight(player) ;
        }
        else
        {
            player.MoveRight(enemy) ;
        }
    }
    else if(_typeEffect.compare("enemyLessPressionPerTurn")==0)
    {
        player.AddPressurePerTurn(-_value) ;
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "effect" ;
        message1->_stringData.insert(pair<string,string>("type", "playerSteamEffect")) ;
        EngineEvent::SendToGraphic(message1) ;
    }
    else if(_typeEffect.compare("enemyLessArmor")==0)
    {
        if(mobTurn)
        {
            player.AddArmor(-_value) ;
            EngineEvent* message1 = new EngineEvent() ;
            message1->_type = "effect" ;
            message1->_stringData.insert(pair<string,string>("type", "playerLessArmor")) ;
            EngineEvent::SendToGraphic(message1) ;
        }
        else
        {
            enemy.AddArmor(-_value) ;
            EngineEvent* message1 = new EngineEvent() ;
            message1->_type = "effect" ;
            message1->_stringData.insert(pair<string,string>("type", "mobLessArmor")) ;
            EngineEvent::SendToGraphic(message1) ;
        }
    }
    else if(_typeEffect.compare("attackPerPressionPerTurn")==0)
    {
        enemy.TakeDamage(_value*player.GetPressurePerTurn()) ;
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "effect" ;
        message1->_stringData.insert(pair<string,string>("type", "playerAttack")) ;
        message1->_stringData.insert(pair<string,string>("part", player.GetActivePart())) ;
        EngineEvent::SendToGraphic(message1) ;
    }
    else if(_typeEffect.compare("attackPerPression")==0)
    {
        enemy.TakeDamage(_value*player.GetPressure()) ;
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "effect" ;
        message1->_stringData.insert(pair<string,string>("type", "playerAttack")) ;
        message1->_stringData.insert(pair<string,string>("part", player.GetActivePart())) ;
        EngineEvent::SendToGraphic(message1) ;
    }
    else if(_typeEffect.compare("moreIntegrity")==0)
    {
        if(mobTurn)
        {
            enemy.AddIntegrity(_value) ;
            EngineEvent* message1 = new EngineEvent() ;
            message1->_type = "effect" ;
            message1->_stringData.insert(pair<string,string>("type", "mobMoreIntegrity")) ;
            EngineEvent::SendToGraphic(message1) ;
        }
        else
        {
            player.AddIntegrity(_value) ;
            EngineEvent* message1 = new EngineEvent() ;
            message1->_type = "effect" ;
            message1->_stringData.insert(pair<string,string>("type", "playerMoreIntegrity")) ;
            EngineEvent::SendToGraphic(message1) ;
        }
    }
    else if(_typeEffect.compare("lessIntegrity")==0)
    {
        if(mobTurn)
        {
            enemy.TakeDamage(_value,false) ;
        }
        else
        {
            player.TakeDamage(_value,false) ;
        }
    }
    else if(_typeEffect.compare("enemyLessArmorTmp")==0)
    {
        if(mobTurn)
        {
            player.AddArmor(-_value) ;
            player.AddTmpEffect(_value, "moreArmor") ;
            EngineEvent* message1 = new EngineEvent() ;
            message1->_type = "effect" ;
            message1->_stringData.insert(pair<string,string>("type", "playerLessArmor")) ;
            EngineEvent::SendToGraphic(message1) ;
        }
        else
        {
            enemy.AddArmor(-_value) ;
            enemy.AddTmpEffect(_value, "moreArmor") ;
            EngineEvent* message1 = new EngineEvent() ;
            message1->_type = "effect" ;
            message1->_stringData.insert(pair<string,string>("type", "mobLessArmor")) ;
            EngineEvent::SendToGraphic(message1) ;
        }
    }
    else if(_typeEffect.compare("moveToEnemy")==0)
    {
        if(mobTurn)
        {
            enemy.MoveToEnemy(player, _value) ;
        }
        else
        {
            player.MoveToEnemy(enemy, _value) ;
        }
    }
    else if(_typeEffect.compare("propulseur")==0)
    {
        if(mobTurn)
        {
            if(player.GetPosition()!=(7-enemy.GetPosition()))
            {
                enemy.SetPosition(7-enemy.GetPosition()) ;
            }
            EngineEvent* message1 = new EngineEvent() ;
            message1->_type = "effect" ;
            message1->_stringData.insert(pair<string,string>("type", "mobPropulseur")) ;
            EngineEvent::SendToGraphic(message1) ;
        }
        else
        {
            if(enemy.GetPosition()!=(7-player.GetPosition()))
            {
                player.SetPosition(7-player.GetPosition()) ;
            }
            EngineEvent* message1 = new EngineEvent() ;
            message1->_type = "effect" ;
            message1->_stringData.insert(pair<string,string>("type", "playerPropulseur")) ;
            EngineEvent::SendToGraphic(message1) ;
        }
    }
    else if(_typeEffect.compare("moreArmorTmp")==0)
    {
        if(mobTurn)
        {
            enemy.AddArmor(_value) ;
            enemy.AddTmpEffect(_value, "lessArmor") ;
            EngineEvent* message1 = new EngineEvent() ;
            message1->_type = "effect" ;
            message1->_stringData.insert(pair<string,string>("type", "mobMoreArmor")) ;
            EngineEvent::SendToGraphic(message1) ;
        }
        else
        {
            player.AddArmor(_value) ;
            player.AddTmpEffect(_value, "lessArmor") ;
            EngineEvent* message1 = new EngineEvent() ;
            message1->_type = "effect" ;
            message1->_stringData.insert(pair<string,string>("type", "playerMoreArmor")) ;
            EngineEvent::SendToGraphic(message1) ;
        }
    }
    else if(_typeEffect.compare("lessPressionPerTurn")==0)
    {
        player.AddPressurePerTurn(-_value) ;
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "effect" ;
        message1->_stringData.insert(pair<string,string>("type", "playerSteamEffect")) ;
        EngineEvent::SendToGraphic(message1) ;
    }
    else if(_typeEffect.compare("morePressionPerTurn")==0)
    {
        player.AddPressurePerTurn(_value) ;
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "effect" ;
        message1->_stringData.insert(pair<string,string>("type", "playerSteamEffect")) ;
        EngineEvent::SendToGraphic(message1) ;
    }
    else if(_typeEffect.compare("moreArmor")==0)
    {
        if(mobTurn)
        {
            enemy.AddArmor(_value) ;
            EngineEvent* message1 = new EngineEvent() ;
            message1->_type = "mobMoreArmor" ;
            EngineEvent::SendToGraphic(message1) ;
        }
        else
        {
            player.AddArmor(_value) ;
            EngineEvent* message1 = new EngineEvent() ;
            message1->_type = "playerMoreArmor" ;
            EngineEvent::SendToGraphic(message1) ;
        }
    }
    else if(_typeEffect.compare("lessArmor")==0)
    {
        if(mobTurn)
        {
            enemy.AddArmor(-_value) ;
            EngineEvent* message1 = new EngineEvent() ;
            message1->_type = "mobLessArmor" ;
            EngineEvent::SendToGraphic(message1) ;
        }
        else
        {
            player.AddArmor(-_value) ;
            EngineEvent* message1 = new EngineEvent() ;
            message1->_type = "playerLessArmor" ;
            EngineEvent::SendToGraphic(message1) ;
        }
    }
    else if(_typeEffect.compare("lessPressionPerTurnTmp")==0)
    {
        player.AddPressurePerTurn(-_value) ;
        player.AddTmpEffect(_value, "morePressurePerTurn") ;
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "effect" ;
        message1->_stringData.insert(pair<string,string>("type", "playerSteamEffect")) ;
        EngineEvent::SendToGraphic(message1) ;
    }
    else if(_typeEffect.compare("morePressionPerTurn")==0)
    {
        player.AddTmpEffect(_value, "lessPressionPerTurn") ;
        player.AddPressurePerTurn(-_value) ;
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "effect" ;
        message1->_stringData.insert(pair<string,string>("type", "playerSteamEffect")) ;
        EngineEvent::SendToGraphic(message1) ;
    }
    else if(_typeEffect.compare("attackDelayed")==0)
    {
        if(mobTurn)
        {
            enemy.SetDelayedAction(true) ;
        }
        else
        {
            player.SetDelayedAction(true) ;
        }
    }
    else if(_typeEffect.compare("backStab")==0)
    {
        if(mobTurn)
        {
            if(((player.GetPosition()-enemy.GetPosition())==1 && player.GetDirection()==1 && enemy.GetDirection()==1)
               || ((enemy.GetPosition()-player.GetPosition())==1 && player.GetDirection()==0 && enemy.GetDirection()==0))
            {
                player.TakeDamage(_value) ;
                EngineEvent* message1 = new EngineEvent() ;
                message1->_type = "effect" ;
                message1->_stringData.insert(pair<string,string>("type", "mobAttack")) ;
                EngineEvent::SendToGraphic(message1) ;
            }
        }
        else
        {
            if(((enemy.GetPosition()-player.GetPosition())==1 && player.GetDirection()==1 && enemy.GetDirection()==1)
               || ((player.GetPosition()-enemy.GetPosition())==1 && player.GetDirection()==0 && enemy.GetDirection()==0))
            {
                enemy.TakeDamage(_value) ;
                EngineEvent* message1 = new EngineEvent() ;
                message1->_type = "effect" ;
                message1->_stringData.insert(pair<string,string>("type", "playerAttack")) ;
                message1->_stringData.insert(pair<string,string>("part", player.GetActivePart())) ;
                EngineEvent::SendToGraphic(message1) ;
            }
        }
    }
    else if(_typeEffect.compare("snare")==0)
    {
        if(mobTurn)
        {
            player.SetImmobilize(true) ;
            EngineEvent* message1 = new EngineEvent() ;
            message1->_type = "effect" ;
            message1->_stringData.insert(pair<string,string>("type", "playerImmobilize")) ;
            EngineEvent::SendToGraphic(message1) ;
        }
        else
        {
            enemy.SetImmobilize(true) ;
            EngineEvent* message1 = new EngineEvent() ;
            message1->_type = "effect" ;
            message1->_stringData.insert(pair<string,string>("type", "mobImmobilize")) ;
            EngineEvent::SendToGraphic(message1) ;
        }
    }
}

bool Effect::DoEffect(Player& player, Rush& rush)
{
    bool error = false ;
    if(_typeEffect.compare("lessStockOre")==0)
    {
        if(rush.GetStockOre()<_value)
        {
            error = true ;
        }
        rush.AddOre(-_value) ;
    }
    else if(_typeEffect.compare("moreIntegrity")==0)
    {
        player.AddIntegrity(_value) ;
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "effect" ;
        message1->_stringData.insert(pair<string,string>("type", "playerMoreIntegrity")) ;
        EngineEvent::SendToGraphic(message1) ;
    }
    else if(_typeEffect.compare("moreStockOre")==0)
    {
        rush.AddOre(_value) ;
    }
    else if(_typeEffect.compare("lessIntegrity")==0)
    {
        player.TakeDamage(_value,false) ;
    }
    else if(_typeEffect.compare("enteringInBuilding")==0)
    {
        player.SetEnteringInBuilding(true) ;
    }
    else if(_typeEffect.compare("moreStockVestige")==0)
    {
        rush.AddVestige(_value) ;
    }
    else if(_typeEffect.compare("lessArmor")==0)
    {
        player.AddArmor(-_value) ;
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "effect" ;
        message1->_stringData.insert(pair<string,string>("type", "playerLessArmor")) ;
        EngineEvent::SendToGraphic(message1) ;
    }
    else if(_typeEffect.compare("moreArmor")==0)
    {
        player.AddArmor(_value) ;
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "effect" ;
        message1->_stringData.insert(pair<string,string>("type", "playerMoreArmor")) ;
        EngineEvent::SendToGraphic(message1) ;
    }
    else if(_typeEffect.compare("lessPressionPerTurn")==0)
    {
        player.AddPressurePerTurn(-_value) ;
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "effect" ;
        message1->_stringData.insert(pair<string,string>("type", "playerSteamEffect")) ;
        EngineEvent::SendToGraphic(message1) ;
    }
    else if(_typeEffect.compare("morePressionPerTurn")==0)
    {
        player.AddPressurePerTurn(_value) ;
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "effect" ;
        message1->_stringData.insert(pair<string,string>("type", "playerSteamEffect")) ;
        EngineEvent::SendToGraphic(message1) ;
    }
    else if(_typeEffect.compare("lessSteam")==0)
    {
        player.AddSteam(-_value) ;
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "effect" ;
        message1->_stringData.insert(pair<string,string>("type", "playerSteamEffect")) ;
        EngineEvent::SendToGraphic(message1) ;
    }
    else if(_typeEffect.compare("moreSteam")==0)
    {
        player.AddSteam(_value) ;
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "effect" ;
        message1->_stringData.insert(pair<string,string>("type", "playerSteamEffect")) ;
        EngineEvent::SendToGraphic(message1) ;
    }
    return error ;
}

void Effect::DoEffectDelayed(Player& player, Mob& enemy, const bool mobTurn)
{
    if(_typeEffect.compare("attackDelayed")==0)
    {
        if(mobTurn)
        {
            player.TakeDamage(_value) ;
        }
        else
        {
            enemy.TakeDamage(_value) ;
        }
    }
}

void Effect::CheckEffect(Player& player, const bool forReloadPart)
{
    if(_typeEffect.compare("maxIntegrity")==0)
    {
        if(forReloadPart)
        {
            player.AddMaxIntegrity(-_value) ;
            player.AddIntegrity(-_value, true) ;
        }
        else
        {
            player.AddMaxIntegrity(_value) ;
            player.AddIntegrity(_value, true) ;
        }
    }
    else if(_typeEffect.compare("armor")==0)
    {
        if(forReloadPart)
        {
            player.AddArmor(-_value, true) ;
        }
        else
        {
            player.AddArmor(_value, true) ;
        }
    }
    else if(_typeEffect.compare("pressurePerTurn")==0)
    {
        if(forReloadPart)
        {
            player.AddPressurePerTurn(-_value, true) ;
        }
        else
        {
            player.AddPressurePerTurn(_value, true) ;
        }
    }
    else if(_typeEffect.compare("steam")==0)
    {
        if(forReloadPart)
        {
            player.AddSteam(-_value, true) ;
        }
        else
        {
            player.AddSteam(_value, true) ;
        }
    }
}

void Effect::CheckEffect(Mob& mob, const unsigned short int difficulty)
{
    if(_typeEffect.compare("maxIntegrity")==0)
    {
        mob.AddMaxIntegrity(_value) ;
        mob.AddIntegrity(_value, true) ;
    }
    else if(_typeEffect.compare("armor")==0)
    {
        mob.AddArmor(_value, true) ;
    }
    else if(_typeEffect.compare("action")==0)
    {
        mob.AddMaxAction(_value) ;
    }

}
