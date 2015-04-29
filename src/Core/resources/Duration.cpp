#include "Duration.hpp"
#include <iostream>

Duration::Duration(const int remainingTurnsIn, bool temporaryIn) : _remainingTurns(remainingTurnsIn),
                                                                   _temporary(temporaryIn){
}

Duration::Duration(const Duration& cloneIn) : _remainingTurns(cloneIn.RemainingTurns()), _temporary(cloneIn.IsTemporary()){
}

Duration::~Duration(){
}

Duration& Duration::operator--(){
    if(!_temporary){
        _remainingTurns-- ;
        std::cout << "Duree decrementee et fixee a " << _remainingTurns << "." << std::endl ;
    }
    return *this ;
}

bool Duration::IsTemporary() const{
    return _temporary ;
}

bool Duration::IsFinished() const{
    return _remainingTurns <= 0 ;
}

int Duration::RemainingTurns() const{
    return _remainingTurns ;
}
