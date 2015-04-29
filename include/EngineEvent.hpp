#ifndef ENGINEEVENT_HPP_INCLUDED
#define ENGINEEVENT_HPP_INCLUDED

#include <string>
#include <map>
class EngineEventManager ;
#include "TypeEngine.hpp"

struct EngineEvent{
public :
    static void AttachManager(EngineEventManager* managerIn) ;

    EngineEvent() ;
    EngineEvent(const EngineEvent& cloneIn) ;
    ~EngineEvent() ;
    EngineEvent& operator=(const EngineEvent& cloneIn) ;

    const std::string& Type() const ;
    const std::string& StringData(const std::string& keyIn) const ;
    int IntData(const std::string& keyIn) const ;

    void SetType(const std::string& typeIn) ;
    void AddStringData(const std::pair<std::string, std::string>& newDataIn) ;
    void AddIntData(const std::pair<std::string, int>& newDataIn) ;

    void SendTo(const TypeEngine recipientIn) const ;
protected :
    const std::map<std::string, std::string>& StringDatas() const ;
    const std::map<std::string, int>& IntDatas() const ;
private :
    std::string _type ;
    std::map<std::string, std::string> _stringData ;
    std::map<std::string, int> _intData ;

    static EngineEventManager* _manager ;
} ;


#endif // ENGINEEVENT_HPP_INCLUDED
