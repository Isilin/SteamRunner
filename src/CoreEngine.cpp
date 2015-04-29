#include "CoreEngine.hpp"
#include <iostream>

CoreEngine::CoreEngine() : Engine(), _fsm(), _rm(){
    //_rm.LoadResources() ;
}

CoreEngine::~CoreEngine(){
}

TypeEngine CoreEngine::Id() const{
    return CORE ;
}

void CoreEngine::ProcessEvent(const EngineEvent& eventIn){
}

void CoreEngine::Frame(){
    std::string fin = "" ;
    if(_fsm.CurrentState().compare("LeaveScreen") != 0){
        std::cin >> fin ;
        system("CLS") ;
        std::cout << "Raffraichissement des etats ... " ;
        _fsm.Refresh(fin) ;
    } else{
        StopThread() ;
    }
}
