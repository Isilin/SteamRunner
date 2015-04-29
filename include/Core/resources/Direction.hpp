#ifndef DIRECTION_HPP_INCLUDED
#define DIRECTION_HPP_INCLUDED

#include <string>

enum EDirection : int{
    LEFT, RIGHT, UP, DOWN
} ;

class Direction{
public :
    Direction(const EDirection nameIn) ;
    Direction(const Direction& cloneIn) ;
    virtual ~Direction() ;

    EDirection GetDirection() const ;
protected :
    EDirection _direction ;
private :
} ;

#endif // DIRECTION_HPP_INCLUDED
