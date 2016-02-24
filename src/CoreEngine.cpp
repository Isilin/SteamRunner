/**
 * @file     CoreEngine.cpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Methods of class CoreEngine.
 */

#include "CoreEngine.hpp"
#include "EngineEvent.hpp"
#include "Game.hpp"
#include "./core/Data.hpp"
#include "./core/PersistantUpgradeTree.hpp"
#include "./core/Rush.hpp"
#include <iostream>
using namespace std ;

CoreEngine::CoreEngine(Game* parent) : Engine(parent), _persistantUpgradeTree(), _rush()
{
    _coreEngine = this ;
    _graphicEngine = NULL ;
    _soundEngine = NULL ;
}

CoreEngine::~CoreEngine()
{

}

void CoreEngine::ProcessEvent(const EngineEvent* event)
{
    if(event->_type.compare("PUUpgrade")==0)
    {
        if(event->_stringData.at("type").compare("maxPressure")==0 || event->_stringData.at("type").compare("reroll")==0 || event->_stringData.at("type").compare("orePerEnemy")==0
            || event->_stringData.at("type").compare("convertionRate")==0 || event->_stringData.at("type").compare("endRate")==0 || event->_stringData.at("type").compare("initialPressure")==0 )
        {
            _persistantUpgradeTree.Upgrade("Save",event->_stringData.at("type")) ;
        }
        else
        {
            _persistantUpgradeTree.Upgrade("PlayerPart",event->_stringData.at("type")) ;
        }

    }
    else if(event->_type.compare("endPU")==0)
    {
        Data::SaveData() ;
        Data::CloseData() ;
        Data::InitData() ;
        Data::Write("stockOre",_persistantUpgradeTree.GetStockOre()) ;
        _rush.DisplayPlayer("start") ;
        if(_persistantUpgradeTree.WillTrueEnded())
        {
            _rush.SetTrueEnd(true) ;
        }

        EngineEvent* message0 = new EngineEvent() ;
        message0->_type = "reroll" ;
        message0->_stringData.insert(pair<string,string>("value",Data::ToString(_rush.GetReroll()))) ;
        EngineEvent::SendToGraphic(message0) ;

    }
    else if(event->_type.compare("PUDescription")==0)
    {
        if(event->_stringData.at("type").compare("maxPressure")==0 || event->_stringData.at("type").compare("reroll")==0 || event->_stringData.at("type").compare("orePerEnemy")==0
            || event->_stringData.at("type").compare("convertionRate")==0 || event->_stringData.at("type").compare("endRate")==0 || event->_stringData.at("type").compare("initialPressure")==0 )
        {
            EngineEvent* message = new EngineEvent() ;
            message->_type = "PUDescription" ;
            message->_stringData.insert(pair<string,string>("description",Data::SearchInString(Data::Read("Save",event->_stringData.at("type")),"description"))) ;
            message->_stringData.insert(pair<string,string>("name",Data::SearchInString(Data::Read("Save",event->_stringData.at("type")),"name"))) ;
            message->_stringData.insert(pair<string,string>("type",event->_stringData.at("type"))) ;
            EngineEvent::SendToGraphic(message) ;
        }
        else
        {
            EngineEvent* message = new EngineEvent() ;
            message->_type = "PUDescription" ;
            message->_stringData.insert(pair<string,string>("description",Data::SearchInString(Data::Read("PlayerPart",event->_stringData.at("type")),"description"))) ;
            message->_stringData.insert(pair<string,string>("name",Data::SearchInString(Data::Read("PlayerPart",event->_stringData.at("type")),"name"))) ;
             message->_stringData.insert(pair<string,string>("type",event->_stringData.at("type"))) ;
            EngineEvent::SendToGraphic(message) ;
        }

    }
    else if(event->_type.compare("PUCost")==0)
    {
        _persistantUpgradeTree.SendCostToGraphicEngine(event->_stringData.at("type")) ;
    }
    else if(event->_type.compare("end")==0)
    {
        Data::CloseData() ;
        Data::InitData() ;
        EngineEvent* message0 = new EngineEvent() ;
        message0->_type = "menu" ;
        EngineEvent::SendToSound(message0) ;
    }
    else if(event->_type.compare("reroll")==0)
    {
        _rush.Reroll(event->_stringData.at("type")) ;
    }
    else if(event->_type.compare("endStart")==0)
    {
        _rush.LeaveRoom() ;
        EngineEvent* message0 = new EngineEvent() ;
        message0->_type = "rush" ;
        EngineEvent::SendToSound(message0) ;
    }
    else if(event->_type.compare("credit")==0)
    {
        EngineEvent* message = new EngineEvent() ;
        message->_type = "credit" ;
        message->_stringData.insert(pair<string,string>("credit",Data::Read("Credit"))) ;
        EngineEvent::SendToGraphic(message) ;
    }
    else if(event->_type.compare("tutoriel")==0)
    {
        EngineEvent* message = new EngineEvent() ;
        message->_type = "tutoriel" ;
        message->_stringData.insert(pair<string,string>(string("tutoriel"),Data::Read("Tutoriel"))) ;
        EngineEvent::SendToGraphic(message) ;
    }
    else if(event->_type.compare("endRush")==0)
    {
        _rush.EndRush() ;
    }
    else if(event->_type.compare("endBattle")==0)
    {
        _rush.EndBattle() ;
    }
    else if(event->_type.compare("leaveRoom")==0)
    {
        _rush.LeaveRoom() ;
    }
    else if(event->_type.compare("endTurn")==0)
    {
        for(unsigned short int i=0;i<event->_stringData.size();i++)
        {
            if(_rush.GetCurrentRoom().GetEnemy()!=NULL)
            {
                _rush.GetPlayer().DoAction(event->_stringData.at(string("type-").append(Data::ToString(i))), event->_stringData.at(string("direction-").append(Data::ToString(i))), *_rush.GetCurrentRoom().GetEnemy()) ;
            }
        }
        if(_rush.GetCurrentRoom().GetEnemy()!=NULL)
        {
            _rush.GetPlayer().ProcHead(Data::ToString(event->_stringData.size()).append("actions"),*_rush.GetCurrentRoom().GetEnemy()) ;
        }
    }
    else if(event->_type.compare("choseRoomEffect")==0)
    {
        _rush.GetCurrentRoom().DoEffects() ;
    }
    else if(event->_type.compare("convertOreInSteam")==0)
    {
        _rush.ConvertOreInSteam() ;
    }
    else if(event->_type.compare("resetData")==0)
    {
        Data::Reset() ;
    }
    else if(event->_type.compare("play")==0)
    {
        _persistantUpgradeTree.Init() ;
    }
    else if(event->_type.compare("convertionRate")==0)
    {
        EngineEvent* message = new EngineEvent() ;
        message->_type = "convertionRate" ;
        message->_stringData.insert(pair<string,string>(string("value"),Data::ToString(_rush.GetPlayer().GetConvertionRate()))) ;
        EngineEvent::SendToGraphic(message) ;
    }
    else if(event->_type.compare("difficulty")==0)
    {
       _rush.SetDifficulty(event->_intData.at("value")) ;
    }
    else
    {
        cerr<<"event non traité de type : "<<event->_type ;
    }
}
