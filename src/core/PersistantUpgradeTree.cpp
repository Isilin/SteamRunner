/**
 * @file     PersistantUpgradeTree.cpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Methods of class PersistantUpgradeTree.
 */

#include "PersistantUpgradeTree.hpp"
#include "Data.hpp"
#include "../EngineEvent.hpp"

using namespace std ;

PersistantUpgradeTree::PersistantUpgradeTree() : _stockOre(0)
{

}

void PersistantUpgradeTree::Init()
{
    string info ;
    _stockOre = Data::ToInt(Data::SearchInString(Data::Read("Save","stockOre"), "value")) ;
    EngineEvent* message = new EngineEvent() ;
    message->_type = "PUStockOre" ;
    message->_stringData.insert(pair<string,string>("stockOre",Data::ToString(_stockOre))) ;
    EngineEvent::SendToGraphic(message) ;
    message = NULL ;

        _persistantUpgrades.push_back("head-0") ;
        message = new EngineEvent() ;
        message->_type = "PUHead-0" ;
        message->_stringData.insert(pair<string,string>("level",Data::SearchInString(Data::Read("PlayerPart","head-0"),"level"))) ;
        message->_stringData.insert(pair<string,string>("maxLevel",Data::SearchInString(Data::Read("PlayerPart","info"),"maxLevel"))) ;
        EngineEvent::SendToGraphic(message) ;
        message = NULL ;

        _persistantUpgrades.push_back("head-1") ;
        message = new EngineEvent() ;
        message->_type = "PUHead-1" ;
        message->_stringData.insert(pair<string,string>("level",Data::SearchInString(Data::Read("PlayerPart","head-1"),"level"))) ;
        message->_stringData.insert(pair<string,string>("maxLevel",Data::SearchInString(Data::Read("PlayerPart","info"),"maxLevel"))) ;
        EngineEvent::SendToGraphic(message) ;
        message = NULL ;

        _persistantUpgrades.push_back("head-2") ;
        message = new EngineEvent() ;
        message->_type = "PUHead-2" ;
        message->_stringData.insert(pair<string,string>("level",Data::SearchInString(Data::Read("PlayerPart","head-2"),"level"))) ;
        message->_stringData.insert(pair<string,string>("maxLevel",Data::SearchInString(Data::Read("PlayerPart","info"),"maxLevel"))) ;
        EngineEvent::SendToGraphic(message) ;
        message = NULL ;

        _persistantUpgrades.push_back("head-3") ;
        message = new EngineEvent() ;
        message->_type = "PUHead-3" ;
        message->_stringData.insert(pair<string,string>("level",Data::SearchInString(Data::Read("PlayerPart","head-3"),"level"))) ;
        message->_stringData.insert(pair<string,string>("maxLevel",Data::SearchInString(Data::Read("PlayerPart","info"),"maxLevel"))) ;
        EngineEvent::SendToGraphic(message) ;
        message = NULL ;

        _persistantUpgrades.push_back("chest-0") ;
        message = new EngineEvent() ;
        message->_type = "PUChest-0" ;
        message->_stringData.insert(pair<string,string>("level",Data::SearchInString(Data::Read("PlayerPart","chest-0"),"level"))) ;
        message->_stringData.insert(pair<string,string>("maxLevel",Data::SearchInString(Data::Read("PlayerPart","info"),"maxLevel"))) ;
        EngineEvent::SendToGraphic(message) ;
        message = NULL ;

        _persistantUpgrades.push_back("chest-1") ;
        message = new EngineEvent() ;
        message->_type = "PUChest-1" ;
        message->_stringData.insert(pair<string,string>("level",Data::SearchInString(Data::Read("PlayerPart","chest-1"),"level"))) ;
        message->_stringData.insert(pair<string,string>("maxLevel",Data::SearchInString(Data::Read("PlayerPart","info"),"maxLevel"))) ;
        EngineEvent::SendToGraphic(message) ;
        message = NULL ;

        _persistantUpgrades.push_back("chest-2") ;
        message = new EngineEvent() ;
        message->_type = "PUChest-2" ;
        message->_stringData.insert(pair<string,string>("level",Data::SearchInString(Data::Read("PlayerPart","chest-2"),"level"))) ;
        message->_stringData.insert(pair<string,string>("maxLevel",Data::SearchInString(Data::Read("PlayerPart","info"),"maxLevel"))) ;
        EngineEvent::SendToGraphic(message) ;
        message = NULL ;

        _persistantUpgrades.push_back("chest-3") ;
        message = new EngineEvent() ;
        message->_type = "PUChest-3" ;
        message->_stringData.insert(pair<string,string>("level",Data::SearchInString(Data::Read("PlayerPart","chest-3"),"level"))) ;
        message->_stringData.insert(pair<string,string>("maxLevel",Data::SearchInString(Data::Read("PlayerPart","info"),"maxLevel"))) ;
        EngineEvent::SendToGraphic(message) ;
        message = NULL ;

        _persistantUpgrades.push_back("legs-0") ;
        message = new EngineEvent() ;
        message->_type = "PULegs-0" ;
        message->_stringData.insert(pair<string,string>("level",Data::SearchInString(Data::Read("PlayerPart","legs-0"),"level"))) ;
        message->_stringData.insert(pair<string,string>("maxLevel",Data::SearchInString(Data::Read("PlayerPart","info"),"maxLevel"))) ;
        EngineEvent::SendToGraphic(message) ;
        message = NULL ;

        _persistantUpgrades.push_back("legs-1") ;
        message = new EngineEvent() ;
        message->_type = "PULegs-1" ;
        message->_stringData.insert(pair<string,string>("level",Data::SearchInString(Data::Read("PlayerPart","legs-1"),"level"))) ;
        message->_stringData.insert(pair<string,string>("maxLevel",Data::SearchInString(Data::Read("PlayerPart","info"),"maxLevel"))) ;
        EngineEvent::SendToGraphic(message) ;
        message = NULL ;

        _persistantUpgrades.push_back("legs-2") ;
        message = new EngineEvent() ;
        message->_type = "PULegs-2" ;
        message->_stringData.insert(pair<string,string>("level",Data::SearchInString(Data::Read("PlayerPart","legs-2"),"level"))) ;
        message->_stringData.insert(pair<string,string>("maxLevel",Data::SearchInString(Data::Read("PlayerPart","info"),"maxLevel"))) ;
        EngineEvent::SendToGraphic(message) ;
        message = NULL ;

        _persistantUpgrades.push_back("legs-3") ;
        message = new EngineEvent() ;
        message->_type = "PULegs-3" ;
        message->_stringData.insert(pair<string,string>("level",Data::SearchInString(Data::Read("PlayerPart","legs-3"),"level"))) ;
        message->_stringData.insert(pair<string,string>("maxLevel",Data::SearchInString(Data::Read("PlayerPart","info"),"maxLevel"))) ;
        EngineEvent::SendToGraphic(message) ;
        message = NULL ;

        _persistantUpgrades.push_back("maxPressure") ;
        message = new EngineEvent() ;
        message->_type = "PUMaxPressure" ;
        message->_stringData.insert(pair<string,string>("level",Data::SearchInString(Data::Read("Save","maxPressure"),"level"))) ;
        message->_stringData.insert(pair<string,string>("maxLevel",Data::SearchInString(Data::Read("Save","maxPressure"),"maxLevel"))) ;
        EngineEvent::SendToGraphic(message) ;
        message = NULL ;

        _persistantUpgrades.push_back("reroll") ;
        message = new EngineEvent() ;
        message->_type = "PUReroll" ;
        message->_stringData.insert(pair<string,string>("level",Data::SearchInString(Data::Read("Save","reroll"),"level"))) ;
        message->_stringData.insert(pair<string,string>("maxLevel",Data::SearchInString(Data::Read("Save","reroll"),"maxLevel"))) ;
        EngineEvent::SendToGraphic(message) ;
        message = NULL ;

        _persistantUpgrades.push_back("convertionRate") ;
        message = new EngineEvent() ;
        message->_type = "PUconvertionRate" ;
        message->_stringData.insert(pair<string,string>("level",Data::SearchInString(Data::Read("Save","convertionRate"),"level"))) ;
        message->_stringData.insert(pair<string,string>("maxLevel",Data::SearchInString(Data::Read("Save","convertionRate"),"maxLevel"))) ;
        EngineEvent::SendToGraphic(message) ;
        message = NULL ;

        _persistantUpgrades.push_back("arm-0") ;
        message = new EngineEvent() ;
        message->_type = "PUArm-0" ;
        message->_stringData.insert(pair<string,string>("level",Data::SearchInString(Data::Read("PlayerPart","arm-0"),"level"))) ;
        message->_stringData.insert(pair<string,string>("maxLevel",Data::SearchInString(Data::Read("PlayerPart","info"),"maxLevel"))) ;
        EngineEvent::SendToGraphic(message) ;
        message = NULL ;

        _persistantUpgrades.push_back("arm-1") ;
        message = new EngineEvent() ;
        message->_type = "PUArm-1" ;
        message->_stringData.insert(pair<string,string>("level",Data::SearchInString(Data::Read("PlayerPart","arm-1"),"level"))) ;
        message->_stringData.insert(pair<string,string>("maxLevel",Data::SearchInString(Data::Read("PlayerPart","info"),"maxLevel"))) ;
        EngineEvent::SendToGraphic(message) ;
        message = NULL ;

        _persistantUpgrades.push_back("arm-2") ;
        message = new EngineEvent() ;
        message->_type = "PUArm-2" ;
        message->_stringData.insert(pair<string,string>("level",Data::SearchInString(Data::Read("PlayerPart","arm-2"),"level"))) ;
        message->_stringData.insert(pair<string,string>("maxLevel",Data::SearchInString(Data::Read("PlayerPart","info"),"maxLevel"))) ;
        EngineEvent::SendToGraphic(message) ;
        message = NULL ;

        _persistantUpgrades.push_back("arm-3") ;
        message = new EngineEvent() ;
        message->_type = "PUArm-3" ;
        message->_stringData.insert(pair<string,string>("level",Data::SearchInString(Data::Read("PlayerPart","arm-3"),"level"))) ;
        message->_stringData.insert(pair<string,string>("maxLevel",Data::SearchInString(Data::Read("PlayerPart","info"),"maxLevel"))) ;
        EngineEvent::SendToGraphic(message) ;
        message = NULL ;

        _persistantUpgrades.push_back("arm-4") ;
        message = new EngineEvent() ;
        message->_type = "PUArm-4" ;
        message->_stringData.insert(pair<string,string>("level",Data::SearchInString(Data::Read("PlayerPart","arm-4"),"level"))) ;
        message->_stringData.insert(pair<string,string>("maxLevel",Data::SearchInString(Data::Read("PlayerPart","info"),"maxLevel"))) ;
        EngineEvent::SendToGraphic(message) ;
        message = NULL ;

        _persistantUpgrades.push_back("arm-5") ;
        message = new EngineEvent() ;
        message->_type = "PUArm-5" ;
        message->_stringData.insert(pair<string,string>("level",Data::SearchInString(Data::Read("PlayerPart","arm-5"),"level"))) ;
        message->_stringData.insert(pair<string,string>("maxLevel",Data::SearchInString(Data::Read("PlayerPart","info"),"maxLevel"))) ;
        EngineEvent::SendToGraphic(message) ;
        message = NULL ;

        _persistantUpgrades.push_back("endRate") ;
        message = new EngineEvent() ;
        message->_type = "PUEndRate" ;
        message->_stringData.insert(pair<string,string>("level",Data::SearchInString(Data::Read("Save","endRate"),"level"))) ;
        message->_stringData.insert(pair<string,string>("maxLevel",Data::SearchInString(Data::Read("Save","endRate"),"maxLevel"))) ;
        EngineEvent::SendToGraphic(message) ;
        message = NULL ;

        _persistantUpgrades.push_back("initialPressure") ;
        message = new EngineEvent() ;
        message->_type = "PUInitialPressure" ;
        message->_stringData.insert(pair<string,string>("level",Data::SearchInString(Data::Read("Save","initialPressure"),"level"))) ;
        message->_stringData.insert(pair<string,string>("maxLevel",Data::SearchInString(Data::Read("Save","initialPressure"),"maxLevel"))) ;
        EngineEvent::SendToGraphic(message) ;
        message = NULL ;

        _persistantUpgrades.push_back("orePerEnemy") ;
        message = new EngineEvent() ;
        message->_type = "PUOrePerEnemy" ;
        message->_stringData.insert(pair<string,string>("level",Data::SearchInString(Data::Read("Save","orePerEnemy"),"level"))) ;
        message->_stringData.insert(pair<string,string>("maxLevel",Data::SearchInString(Data::Read("Save","orePerEnemy"),"maxLevel"))) ;
        EngineEvent::SendToGraphic(message) ;
        message = NULL ;
}

