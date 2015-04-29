#ifndef RESOURCESMANAGER_HPP_INCLUDED
#define RESOURCESMANAGER_HPP_INCLUDED

#include "tinyxml2.h"

#include "Entity.hpp"

class ResourcesManager{
public :
    ResourcesManager() ;
    ~ResourcesManager() ;

    void LoadResources() ;
protected :
private :
    std::vector<TypeAttribute> _listTypesAttribute ;
    std::vector<TypeEffect> _listTypesEffect ;
    std::vector<TypePart> _listTypesPart ;
    std::vector<Biome> _listBiomes ;
    std::vector<Entity> _listEntities ;
    std::vector<Attribute> _listAttributes ;
    std::vector<Part> _listParts ;
    std::vector<Action> _listActions ;
    std::vector<Effect> _listEffects ;
    std::vector<Condition> _listConditions ;

    void LoadTypeAttribute(tinyxml2::XMLDocument& docIn) ;
    void LoadTypeEffect(tinyxml2::XMLDocument& docIn) ;
    void LoadTypePart(tinyxml2::XMLDocument& docIn) ;
    void LoadBiome(tinyxml2::XMLDocument& docIn) ;
    void LoadEntity(tinyxml2::XMLDocument& docIn) ;
    void LoadAttribute(tinyxml2::XMLDocument& docIn) ;
    void LoadPart(tinyxml2::XMLDocument& docIn) ;
    void LoadAction(tinyxml2::XMLDocument& docIn) ;
    void LoadCondition(tinyxml2::XMLDocument& docIn) ;
} ;

#endif // RESOURCESMANAGER_HPP_INCLUDED
