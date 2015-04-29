#include "CreditScreen.hpp"
#include <iostream>
#include "TitleScreen.hpp"

CreditScreen::CreditScreen() : State(){
    std::cout << "Entree dans l'etat CreditScreen ..." << std::endl ;
}

CreditScreen::~CreditScreen(){
    std::cout << "Suppression de l'etat CreditScreen ..." << std::endl ;
}

void CreditScreen::Back(){
    std::cout << "Transition Back de CreditScreen vers TitleScreen ..." << std::endl ;
    _deleteMe = true ;
    _newState = new TitleScreen() ;
}

const std::string CreditScreen::Name(){
    return std::string("CreditScreen") ;
}
