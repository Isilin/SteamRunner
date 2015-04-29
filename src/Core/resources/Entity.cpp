#include "Entity.hpp"
#include <iostream>

Entity::Entity() : _listAttributes(), _listParts(),
                                               _listConditions(){
    std::cout << "Creation de Entity : " << std::endl ;
}

Entity::~Entity(){
    _listAttributes.clear() ;
    _listParts.clear() ;
    _listConditions.clear() ;
}

void Entity::Suffer(){
    for(std::vector<Condition>::iterator it = _listConditions.begin() ; it != _listConditions.end() ; ++it){
        this->Apply(it->GetEffect()) ;
        --(*it) ;
        if(it->IsFinished()){
            _listConditions.erase(it) ;
        }
    }
}

void Entity::Receive(const Condition& newConditionIn){
    _listConditions.push_back(newConditionIn) ;
}

void Entity::Apply(const Effect& effectIn){
    for(std::vector<Attribute>::iterator it = _listAttributes.begin() ; it != _listAttributes.end() ; ++it){
        if(it->Type().compare(effectIn.Target()) == 0){
            (*it) += effectIn.Value() ;
        }
    }
}
