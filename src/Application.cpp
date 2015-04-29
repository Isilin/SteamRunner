#include "Application.hpp"
#include "CoreEngine.hpp"
#include "GraphicEngine.hpp"

Application::Application() : _listEngines(), _mailCenter(){
    // Creer les engines et leur creer ou non un compte dans le mailCenter
    _listEngines.push_back(new CoreEngine()) ;
    _listEngines.push_back(new GraphicEngine()) ;

    for(Engine* i : _listEngines){
        _mailCenter.AddAccount(i->Id()) ;
    }
}

Application::~Application(){
    for(Engine* i : _listEngines){
        delete(i) ;
    }
    _listEngines.clear() ;
}

void Application::Run(){
    Start() ;
    while(!AllEnginesAreStopped())
    {
        for(Engine* i : _listEngines){
            // Relever les boites au lettres
            _mailCenter.Lock() ;
            while(_mailCenter.NewMessages(i->Id())){
                i->PushEvent(_mailCenter.PopFirstMessage(i->Id())) ;
            }
            _mailCenter.UnLock() ;
        }
    }
}

void Application::Start(){
    for(Engine* i : _listEngines){
        i->StartThread() ;
    }
}

bool Application::AllEnginesAreStopped() const{
    bool result = true ;
    for(Engine* i : _listEngines){
        result = result & !i->IsRunning() ;
    }
    return result ;
}
