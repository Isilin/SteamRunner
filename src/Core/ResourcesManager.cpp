#include "ResourcesManager.hpp"
#include <iostream>
#include <string>
#include "XMLUtilities.hpp"

ResourcesManager::ResourcesManager() : _listTypesAttribute(), _listTypesEffect(), _listTypesPart(), _listBiomes(),
                                        _listEntities(), _listAttributes(), _listParts(), _listActions(), _listEffects(),
                                        _listConditions(){
}

ResourcesManager::~ResourcesManager(){
    _listTypesAttribute.clear() ;
    _listTypesEffect.clear() ;
    _listTypesPart.clear() ;
    _listBiomes.clear() ;
    _listEntities.clear() ;
    _listAttributes.clear() ;
    _listParts.clear() ;
    _listActions.clear() ;
    _listEffects.clear() ;
    _listConditions.clear() ;
}

void ResourcesManager::LoadResources(){
    std::cout << "Debut du chargement des fichiers ..." << std::endl << std::endl ;
    tinyxml2::XMLDocument doc ;

    if(doc.LoadFile("data/TypeAttribute.xml")){
        printf("%s\n", doc.ErrorName()) ;
    } else{
        LoadTypeAttribute(doc) ;
    }

    if(doc.LoadFile("data/TypeEffect.xml")){
        printf("%s\n", doc.ErrorName()) ;
    } else{
        LoadTypeEffect(doc) ;
    }

    if(doc.LoadFile("data/TypePart.xml")){
        printf("%s\n", doc.ErrorName()) ;
    } else{
        LoadTypePart(doc) ;
    }

    if(doc.LoadFile("data/Biome.xml")){
        printf("%s\n", doc.ErrorName()) ;
    } else{
        LoadBiome(doc) ;
    }

    if(doc.LoadFile("data/Entity.xml")){
        printf("%s\n", doc.ErrorName()) ;
    } else{
        LoadEntity(doc) ;
    }

    if(doc.LoadFile("data/Attribute.xml")){
        printf("%s\n", doc.ErrorName()) ;
    } else{
        LoadAttribute(doc) ;
    }

    if(doc.LoadFile("data/Action.xml")){
        printf("%s\n", doc.ErrorName()) ;
    } else{
        LoadAction(doc) ;
    }

    if(doc.LoadFile("data/Condition.xml")){
        printf("%s\n", doc.ErrorName()) ;
    } else{
        LoadCondition(doc) ;
    }

    std::cout << std::endl << "Fichiers charges ..." << std::endl ;
}

void ResourcesManager::LoadTypeAttribute(tinyxml2::XMLDocument& docIn){
    for(tinyxml2::XMLElement* it = FirstTuple(docIn) ; it != NULL ; it=it->NextSiblingElement()){
        try{
            std::string tmpLabel = ExtractStr(it, "Label") ;
            _listTypesAttribute.push_back(TypeAttribute(tmpLabel)) ;
        } catch(std::exception& e){
            std::cout << "Erreur de creation de TypeAttribute : " << e.what() << std::endl ;
        }
    }
}

void ResourcesManager::LoadTypeEffect(tinyxml2::XMLDocument& docIn){
    for(tinyxml2::XMLElement* it = FirstTuple(docIn) ; it != NULL ; it=it->NextSiblingElement()){
        try{
            std::string tmpLabel = ExtractStr(it, "Label") ;
            int tmpTarget = ExtractInt(it, "IdTypeAttribute") ;
            _listTypesEffect.push_back(TypeEffect(tmpLabel, _listTypesAttribute[tmpTarget].Type())) ;
        } catch(std::exception& e){
            std::cout << "Erreur de creation de TypeEffect : " << e.what() << std::endl ;
        }
    }
}

void ResourcesManager::LoadTypePart(tinyxml2::XMLDocument& docIn){
    for(tinyxml2::XMLElement* it = FirstTuple(docIn) ; it != NULL ; it=it->NextSiblingElement()){
        try{
            std::string tmpLabel = ExtractStr(it, "Label") ;
            _listTypesPart.push_back(TypePart(tmpLabel)) ;
        } catch(std::exception& e){
            std::cout << "Erreur de creation de TypePart : " << e.what() << std::endl ;
        }
    }
}

