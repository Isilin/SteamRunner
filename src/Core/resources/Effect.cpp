#include <iostream>
#include "Effect.hpp"

Effect::Effect(const int valueIn, const std::string& nameIn, const TypeEffect& typeIn) : TypeEffect(typeIn), Named(nameIn),
                                                        _value(valueIn){
    std::cout << "Creation de : " << _name << "[" << _value << "]" << std::endl ;
}

Effect::Effect(const Effect& cloneIn) : TypeEffect(cloneIn), Named(cloneIn), _value(cloneIn.Value()){
    std::cout << "Creation de : " << _name << "[" << _value << "]" << std::endl ;
}

Effect::~Effect(){
    std::cout << "Destruction de l'effet " << _name << std::endl ;
}

int Effect::Value() const{
    return _value ;
}
