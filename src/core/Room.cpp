/**
 * @file     Room.cpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Methods of class Room.
 */

#include "Room.hpp"
#include "Rush.hpp"
#include "Data.hpp"
#include "../EngineEvent.hpp"
#include <cstdlib>

using namespace std ;

Room::Room(Rush& rush) : _biome("Desert"), _description(""), _typeBackground("random"), _rush(rush), _enemy(NULL), _chosen(false)
{
    _effects = std::vector<Effect>() ;
}

Room::~Room()
{
    _enemy = NULL ;
    _effects.clear() ;
}

void Room::NewEnemy()
{
    if(_enemy!=NULL)
    {
        delete(_enemy) ;
        _enemy = NULL ;
    }
    int r;
    string keys="", info ;
    _enemy = new Mob(_biome, _rush.GetDifficulty()) ;
    r = rand()%8 ;
    if(r!=7 && r!=6)
    {
        keys.append( string("Battle-").append(Data::ToString(r)) ) ;
        info=Data::Read("Room",keys) ;
        _description.append(string("\n").append(Data::SearchInString(info,"description")))  ;
    }
}

void Room::ClearRoom()
{
    delete(_enemy) ;
    _enemy = NULL ;
    _effects.clear() ;
    _chosen = false ;
    _description = "" ;
    _typeBackground = "random" ;
}

void Room::NewDiscovery(const string type)
{
    _effects.clear() ;
    string keys="", info, tmp="";
    int r,p;
    if(type.compare(string("Event"))==0)
    {
        r =(rand()%11) ;
        keys = string("Event-").append(Data::ToString(r)) ;
    }
    else if(type.compare(string("Building"))==0)
    {
        r =(rand()%6) ;
        if(r==5)
        {
            r = 4 ;
        }
        keys = string("Building-").append(Data::ToString(r)) ;
    }
    else if(type.substr(0,7).compare(string("Special"))==0)
    {
        p = Data::ToInt(type.substr(8,1)) ;
        if(p==0 || p==2)
        {
            r=rand()%3;
        }
        else if(p==5 && _rush.GetTrueEnd())
        {
           r=1;
        }
        else
        {
            r=0;
        }
        keys = string("Special-").append(Data::ToString(p).append(Data::ToString(r))) ;
    }

    if(!keys.empty())
    {
        info = Data::Read("Room",keys) ;
        _description.append(string("\n").append(Data::SearchInString(info,"description"))) ;
        if(Data::SearchInString(info,"chosen").compare(string("true"))==0)
        {
            _chosen = true ;
        }
        else
        {
            _chosen = false ;
        }
        for(int i=0;info.find(string("value").append(Data::ToString(i)))!=string::npos;i++)
        {
            AddEffect(Data::ToInt(Data::SearchInString(info,string("value").append(Data::ToString(i)))),
                      Data::ToInt(Data::SearchInString(info, string("perLevel").append(Data::ToString(i)))),
                       Data::SearchInString(info,string("typeEffect").append(Data::ToString(i))),
                      _rush.GetDifficulty()) ;
        }
        tmp = Data::SearchInString(info,"typeBackground") ;
        if(!tmp.empty())
        {
            _typeBackground = tmp ;
        }
    }
}

void Room::AddEffect(const int value, const int perLevel, const string type, const unsigned short int difficulty)
{
    Effect tmp(value, perLevel, type, difficulty);
    _effects.push_back(tmp) ;
}

void Room::DoEffects()
{
    if(!_effects.empty())
    {
        bool error = false ;
        for(unsigned int i=0; i<_effects.size();i++)
        {
            if(!error)
            {
                error = _effects[i].DoEffect(_rush.GetPlayer(),_rush) ;
            }

        }
    }
}

void Room::StartBattle()
{
    EngineEvent* message = new EngineEvent() ;
    message->_type = "positionBattle" ;
    int r ;
    r = 7 - rand()%4 ;
    _enemy->SetPosition(r) ;
    message->_intData.insert(pair<string,int>(string("mob"),r)) ;
    if(r==4)
    {
        r = rand()%3 ;
    }
    else
    {
        r = rand()%4 ;
    }
    _rush.GetPlayer().SetPosition(r) ;
    _rush.GetPlayer().StartBattle() ;
    _enemy->DisplayEntity("rush") ;
    message->_intData.insert(pair<string,int>(string("player"),r)) ;
    EngineEvent::SendToGraphic(message) ;
}

void Room::EndTurn()
{
    _enemy->DoTurn(_rush.GetPlayer()) ;
    _rush.GetPlayer().StartTurn(*_enemy) ;
}

void Room::EndBattle()
{
    _rush.GetPlayer().EndBattle() ;
}

void Room::EnterInRoom()
{
    string tmp = "";
    EngineEvent* message = new EngineEvent() ;
    message->_type = "room" ;
    message->_stringData.insert(pair<string,string>(string("biome"),_biome)) ;
    message->_stringData.insert(pair<string,string>(string("background"),_typeBackground)) ;
    message->_stringData.insert(pair<string,string>(string("stockOre"),Data::ToString(_rush.GetStockOre()))) ;
    message->_stringData.insert(pair<string,string>(string("stockVestige"),Data::ToString(_rush.GetStockVestige()))) ;
    message->_stringData.insert(pair<string,string>(string("integrity"),Data::ToString(_rush.GetPlayer().GetIntegrity()))) ;
    message->_stringData.insert(pair<string,string>(string("maxIntegrity"),Data::ToString(_rush.GetPlayer().GetMaxIntegrity()))) ;
    message->_stringData.insert(pair<string,string>(string("pressure"),Data::ToString(_rush.GetPlayer().GetPressure()))) ;
    message->_stringData.insert(pair<string,string>(string("pressurePerTurn"),Data::ToString(_rush.GetPlayer().GetPressurePerTurn()))) ;
    message->_stringData.insert(pair<string,string>(string("maxPressure"),Data::ToString(_rush.GetPlayer().GetMaxPressure()))) ;
    message->_stringData.insert(pair<string,string>(string("armor"),Data::ToString(_rush.GetPlayer().GetArmor()))) ;
    message->_stringData.insert(pair<string,string>(string("steam"),Data::ToString(_rush.GetPlayer().GetSteam()))) ;
    message->_stringData.insert(pair<string,string>(string("description"),_description)) ;
    if(_chosen)
    {
        tmp = "true" ;
    }
    else
    {
        tmp = "false" ;
    }
    message->_stringData.insert(pair<string,string>(string("chosen"),tmp)) ;
    EngineEvent::SendToGraphic(message) ;
    _rush.GetPlayer().DisplayEntity("rush") ;
    if(!_chosen)
    {
        DoEffects() ;
    }
    if(_enemy!=NULL)
    {
        StartBattle() ;
    }
}
