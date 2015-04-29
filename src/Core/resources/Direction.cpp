#include <iostream>
#include "Direction.hpp"

Direction::Direction(const EDirection nameIn) : _direction(nameIn){
    std::cout << "De Direction : " << nameIn << std::endl ;
}

Direction::Direction(const Direction& cloneIn) : _direction(cloneIn.GetDirection()){
    std::cout << "De Direction : " << cloneIn.GetDirection() << std::endl ;
}

Direction::~Direction(){
}

EDirection Direction::GetDirection() const{
    return _direction ;
}
