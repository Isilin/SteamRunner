#include "CharacterScreen.hpp"
#include <iostream>
#include "RoomScreen.hpp"

CharacterScreen::CharacterScreen() : State(){
    std::cout << "Entree dans l'etat CharacterScreen ..." << std::endl ;
}

CharacterScreen::~CharacterScreen(){
    std::cout << "Suppression de l'etat CharacterScreen ..." << std::endl ;
}

void CharacterScreen::Next(){
    std::cout << "Transition Next de CharacterScreen vers RoomScreen ..." << std::endl ;
    _deleteMe = true ;
    _newState = new RoomScreen() ;
}

const std::string CharacterScreen::Name(){
    return std::string("CharacterScreen") ;
}
