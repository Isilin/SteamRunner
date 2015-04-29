#ifndef OPTIONSCREEN_HPP_INCLUDED
#define OPTIONSCREEN_HPP_INCLUDED

#include "State.hpp"

class OptionScreen : public State{
public :
    OptionScreen(State* lastStateIn) ;
    ~OptionScreen() ;

    virtual void Back() ;
    virtual void Pause() ;

    virtual const std::string Name() ;
protected :
private :
    State* _lastState ;

    OptionScreen(const OptionScreen&) ;
    OptionScreen& operator=(const OptionScreen&) ;
} ;

#endif // OPTIONSCREEN_HPP_INCLUDED
