/**
 * @file     Rush.cpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Methods of class Rush.
 */

#include "Rush.hpp"
#include "Data.hpp"
#include "../EngineEvent.hpp"
#include <cstdlib>
#include <iostream>

using namespace std ;

Rush::Rush() : _difficulty(0),_maxDifficulty(0), _rerolls(0), _stockOre(0), _orePerEnemyMax(0), _orePerEnemyMin(0), _stockVestige(0), _indiceCurrentRoom(-1), _trueEnd(false), _rushEnded(false), _currentRoom(*this), _player()
{

    _stockOre = Data::ToInt(Data::SearchInString(Data::Read("Save","stockOre"),"value")) ;
    _rerolls = Data::ToInt(Data::SearchInString(Data::Read("Save","reroll"),"value0")) ;
    _maxDifficulty =  Data::ToInt(Data::SearchInString(Data::Read("Save","maxDifficulty"),"value0")) ;
    _orePerEnemyMax = Data::ToInt(Data::SearchInString(Data::Read("Save","orePerEnemy"),"value1")) ;
    _orePerEnemyMin = Data::ToInt(Data::SearchInString(Data::Read("Save","orePerEnemy"),"value0")) ;
}

Rush::~Rush()
{

}

void Rush::SetStockOre(const int value)
{
    _stockOre = value ;
    EngineEvent* message1 = new EngineEvent() ;
    message1->_type = "rushStockOre" ;
    message1->_stringData.insert(pair<string,string>("stockOre",Data::ToString(_stockOre))) ;
    EngineEvent::SendToGraphic(message1) ;
}

void Rush::SetDifficulty(const unsigned short int value)
{
    _difficulty = value ;
    if(_difficulty==10)
    {
        _trueEnd = true ;
    }
}

void Rush::SetTrueEnd(const bool value)
{
    _trueEnd = value ;
}

void Rush::IncrementsIndiceCurrentRoom()
{
    _indiceCurrentRoom += 1 ;
    if(_indiceCurrentRoom>=36)
    {
        if(Data::SearchInString(Data::Read("Save","maxDifficulty"),"value0").compare(Data::SearchInString(Data::Read("Save","maxDifficulty"),"maxLevel"))!=0)
        {
            Data::Upgrade("Save", "maxDifficulty") ;
            EngineEvent* message = new EngineEvent() ;
            message->_type = "maxDifficulty" ;
            EngineEvent::SendToGraphic(message) ;
        }
        EndRush() ;
    }
}

void Rush::LeaveRoom()
{
    _currentRoom.ClearRoom() ;

    int r,p ;
    string tmp, biome ;
    if(_indiceCurrentRoom<=12)
    {
        biome = "Desert" ;
    }
    else if (_indiceCurrentRoom<=23)
    {
        biome = "Jungle" ;
    }
    else
    {
        biome = "Mine" ;
    }
    _currentRoom.SetBiome(biome) ;

    if(_player.GetEnteringInBuilding())
    {
        _player.SetEnteringInBuilding(false) ;
        _currentRoom.NewDiscovery("Building") ;
    }
    else
    {
        IncrementsIndiceCurrentRoom() ;
        if(_indiceCurrentRoom==0 || _indiceCurrentRoom==1 || _indiceCurrentRoom==2 || _indiceCurrentRoom==13 || _indiceCurrentRoom==24 || _indiceCurrentRoom==35)
        {
            switch (_indiceCurrentRoom)
            {
                case 13 : p = 3 ; break ;
                case 24 : p = 4 ; break ;
                case 35 : p = 5 ; break ;
                default : p = _indiceCurrentRoom ; break;
            }

            tmp = string("Special-").append( Data::ToString(p)) ;
            _currentRoom.NewDiscovery(tmp) ;
        }
        else
        {
            r=(rand()%2) ;
            if(r==0)
            {
                _currentRoom .NewDiscovery("Event") ;
            }
            else
            {
                _currentRoom.NewEnemy() ;
            }
        }
    }
    if(_indiceCurrentRoom==0)
    {
        EngineEvent* message0 = new EngineEvent() ;
        message0->_type = "start" ;
        EngineEvent::SendToSound(message0) ;
    }
    _currentRoom.EnterInRoom() ;
}

void Rush::EndRush()
{
    EngineEvent* message = new EngineEvent() ;
    message->_type = "preEnd" ;
    message->_stringData.insert(pair<string,string>("stockOre",Data::ToString(_stockOre))) ;
    EngineEvent::SendToGraphic(message) ;
    _stockOre *= 0.75 ;
    EngineEvent* message0 = new EngineEvent() ;
    message0->_type = "end" ;
    message0->_stringData.insert(pair<string,string>("stockOre",Data::ToString(_stockOre))) ;
    message0->_stringData.insert(pair<string,string>("vestige",Data::ToString(_stockVestige))) ;
    message0->_stringData.insert(pair<string,string>("convertionRate",Data::SearchInString(Data::Read("Save", "endconvertionRate"), "value0"))) ;
    EngineEvent::SendToGraphic(message0) ;
    _rushEnded = true ;
    _stockOre -= 3*_stockOre/4 ;
    _stockOre += _stockVestige * Data::ToInt(Data::SearchInString(Data::Read("Save", "endConvertionRate"), "value0")) ;
    _stockVestige = 0 ;
    Data::Write("stockOre",_stockOre) ;
    EngineEvent* message1 = new EngineEvent() ;
    message1->_type = "endStockOre" ;
    message1->_stringData.insert(pair<string,string>("stockOre",Data::ToString(_stockOre))) ;
    EngineEvent::SendToGraphic(message1) ;
    Data::SaveData();
}

void Rush::ConvertOreInSteam()
{
    if(_stockOre>=5)
    {
        SetStockOre(_stockOre - 5);
        _player.AddSteam(_player.GetConvertionRate()) ;
    }
    else
    {
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "stockOreError" ;
        EngineEvent::SendToGraphic(message1) ;
    }
}

void Rush::AddOre(const int value)
{
    _stockOre += value * (1+((3*_difficulty)/10)) ;
    EngineEvent* message0 = new EngineEvent() ;
    message0->_type = "rushStockOre" ;
    message0->_stringData.insert(pair<string,string>("value",Data::ToString(_rerolls))) ;
    EngineEvent::SendToGraphic(message0) ;
}

void Rush::AddVestige(const short int value)
{
    _stockVestige += value ;
    EngineEvent* message0 = new EngineEvent() ;
    message0->_type = "rushStockVestige" ;
    message0->_stringData.insert(pair<string,string>("value",Data::ToString(_rerolls))) ;
    EngineEvent::SendToGraphic(message0) ;
}

void Rush::EndBattle()
{
    int ore = rand()%(_orePerEnemyMax-_orePerEnemyMin)+ _orePerEnemyMin ;
    AddOre(ore) ;
    _currentRoom.EndBattle() ;
}

void Rush::Reroll(string typePart)
{
    if(_rerolls>0)
    {
        _rerolls-- ;
        _player.Reroll(typePart) ;
        EngineEvent* message0 = new EngineEvent() ;
        message0->_type = "reroll" ;
        message0->_stringData.insert(pair<string,string>("value",Data::ToString(_rerolls))) ;
        EngineEvent::SendToGraphic(message0) ;
    }
    else
    {
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "rerollError" ;
        EngineEvent::SendToGraphic(message1) ;
    }

}

void Rush::DisplayPlayer(string typeMessage)
{
    _player.DisplayEntity(typeMessage) ;
}
