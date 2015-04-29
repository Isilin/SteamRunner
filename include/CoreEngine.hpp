#ifndef COREENGINE_HPP_INCLUDED
#define COREENGINE_HPP_INCLUDED

#include "Engine.hpp"
#include "FSM.hpp"
#include "ResourcesManager.hpp"

class CoreEngine : public Engine{
public :
    CoreEngine() ;
    ~CoreEngine() ;

    CoreEngine(const CoreEngine&) = delete ;
    CoreEngine& operator=(const CoreEngine&) = delete ;

    virtual TypeEngine Id() const ;
protected :
    virtual void ProcessEvent(const EngineEvent& eventIn) ;
    virtual void Frame() ;
private :
    FiniteStatesMachine _fsm ;
    ResourcesManager _rm ;
} ;

#endif // COREENGINE_HPP_INCLUDED
