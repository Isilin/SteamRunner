#ifndef PERKSCREEN_HPP_INCLUDED
#define PERKSCREEN_HPP_INCLUDED

#include "State.hpp"

class PerkScreen : public State{
public :
    PerkScreen() ;
    ~PerkScreen() ;

    virtual void Next() ;
    virtual void Back() ;

    virtual const std::string Name() ;
protected :
private :
    PerkScreen(const PerkScreen&) ;
    PerkScreen& operator=(const PerkScreen&) ;
} ;

#endif // PERKSCREEN_HPP_INCLUDED
