#include "TitleScreen.hpp"
#include <iostream>
#include "CreditScreen.hpp"
#include "OptionScreen.hpp"
#include "LeaveScreen.hpp"
#include "PerkScreen.hpp"

TitleScreen::TitleScreen() : State(){
    std::cout << "Entree dans l'etat TitleScreen ..." << std::endl ;
}

TitleScreen::~TitleScreen(){
    std::cout << "Suppression de l'etat TitleScreen ..." << std::endl ;
}

void TitleScreen::Leave(){
    std::cout << "Transition Leave de TitleScreen vers LeaveScreen ..." << std::endl ;
    _deleteMe = true ;
    _newState = new LeaveScreen() ;
}

void TitleScreen::Play(){
    std::cout << "Transition Play de TitleScreen vers PerkScreen ..." << std::endl ;
    _deleteMe = true ;
    _newState = new PerkScreen() ;
}

void TitleScreen::Credit(){
    std::cout << "Transition Credit de TitleScreen vers CreditScreen ..." << std::endl ;
    _deleteMe = true ;
    _newState = new CreditScreen() ;
}
void TitleScreen::Option(){
    std::cout << "Transition Option de TitleScreen vers OptionScreen ..." << std::endl ;
    _newState = new OptionScreen(this) ;
}

const std::string TitleScreen::Name(){
    return std::string("TitleScreen") ;
}
