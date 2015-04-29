#include "XMLUtilities.hpp"

int ExtractInt(const tinyxml2::XMLElement* nodeIn, const std::string& keyIn){
    return std::atoi(nodeIn->Attribute(keyIn.c_str())) ;
}

std::string ExtractStr(const tinyxml2::XMLElement* nodeIn, const std::string& keyIn){
    return std::string(nodeIn->Attribute(keyIn.c_str())) ;
}

bool ExtractBool(const tinyxml2::XMLElement* nodeIn, const std::string& keyIn){
    return std::string(nodeIn->Attribute(keyIn.c_str())).compare("True") == 0 ;
}

tinyxml2::XMLElement* FirstTuple(tinyxml2::XMLDocument& docIn){
    return docIn.FirstChildElement()->FirstChildElement()->NextSiblingElement() ;
}