PersistantUpgradeTree::~PersistantUpgradeTree()
{
    _persistantUpgrades.clear() ;
}

const bool PersistantUpgradeTree::SubStockOre(const int value)
{
    if(_stockOre>=value)
    {
        _stockOre -= value ;
        EngineEvent* message0 = new EngineEvent() ;
        message0->_type = "PUStockOre" ;
        message0->_stringData.insert(pair<string,string>("stockOre",Data::ToString(_stockOre))) ;
        EngineEvent::SendToGraphic(message0) ;
        return true ;
    }
    else
    {
        EngineEvent* message1 = new EngineEvent() ;
        message1->_type = "stockOreError" ;
        EngineEvent::SendToGraphic(message1) ;
        return false ;
    }
}

const bool PersistantUpgradeTree::WillTrueEnded()
{
    string info = Data::Read("Save","countCurrentUpgrade") ;
    return Data::ToInt(Data::SearchInString(info,"value0"))>=Data::ToInt(Data::SearchInString(info,"maxLevel")) ;
}

void PersistantUpgradeTree::Upgrade(const string typePersistantUpgrade, const string keys)
{
    int tmp ;
    if(typePersistantUpgrade.compare("PlayerPart")==0)
    {
        tmp = Data::ToInt(Data::SearchInString(Data::Read("PlayerPart","info"),"cost"))+
            ((Data::ToInt(Data::SearchInString(Data::Read("PlayerPart",keys),"level"))-1)*
             Data::ToInt(Data::SearchInString(Data::Read("PlayerPart","info"),"costPerLevel"))) ;
    }
    else
    {
        tmp = Data::ToInt(Data::SearchInString(Data::Read("Save",keys),"cost"))+
            ((Data::ToInt(Data::SearchInString(Data::Read("Save",keys),"level"))-1)*
             Data::ToInt(Data::SearchInString(Data::Read("Save",keys),"costPerLevel"))) ;
    }
    if(keys.compare("countCurrentUpgrade")==0 || keys.compare("maxDifficulty")==0 || SubStockOre(tmp)==true)
    {
        if(keys.compare("countCurrentUpgrade")!=0)
        {
            Data::Upgrade(typePersistantUpgrade,keys);
            for(unsigned short int i=0;i<_persistantUpgrades.size();i++)
            {
                if(_persistantUpgrades[0].compare(keys)==0)
                {
                    EngineEvent* message0 = new EngineEvent() ;
                    message0->_type = string("PU").append(keys) ;
                    message0->_stringData.insert(pair<string,string>("level",Data::SearchInString(Data::Read(typePersistantUpgrade,keys),"level"))) ;
                    message0->_stringData.insert(pair<string,string>("maxLevel",Data::SearchInString(Data::Read(typePersistantUpgrade,keys),"maxLevel"))) ;
                    EngineEvent::SendToGraphic(message0) ;
                }
            }
        }
        Data::Upgrade("Save", "countCurrentUpgrade") ;
    }
}

