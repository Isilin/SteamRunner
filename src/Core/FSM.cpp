#include "FSM.hpp"
#include "SplashScreen.hpp"
#include <iostream>

FiniteStatesMachine::FiniteStatesMachine() : _currentState(nullptr){
    _currentState = new SplashScreen() ;
}

FiniteStatesMachine::~FiniteStatesMachine(){
    delete(_currentState) ;
}

void FiniteStatesMachine::Refresh(const std::string& infoIn){
    if(infoIn.compare("Next") == 0){
        _currentState->Next() ;
    } else if(infoIn.compare("Back") == 0){
        _currentState->Back() ;
    } else if(infoIn.compare("Leave") == 0){
        _currentState->Leave() ;
    } else if(infoIn.compare("Play") == 0){
        _currentState->Play() ;
    } else if(infoIn.compare("Credit") == 0){
        _currentState->Credit() ;
    } else if(infoIn.compare("Option") == 0){
        _currentState->Option() ;
    } else if(infoIn.compare("Pause") == 0){
        _currentState->Pause() ;
    } else{
        std::cout << "Cet etat n'existe pas !" << std::endl ;
    }

    State* tmpState = _currentState->NewState() ;
    if(_currentState->DeleteMe()){
        delete(_currentState) ;
        _currentState = nullptr ;
    }
    if(tmpState != nullptr){
        _currentState = tmpState ;
        tmpState = nullptr ;
    }
}

const std::string FiniteStatesMachine::CurrentState(){
    return _currentState->Name() ;
}
