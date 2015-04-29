#ifndef TITLESCREEN_HPP_INCLUDED
#define TITLESCREEN_HPP_INCLUDED

#include "State.hpp"

class TitleScreen : public State{
public :
    TitleScreen() ;
    ~TitleScreen() ;

    virtual void Leave() ;
    virtual void Play() ;
    virtual void Credit() ;
    virtual void Option() ;

    virtual const std::string Name() ;
protected :
private :
} ;

#endif // TITLESCREEN_HPP_INCLUDED
