#include <iostream>
#include "Biome.hpp"

Biome::Biome(const std::string& nameIn) : Named(nameIn){
    std::cout << "Creation du Biome : " << nameIn << std::endl ;
}

Biome::Biome(const Biome& cloneIn) : Named(cloneIn.Name()){
}

Biome::~Biome(){
}

bool Biome::operator==(const Biome& rightOperandIn) const{
    return _name.compare(rightOperandIn.Name()) == 0 ;
}
