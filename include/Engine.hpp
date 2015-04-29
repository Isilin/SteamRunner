#ifndef ENGINE_HPP_INCLUDED
#define ENGINE_HPP_INCLUDED

#include <queue>
#include <string>
#include "EngineEvent.hpp"
#include "TypeEngine.hpp"
#include "SFML/System.hpp"

class Engine{
public :
    Engine() ;
    virtual ~Engine() ;

    Engine(const Engine&) = delete ;
    Engine& operator=(const Engine&) = delete ;

    void PushEvent(const EngineEvent& eventIn) ;
    bool IsRunning() const ;
    virtual TypeEngine Id() const ;
    void StartThread() ;
    void StopThread() ;
    virtual void ExecuteThread() ;
protected:
    std::queue<EngineEvent> _eventQueue ;
    bool _running ;

    void ProcessQueue() ;
    virtual void ProcessEvent(const EngineEvent&) ;
    virtual void Frame() ;
private :
    sf::Thread _thread ;

} ;

#endif // ENGINE_HPP_INCLUDED
