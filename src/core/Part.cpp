/**
 * @file     Part.cpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Methods of class Part.
 */

#include "Part.hpp"
#include "Player.hpp"
#include "Mob.hpp"
#include "Data.hpp"
#include "../EngineEvent.hpp"

using namespace std ;

Part::Part() : _type(""), _name(""), _description("")
{
    _actions = std::vector<Action>() ;
}

Part::~Part()
{
    _actions.clear() ;
}

void Part::LoadPart(const string typePart, Player& player)
{
    _type = typePart ;
    string tmp, info ;
    int r ;
    r = (rand()%4) ;
    tmp = typePart ;
    tmp = tmp.append(string("-").append(Data::ToString(r))) ;
    _type = tmp ;
    info = Data::Read("PlayerPart",tmp) ;
    _name = Data::SearchInString(info,"name") ;
    _description = Data::SearchInString(info,"description") ;
    _actions.clear() ;
    for(int i=0;info.find(string("pressureCost").append(Data::ToString(i)))!= string::npos;i++)
    {
        AddAction(Data::ToInt(Data::SearchInString(info,string("pressureCost").append(Data::ToString(i)))),
                   Data::ToInt(Data::SearchInString(info,string("minDistance").append(Data::ToString(i)))),
                   Data::ToInt(Data::SearchInString(info,string("maxDistance").append(Data::ToString(i)))),
                   Data::SearchInString(info,string("effects").append(Data::ToString(i)),true),
                   Data::SearchInString(info,string("direction").append(Data::ToString(i))),
                   Data::ToInt(Data::SearchInString(info,"level"))) ;
    }
    CheckPart(player) ;
}

void Part::LoadPart(const string typePart, Mob& mob, const string biome, const unsigned short int difficulty)
{
    string tmp, info ;
    int r ;
    _name = biome ;
    r = (rand()%3) ;
    tmp = typePart ;
    tmp = tmp.append(string("-").append(Data::ToString(r))) ;
    _type = tmp ;
    info = Data::Read(string("PartMob").append(biome), tmp) ;
    _description = Data::SearchInString(info,"description") ;
    _actions.clear() ;
    for(int i=0;info.find(string("pressureCost").append(Data::ToString(i)))!= string::npos;i++)
    {
        AddAction(Data::ToInt(Data::SearchInString(info,string("pressureCost").append(Data::ToString(i)))),
                  Data::ToInt(Data::SearchInString(info,string("minDistance").append(Data::ToString(i)))),
                  Data::ToInt(Data::SearchInString(info,string("maxDistance").append(Data::ToString(i)))),
                  Data::SearchInString(info,string("effects").append(Data::ToString(i)),true),
                  Data::SearchInString(info,string("direction").append(Data::ToString(i))),
                  difficulty) ;
    }
    CheckPart(mob, difficulty) ;
}

void Part::ReloadPart(Player& player)
{
    CheckPart(player, true) ;
    string tmp = _type.substr(0,_type.size()-2) ;
    LoadPart(tmp, player) ;
    DisplayPart("start") ;
}

void Part::CheckPart(Player& player, const bool forReloadPart)
{
    for(unsigned int i=0;i<_actions.size();i++)
   {
       if(_actions[i].GetDirection().compare("none")==0)
       {
           _actions[i].CheckAction(player, forReloadPart) ;
       }
   }
}

void Part::CheckPart(Mob& mob, const unsigned short int difficulty)
{
   for(unsigned int i=0;i<_actions.size();i++)
   {
        _actions[i].CheckAction(mob, difficulty) ;
   }
}

void Part::AddAction(const short int pressureCost, const short int minDistance, const short int maxDistance, const std::string infoEffects, const std::string direction, const unsigned short int difficulty)
{
    Action tmp(pressureCost, minDistance, maxDistance, infoEffects, direction, difficulty) ;
    _actions.push_back(tmp) ;
}

void Part::DoAction(const string direction, Player& player, Mob& enemy, bool mobTurn)
{
    for(unsigned int i=0; i<_actions.size() ; i++ )
    {
        if(_actions[i].GetDirection().compare(direction)==0)
        {
            const_cast<Action&>(_actions[i]).DoAction(player, enemy, mobTurn) ;
        }
    }
}

void Part::DisplayPart(string typeMessage) const
{
    if(typeMessage.compare("start")==0)
    {
        EngineEvent* message0 = new EngineEvent() ;
        message0->_type = "startPart" ;
        message0->_stringData.insert(pair<string,string>("description",_description)) ;
        message0->_stringData.insert(pair<string,string>("name",_name)) ;
        message0->_stringData.insert(pair<string,string>("type",_type)) ;
        EngineEvent::SendToGraphic(message0) ;
    }
    else
    {
        string tmp = _type ;
        if(_name.compare("Jungle")==0 || _name.compare("Desert")==0 || _name.compare("Mine")==0)
        {
            EngineEvent* message = new EngineEvent() ;
            message->_type = "mobPart" ;
            message->_stringData.insert(pair<string,string>("type",tmp.insert(tmp.size()-2,_name))) ;
            EngineEvent::SendToGraphic(message) ;
        }
        else
        {
            EngineEvent* message = new EngineEvent() ;
            message->_type = "playerPart" ;
            message->_stringData.insert(pair<string,string>("type",_type)) ;
            EngineEvent::SendToGraphic(message) ;
        }
    }
}

void Part::MoveToDoAction(Player& enemy, Mob& mob, string type) const
{
    for(unsigned short int i=0;i<_actions.size();i++)
    {
        if(_actions[i].GetDirection().compare(type)==0)
        {
            _actions[i].MoveToDoAction(enemy, mob) ;
        }
    }
}
