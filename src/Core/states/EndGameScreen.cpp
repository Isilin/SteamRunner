#include "EndGameScreen.hpp"
#include <iostream>
#include "TitleScreen.hpp"


EndGameScreen::EndGameScreen() : State(){
    std::cout << "Entree dans l'etat EndGameScreen ..." << std::endl ;
}

EndGameScreen::~EndGameScreen(){
    std::cout << "Suppression de l'etat EndGameScreen ..." << std::endl ;
}

void EndGameScreen::Next(){
    std::cout << "Transition Next de EndGameScreenScreen vers TitleScreen ..." << std::endl ;
    _deleteMe = true ;
    _newState = new TitleScreen() ;
}

const std::string EndGameScreen::Name(){
    return std::string("EndGameScreen") ;
}
