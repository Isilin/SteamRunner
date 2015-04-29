#include "Named.hpp"

Named::Named(const std::string& nameIn) : _name(nameIn){
}

Named::Named(const Named& cloneIn) : _name(cloneIn.Name()){
}

Named::~Named(){
}

const std::string& Named::Name() const{
    return _name ;
}

void Named::Rename(const std::string& newNameIn){
    _name = newNameIn ;
}

