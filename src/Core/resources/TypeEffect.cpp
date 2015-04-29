#include <iostream>
#include "TypeEffect.hpp"

TypeEffect::TypeEffect(const std::string& typeIn, const std::string& targetIn) : _type(typeIn), _target(targetIn){
    std::cout << "Creation du TypeEffect : " << typeIn << std::endl ;
}

TypeEffect::TypeEffect(const TypeEffect& cloneIn) : _type(cloneIn.Type()), _target(cloneIn.Target()){
}

TypeEffect::~TypeEffect(){
}

const std::string& TypeEffect::Type() const{
    return _type ;
}

const std::string& TypeEffect::Target() const{
    return _target ;
}
