#include "OptionScreen.hpp"
#include <iostream>
#include "TitleScreen.hpp"
#include "PauseScreen.hpp"

OptionScreen::OptionScreen(State* lastStateIn) : State(), _lastState(lastStateIn){
    std::cout << "Entree dans l'etat OptionScreen ..." << std::endl ;
}

OptionScreen::~OptionScreen(){
    std::cout << "Suppression de l'etat OptionScreen ..." << std::endl ;
    if(_lastState != nullptr){
        delete(_lastState) ;
        _lastState = nullptr ;
    }
}

void OptionScreen::Back(){
    std::cout << "Transition Back de OptionScreen vers TitleScreen ..." << std::endl ;
    _deleteMe = true ;
    _newState = _lastState ;
    _lastState = nullptr ;
}

void OptionScreen::Pause(){
    std::cout << "Transition Pause de OptionScreen vers PauseScreen ..." << std::endl ;
    _deleteMe = true ;
    _newState = _lastState ;
    _lastState = nullptr ;
}

const std::string OptionScreen::Name(){
    return std::string("OptionScreen") ;
}