void PersistantUpgradeTree::SendCostToGraphicEngine(string typePersistantUpgrade)
{
    if(typePersistantUpgrade.compare("maxPressure")==0 || typePersistantUpgrade.compare("reroll")==0 || typePersistantUpgrade.compare("orePerEnemy")==0
                || typePersistantUpgrade.compare("convertionRate")==0 || typePersistantUpgrade.compare("endRate")==0 || typePersistantUpgrade.compare("initialPressure")==0 )
    {
        if(Data::SearchInString(Data::Read("Save",typePersistantUpgrade),"level").compare(Data::SearchInString(Data::Read("Save",typePersistantUpgrade),"maxLevel"))==0)
        {
            EngineEvent* message = new EngineEvent() ;
            message->_type = "PUCost" ;
            message->_stringData.insert(pair<string,string>("cost","max")) ;
            EngineEvent::SendToGraphic(message) ;

        }
        else
        {
            EngineEvent* message = new EngineEvent() ;
            message->_type = "PUCost" ;
            message->_stringData.insert(pair<string,string>("cost", Data::ToString(
                                                            Data::ToInt(Data::SearchInString(Data::Read("Save",typePersistantUpgrade),"cost"))+
                                                            ((Data::ToInt(Data::SearchInString(Data::Read("Save",typePersistantUpgrade),"level"))-1)*
                                                             Data::ToInt(Data::SearchInString(Data::Read("Save",typePersistantUpgrade),"costPerLevel")))) )) ;
            EngineEvent::SendToGraphic(message) ;
        }
    }
    else
    {
        if(Data::SearchInString(Data::Read("PlayerPart",typePersistantUpgrade),"level").compare(Data::SearchInString(Data::Read("PlayerPart","info"),"maxLevel"))==0)
        {
            EngineEvent* message = new EngineEvent() ;
            message->_type = "PUCost" ;
            message->_stringData.insert(pair<string,string>("cost","max")) ;
            EngineEvent::SendToGraphic(message) ;

        }
        else
        {
            EngineEvent* message = new EngineEvent() ;
            message->_type = "PUCost" ;
            message->_stringData.insert(pair<string,string>("cost", Data::ToString(
                                                            Data::ToInt(Data::SearchInString(Data::Read("PlayerPart","info"),"cost"))+
                                                            ((Data::ToInt(Data::SearchInString(Data::Read("PlayerPart",typePersistantUpgrade),"level"))-1)*
                                                             Data::ToInt(Data::SearchInString(Data::Read("PlayerPart","info"),"costPerLevel")))) )) ;
            EngineEvent::SendToGraphic(message) ;
        }
    }
}
