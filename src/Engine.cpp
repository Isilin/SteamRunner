#include "Engine.hpp"

Engine::Engine() : _eventQueue(), _running(false), _thread(&Engine::ExecuteThread, this){
}

Engine::~Engine(){
    while(!_eventQueue.empty()){
        _eventQueue.pop() ;
    }
}

void Engine::PushEvent(const EngineEvent& eventIn){
    _eventQueue.push(eventIn) ;
}

bool Engine::IsRunning() const{
    return _running ;
}

TypeEngine Engine::Id() const{
    return NONE ;
}

void Engine::StartThread(){
    _running = true ;
    _thread.launch() ;
}

void Engine::ExecuteThread(){
    while(IsRunning()){
        ProcessQueue() ;
        Frame() ;
    }
}

void Engine::StopThread(){
    _running = false ;
}

void Engine::ProcessQueue()
{
    while(!_eventQueue.empty())
    {
        ProcessEvent(_eventQueue.front()) ;
        _eventQueue.pop() ;
    }
}

void Engine::ProcessEvent(const EngineEvent&){
}

void Engine::Frame(){
}
