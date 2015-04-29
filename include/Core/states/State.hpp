#ifndef STATE_HPP_INCLUDED
#define STATE_HPP_INCLUDED

#include <string>

class State{
public :
    State() ;
    virtual ~State() ;

    virtual void Next() ;
    virtual void Back() ;
    virtual void Leave() ;
    virtual void Play() ;
    virtual void Credit() ;
    virtual void Option() ;
    virtual void Pause() ;

    virtual const std::string Name() = 0 ;
    bool DeleteMe() ;
    State* NewState() ;
protected :
    bool _deleteMe ;
    State* _newState ;
private :
    State(const State&) ;
    State& operator=(const State&) ;
} ;

#endif // STATE_HPP_INCLUDED