void ResourcesManager::LoadBiome(tinyxml2::XMLDocument& docIn){
    for(tinyxml2::XMLElement* it = FirstTuple(docIn) ; it != NULL ; it=it->NextSiblingElement()){
        try{
            std::string tmpLabel = ExtractStr(it, "Label") ;
            _listBiomes.push_back(Biome(tmpLabel)) ;
        } catch(std::exception& e){
            std::cout << "Erreur de creation de Biome : " << e.what() << std::endl ;
        }
    }
}

void ResourcesManager::LoadEntity(tinyxml2::XMLDocument& docIn){
    for(tinyxml2::XMLElement* it = FirstTuple(docIn) ; it != NULL ; it=it->NextSiblingElement()){
        try{
            _listEntities.push_back(Entity()) ;
        } catch(std::exception& e){
            std::cout << "Erreur de creation de Entity : " << e.what() << std::endl ;
        }
    }
}

void ResourcesManager::LoadAttribute(tinyxml2::XMLDocument& docIn){
    for(tinyxml2::XMLElement* it = FirstTuple(docIn) ; it != NULL ; it=it->NextSiblingElement()){
        try{
            std::string tmpName = ExtractStr(it, "Name") ;
            int tmpValue = ExtractInt(it, "Value") ;
            int tmpTypeAttribute = ExtractInt(it, "IdTypeAttribute") ;
            int tmpEntity = ExtractInt(it, "IdEntity") ;
            // TODO (IsilinBN#1#): Traiter l'ajout des attributs sur les entités.
            _listAttributes.push_back(Attribute(_listTypesAttribute[tmpTypeAttribute], tmpName, tmpValue)) ;
        } catch(std::exception& e){
            std::cout << "Erreur de creation de Attribute : " << e.what() << std::endl ;
        }
    }
}

void ResourcesManager::LoadPart(tinyxml2::XMLDocument& docIn){
    for(tinyxml2::XMLElement* it = FirstTuple(docIn) ; it != NULL ; it=it->NextSiblingElement()){
        try{
            std::string tmpName = ExtractStr(it, "Name") ;
            int tmpTypePart = ExtractInt(it, "IdTypePart") ;
            _listParts.push_back(Part(tmpName, _listTypesPart[tmpTypePart])) ;
        } catch(std::exception& e){
            std::cout << "Erreur de creation de Part : " << e.what() << std::endl ;
        }
    }
}

void ResourcesManager::LoadAction(tinyxml2::XMLDocument& docIn){
    for(tinyxml2::XMLElement* it = FirstTuple(docIn) ; it != NULL ; it=it->NextSiblingElement()){
        try{
            std::string tmpName = ExtractStr(it, "Name") ;
            int tmpCost = ExtractInt(it, "Cost") ;
            int tmpDistanceMin = ExtractInt(it, "DistanceMin") ;
            int tmpDistanceMax = ExtractInt(it, "DistanceMax") ;
            std::string tmpDirection = ExtractStr(it, "Direction") ;
            int tmpPart = ExtractInt(it, "IdPart") ;
            // TODO (IsilinBN#1#): Traiter la direction
            _listActions.push_back(Action(Area(tmpDistanceMin, tmpDistanceMax), Direction(UP), tmpCost, tmpName)) ;
            // TODO (IsilinBN#1#): Résoudre l'erreur de linkage de part avec action
            //_listParts[tmpPart] += _listActions.back() ;
        } catch(std::exception& e){
            std::cout << "Erreur de creation de Action : " << e.what() << std::endl ;
        }
    }
}

void ResourcesManager::LoadCondition(tinyxml2::XMLDocument& docIn){
    for(tinyxml2::XMLElement* it = FirstTuple(docIn) ; it != NULL ; it=it->NextSiblingElement()){
        try{
            bool tmpTemporary = ExtractBool(it, "Temporary") ;
            int tmpRemainingTurns = ExtractInt(it, "RemainingTurns") ;
            std::string tmpNameEffect = ExtractStr(it, "NameEffect") ;
            int tmpValueEffect = ExtractInt(it, "ValueEffect") ;
            int tmpTypeEffect = ExtractInt(it, "IdTypeEffect") ;
            int tmpAction = ExtractInt(it, "IdAction") ;

            _listEffects.push_back(Effect(tmpValueEffect, tmpNameEffect, _listTypesEffect[tmpTypeEffect])) ;
            _listConditions.push_back(Condition(_listEffects.back(), tmpRemainingTurns, tmpTemporary)) ;
            _listActions[tmpAction] += _listConditions.back() ;
        } catch(std::exception& e){
            std::cout << "Erreur de creation de Condition : " << e.what() << std::endl ;
        }
    }
}
