#include "RoomScreen.hpp"
#include <iostream>
#include "EndGameScreen.hpp"
#include "PauseScreen.hpp"

RoomScreen::RoomScreen() : State(){
    std::cout << "Entree dans l'etat RoomScreen ..." << std::endl ;
}

RoomScreen::~RoomScreen(){
    std::cout << "Suppression de l'etat RoomScreen ..." << std::endl ;
}

void RoomScreen::Next(){
    std::cout << "Transition Next de RoomScreen vers RoomScreen ..." << std::endl ;
    _deleteMe = true ;
    _newState = new RoomScreen() ;
}

void RoomScreen::Leave(){
    std::cout << "Transition Leave de RoomScreen vers RoomScreen ..." << std::endl ;
    _deleteMe = true ;
    _newState = new EndGameScreen() ;
}

void RoomScreen::Pause(){
    std::cout << "Transition Pause de RoomScreen vers RoomScreen ..." << std::endl ;
    _newState = new PauseScreen(this) ;
}

const std::string RoomScreen::Name(){
    return std::string("RoomScreen") ;
}
