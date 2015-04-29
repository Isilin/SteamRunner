#include "Attribute.hpp"
#include <iostream>

Attribute::Attribute(const TypeAttribute& typeIn, const std::string& nameIn, const int valueIn) : TypeAttribute(typeIn),
                                                                            Named(nameIn), _value(valueIn), _pool(nullptr){
    std::cout << "Creation de Attribute : " << nameIn << std::endl ;
}

Attribute::Attribute(const Attribute& cloneIn) : TypeAttribute(cloneIn), Named(cloneIn), _value(cloneIn.Value()),
                                                _pool(nullptr){
    std::cout << "Creation de Attribute : " << cloneIn.Name() << std::endl ;
}

Attribute::~Attribute(){
    _pool = nullptr ;
}

Attribute& Attribute::operator+=(const int valueIn){
    _value += valueIn ;
    return *this ;
}

void Attribute::AttachPool(Attribute* poolIn){
    _pool = poolIn ;
}

int Attribute::Value() const{
    return _value ;
}

const Attribute* Attribute::Pool() const{
    return _pool ;
}
