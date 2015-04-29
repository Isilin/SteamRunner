#ifndef CHARACTERSCREEN_HPP_INCLUDED
#define CHARACTERSCREEN_HPP_INCLUDED

#include "State.hpp"

class CharacterScreen : public State{
public :
    CharacterScreen() ;
    ~CharacterScreen() ;

    virtual void Next() ;

    virtual const std::string Name() ;
protected :
private :

    CharacterScreen(const CharacterScreen&) ;
    CharacterScreen& operator=(const CharacterScreen&) ;
} ;

#endif // CHARACTERSCREEN_HPP_INCLUDED
