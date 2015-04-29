#ifndef XMLUTILITIES_HPP_INCLUDED
#define XMLUTILITIES_HPP_INCLUDED

#include "tinyxml2.h"
#include <string>

int ExtractInt(const tinyxml2::XMLElement* nodeIn, const std::string& keyIn) ;
std::string ExtractStr(const tinyxml2::XMLElement* nodeIn, const std::string& keyIn) ;
bool ExtractBool(const tinyxml2::XMLElement* nodeIn, const std::string& keyIn) ;

tinyxml2::XMLElement* FirstTuple(tinyxml2::XMLDocument& docIn) ;

#endif // XMLUTILITIES_HPP_INCLUDED
