#include "PerkScreen.hpp"
#include <iostream>
#include "TitleScreen.hpp"
#include "CharacterScreen.hpp"

PerkScreen::PerkScreen() : State(){
    std::cout << "Entree dans l'etat PerkScreen ..." << std::endl ;
}

PerkScreen::~PerkScreen(){
    std::cout << "Suppression de l'etat PerkScreen ..." << std::endl ;
}

void PerkScreen::Next(){
    std::cout << "Transition Next de PerkScreen vers CharacterScreen ..." << std::endl ;
    _deleteMe = true ;
    _newState = new CharacterScreen() ;
}

void PerkScreen::Back(){
    std::cout << "Transition Next de PerkScreen vers TitleScreen ..." << std::endl ;
    _deleteMe = true ;
    _newState = new TitleScreen() ;
}

const std::string PerkScreen::Name(){
    return std::string("PerkScreen") ;
}
