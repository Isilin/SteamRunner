#ifndef PAUSESCREEN_HPP_INCLUDED
#define PAUSESCREEN_HPP_INCLUDED

#include "State.hpp"

class PauseScreen : public State{
public :
    PauseScreen(State* lastStateIn) ;
    ~PauseScreen() ;

    virtual void Next() ;
    virtual void Back() ;
    virtual void Leave() ;
    virtual void Option() ;

    virtual const std::string Name() ;
protected :
private :
    State* _lastState ;

    PauseScreen(const PauseScreen&) ;
    PauseScreen& operator=(const PauseScreen&) ;
} ;

#endif // PAUSESCREEN_HPP_INCLUDED
