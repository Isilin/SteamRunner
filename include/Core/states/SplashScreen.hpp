#ifndef SPLASHSCREEN_HPP_INCLUDED
#define SPLASHSCREEN_HPP_INCLUDED

#include "State.hpp"

class SplashScreen : public State{
public :
    SplashScreen() ;
    ~SplashScreen() ;

    virtual void Next() ;

    virtual const std::string Name() ;
protected :
private :
} ;

#endif // SPLASHSCREEN_HPP_INCLUDED
