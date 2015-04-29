#ifndef ENGINEEVENTMANAGER_HPP_INCLUDED
#define ENGINEEVENTMANAGER_HPP_INCLUDED

#include <map>
#include <queue>
#include "EngineEvent.hpp"
#include "TypeEngine.hpp"
#include "SFML/System.hpp"

class EngineEventManager{
public :
    EngineEventManager() ;
    ~EngineEventManager() ;

    EngineEventManager(const EngineEventManager&) = delete ;
    EngineEventManager& operator=(const EngineEventManager&) = delete ;

    void SendMessage(const EngineEvent& messageIn, const TypeEngine recipientIn) ;

    void AddAccount(const TypeEngine accountIn) ;
    EngineEvent PopFirstMessage(const TypeEngine accountIn) ;
    bool NewMessages(const TypeEngine accountIn) const ;

    void Lock() ;
    void UnLock() ;
protected :
private :
    std::map<TypeEngine, std::queue<EngineEvent> > _account ;
    std::queue<EngineEvent> _accountError ;
    sf::Mutex _guardian ;

} ;

#endif // ENGINEEVENTMANAGER_HPP_INCLUDED
