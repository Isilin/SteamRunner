#ifndef LEAVESCREEN_HPP_INCLUDED
#define LEAVESCREEN_HPP_INCLUDED

#include "State.hpp"

class LeaveScreen : public State{
public :
    LeaveScreen() ;
    ~LeaveScreen() ;

    virtual const std::string Name() ;
protected :
private :
} ;

#endif // LEAVESCREEN_HPP_INCLUDED
