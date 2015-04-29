#ifndef CREDITSCREEN_HPP_INCLUDED
#define CREDITSCREEN_HPP_INCLUDED

#include "State.hpp"

class CreditScreen : public State{
public :
    CreditScreen() ;
    ~CreditScreen() ;

    virtual void Back() ;

    virtual const std::string Name() ;
protected :
private :
} ;

#endif // CREDITSCREEN_HPP_INCLUDED
