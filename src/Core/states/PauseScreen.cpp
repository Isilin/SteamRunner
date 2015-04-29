#include "PauseScreen.hpp"
#include <iostream>
#include "LeaveScreen.hpp"
#include "EndGameScreen.hpp"
#include "OptionScreen.hpp"
#include "RoomScreen.hpp"

PauseScreen::PauseScreen(State* lastStateIn) : State(), _lastState(lastStateIn){
    std::cout << "Entree dans l'etat PauseScreen ..." << std::endl ;
}

PauseScreen::~PauseScreen(){
    std::cout << "Suppression de l'etat PauseScreen ..." << std::endl ;
    if(_lastState != nullptr){
        delete(_lastState) ;
        _lastState = nullptr ;
    }
}

void PauseScreen::Next(){
    std::cout << "Transition Next de PauseScreen vers EndGameScreen ..." << std::endl ;
    _deleteMe = true ;
    _newState = new EndGameScreen() ;
}

void PauseScreen::Back(){
    std::cout << "Transition Back de PauseScreen vers RoomScreen ..." << std::endl ;
    _deleteMe = true ;
    _newState = _lastState ;
    _lastState = nullptr ;

}

void PauseScreen::Leave(){
    std::cout << "Transition Leave de PauseScreen vers LeaveScreen ..." << std::endl ;
    _deleteMe = true ;
    _newState = new LeaveScreen() ;
}

void PauseScreen::Option(){
    std::cout << "Transition Option de PauseScreen vers OptionScreen ..." << std::endl ;
    _newState = new OptionScreen(this) ;
}

const std::string PauseScreen::Name(){
    return std::string("PauseScreen") ;
}

