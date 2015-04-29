#ifndef FINITESTATESMACHINE_HPP_INCLUDED
#define FINITESTATESMACHINE_HPP_INCLUDED

#include "State.hpp"

class FiniteStatesMachine{
public :
    FiniteStatesMachine() ;
    ~FiniteStatesMachine() ;

    void Refresh(const std::string& infoIn) ;
    const std::string CurrentState() ;
protected :
private :
    State* _currentState ;

    FiniteStatesMachine(const FiniteStatesMachine&) ;
    FiniteStatesMachine& operator=(const FiniteStatesMachine&) ;
} ;

#endif // FINITESTATESMACHINE_HPP_INCLUDED
