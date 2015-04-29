#ifndef ENDGAMESCREEN_HPP_INCLUDED
#define ENDGAMESCREEN_HPP_INCLUDED

#include "State.hpp"

class EndGameScreen : public State{
public :
    EndGameScreen() ;
    ~EndGameScreen() ;

    virtual void Next() ;

    virtual const std::string Name() ;
protected :
private :
    EndGameScreen(const EndGameScreen&) ;
    EndGameScreen& operator=(const EndGameScreen&) ;
} ;

#endif // ENDGAMESCREEN_HPP_INCLUDED
