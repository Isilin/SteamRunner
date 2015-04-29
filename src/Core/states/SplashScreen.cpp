#include "SplashScreen.hpp"
#include <iostream>
#include "TitleScreen.hpp"


SplashScreen::SplashScreen() : State(){
    std::cout << "Entree dans l'etat SplashScreen ..." << std::endl ;
}

SplashScreen::~SplashScreen(){
    std::cout << "Suppression de l'etat SplashScreen ..." << std::endl ;
}

void SplashScreen::Next(){
    std::cout << "Transition Next de SplashScreen vers TitleScreen ..." << std::endl ;
    _deleteMe = true ;
    _newState = new TitleScreen() ;
}

const std::string SplashScreen::Name(){
    return std::string("SplashScreen") ;
}
