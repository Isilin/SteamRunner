#ifndef ROOMSCREEN_HPP_INCLUDED
#define ROOMSCREEN_HPP_INCLUDED

#include "State.hpp"

class RoomScreen : public State{
public :
    RoomScreen() ;
    ~RoomScreen() ;

    virtual void Next() ;
    virtual void Leave() ;
    virtual void Pause() ;

    virtual const std::string Name() ;
protected :
private :
    RoomScreen(const RoomScreen&) ;
    RoomScreen& operator=(const RoomScreen&) ;
} ;

#endif // ROOMSCREEN_HPP_INCLUDED
