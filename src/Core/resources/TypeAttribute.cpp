#include "TypeAttribute.hpp"
#include <iostream>

TypeAttribute::TypeAttribute(const std::string& typeIn) : _type(typeIn){
    std::cout << "Creation du TypeAttribute : " << typeIn << std::endl ;
}

TypeAttribute::TypeAttribute(const TypeAttribute& cloneIn) : _type(cloneIn.Type()){
}

TypeAttribute::~TypeAttribute(){
}

const std::string& TypeAttribute::Type() const{
    return _type ;
}
