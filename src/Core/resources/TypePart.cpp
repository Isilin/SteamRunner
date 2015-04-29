#include <iostream>
#include "TypePart.hpp"

TypePart::TypePart(const std::string& typeIn) : _type(typeIn){
    std::cout << "Creation du TypePart : " << typeIn << std::endl ;
}

TypePart::TypePart(const TypePart& cloneIn) : _type(cloneIn.Type()){
}

TypePart::~TypePart(){
}

const std::string& TypePart::Type() const{
    return _type ;
}
