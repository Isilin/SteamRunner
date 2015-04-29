#include "Condition.hpp"
#include <iostream>

Condition::Condition(const Effect& effectIn, const int remainingTurnsIn, bool temporaryIn) :
                    Duration(remainingTurnsIn, temporaryIn), _effect(effectIn){
    std::cout << "Creation de condition " << std::endl ;
}

Condition::Condition(const Condition& cloneIn) : Duration(cloneIn), _effect(cloneIn.GetEffect()){
    std::cout << "Creation de condition " << std::endl ;
}

Condition::~Condition(){
}

const std::string Condition::Description() const{
    std::string tmp = "" ;
    if(_effect.Value() > 0){
        tmp.append("+") ;
    }
    tmp.append(std::to_string(_effect.Value())).append(" sur ").append(_effect.Target()) ;
    if(IsTemporary()){
        tmp.append("[Dans cette salle]") ;
    } else{
        tmp.append(" [").append(std::to_string(RemainingTurns())).append(" tours]") ;
    }
    return tmp ;
}

const Effect& Condition::GetEffect() const{
    return _effect ;
}
