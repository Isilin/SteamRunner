#include <iostream>
#include "Part.hpp"
#include "Entity.hpp"

Part::Part(const std::string& nameIn, const TypePart& typeIn) : Named(nameIn), TypePart(typeIn), _listActions(),
                                                                _listBiomes(), _listConditions(){
    std::cout << "Creation de Partie : " << _name << std::endl ;
}

Part::~Part(){
    _listActions.clear() ;
    _listBiomes.clear() ;
    _listConditions.clear() ;
}

Part& Part::operator+=(const Action& newActionIn){
    _listActions.push_back(newActionIn) ;
    return *this ;
}

Part& Part::operator+=(const Biome& newBiomeIn){
    _listBiomes.push_back(newBiomeIn) ;
    return *this ;
}

Part& Part::operator+=(const Condition& newConditionIn){
    _listConditions.push_back(newConditionIn) ;
    return *this ;
}
