#ifndef ATTRIBUTE_HPP_INCLUDED
#define ATTRIBUTE_HPP_INCLUDED

#include "TypeAttribute.hpp"
#include "Named.hpp"

class Attribute : public TypeAttribute, public Named{
public :
    Attribute(const TypeAttribute& typeIn, const std::string& nameIn, const int valueIn) ;
    Attribute(const Attribute& cloneIn) ;
    ~Attribute() ;

    Attribute& operator+=(const int valueIn) ;
    void AttachPool(Attribute* poolIn) ;

    int Value() const ;
    const Attribute* Pool() const ;
protected :
private :
    int _value ;
    Attribute* _pool ;

    Attribute& operator=(const Attribute&) ;
} ;

#endif // ATTRIBUTE_HPP_INCLUDED
