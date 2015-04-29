#include "LeaveScreen.hpp"
#include <iostream>

LeaveScreen::LeaveScreen() : State(){
    std::cout << "Entree dans l'etat LeaveScreen ..." << std::endl ;
}

LeaveScreen::~LeaveScreen(){
    std::cout << "Suppression de l'etat LeaveScreen ..." << std::endl ;
}

const std::string LeaveScreen::Name(){
    return std::string("LeaveScreen") ;
}
