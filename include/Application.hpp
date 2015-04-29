#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include <vector>
#include "Engine.hpp"
#include "EngineEventManager.hpp"

class Application{
public :
    Application() ;
    ~Application() ;

    Application(const Application&) = delete ;
    Application& operator=(const Application&) =delete ;

    void Run() ;
protected :
private :
    void Start() ;
    bool AllEnginesAreStopped() const ;

    std::vector<Engine*> _listEngines ;
    EngineEventManager _mailCenter ;
} ;

#endif // APPLICATION_HPP_INCLUDED
