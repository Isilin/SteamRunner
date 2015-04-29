#ifndef TYPEATTRIBUTE_HPP_INCLUDED
#define TYPEATTRIBUTE_HPP_INCLUDED

#include <string>

class TypeAttribute{
public :
    TypeAttribute(const std::string& typeIn) ;
    TypeAttribute(const TypeAttribute& cloneIn) ;
    virtual ~TypeAttribute() ;

    const std::string& Type() const ;
protected :
private :
    std::string _type ;
} ;

#endif // TYPEATTRIBUTE_HPP_INCLUDED
