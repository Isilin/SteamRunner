#include "Action.hpp"
#include <iostream>
#include "Entity.hpp"

Action::Action(const Area& aoeIn, const Direction& directionIn, const int costIn, const std::string nameIn) :
                Area(aoeIn), Direction(directionIn), Named(nameIn), _listConditions(), _cost(costIn){
    std::cout << "Creation d'action : " << _name << std::endl ;
}

Action::Action(const Action& cloneIn) : Area(cloneIn), Direction(cloneIn), Named(cloneIn), _listConditions(),
                                        _cost(cloneIn.Cost()){
    for(unsigned short int i = 0 ; i < cloneIn.NumberOfConditions() ; i++){
        (*this) += cloneIn.GetConditions(i) ;
    }
    std::cout << "Creation d'action : " << _name << std::endl ;
}

Action::~Action(){
    _listConditions.clear() ;
}

Action& Action::operator+=(const Condition& newConditionIn){
    _listConditions.push_back(newConditionIn) ;
    return *this ;
}

void Action::Execute(Entity& targetIn){
    for(unsigned short int i = 0 ; i < _listConditions.size() ; i++){
        targetIn.Receive(_listConditions[i]) ;
    }
}

int Action::Cost() const{
    return _cost ;
}

const Condition& Action::GetConditions(const int indiceIn) const{
    return _listConditions[indiceIn] ;
}

int Action::NumberOfConditions() const{
    return _listConditions.size() ;
}
