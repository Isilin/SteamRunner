#include "State.hpp"
#include <iostream>

State::State() : _deleteMe(false), _newState(nullptr) {
}

State::~State(){
    _newState = nullptr ;
}

void State::Next(){
    std::cout << "La transition Next n'est pas definie pour cet etat !" << std::endl ;
}

void State::Back(){
    std::cout << "La transition Back n'est pas definie pour cet etat !" << std::endl ;
}

void State::Leave(){
    std::cout << "La transition Leave n'est pas definie pour cet etat !" << std::endl ;
}

void State::Play(){
    std::cout << "La transition Play n'est pas definie pour cet etat !" << std::endl ;
}

void State::Credit(){
    std::cout << "La transition Credit n'est pas definie pour cet etat !" << std::endl ;
}

void State::Option(){
    std::cout << "La transition Option n'est pas definie pour cet etat !" << std::endl ;
}

void State::Pause(){
    std::cout << "La transition Pause n'est pas definie pour cet etat !" << std::endl ;
}
bool State::DeleteMe(){
    return _deleteMe ;
}
State* State::NewState(){
    return _newState ;
}
