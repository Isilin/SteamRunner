#ifndef CONDITION_HPP_INCLUDED
#define CONDITION_HPP_INCLUDED

#include "Effect.hpp"
#include "Duration.hpp"

class Condition : public Duration{
public :
    Condition(const Effect& effectIn, const int remainingTurnsIn, bool temporaryIn = false) ;
    Condition(const Condition& cloneIn) ;
    ~Condition() ;

    const std::string Description() const ;
    const Effect& GetEffect() const ;
protected :
private :
    Effect _effect ;
} ;

#endif // CONDITION_HPP_INCLUDED
