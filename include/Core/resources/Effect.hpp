#ifndef EFFECT_HPP_INCLUDED
#define EFFECT_HPP_INCLUDED

#include "TypeEffect.hpp"
#include "Named.hpp"

class Effect : public TypeEffect, public Named{
public :
    Effect(const int valueIn, const std::string& nameIn, const TypeEffect& typeIn) ;
    Effect(const Effect& cloneIn) ;
    ~Effect() ;

    int Value() const ;
protected :

private :
    int _value ;
} ;

#endif // EFFECT_HPP_INCLUDED
