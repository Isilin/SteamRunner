#include "EngineEvent.hpp"
#include "EngineEventManager.hpp"

EngineEventManager* EngineEvent::_manager = nullptr ;

void EngineEvent::AttachManager(EngineEventManager* managerIn){
    _manager = managerIn ;
}

EngineEvent::EngineEvent() : _type(), _stringData(), _intData(){
}

EngineEvent::EngineEvent(const EngineEvent& cloneIn) : _type(cloneIn.Type()), _stringData(cloneIn.StringDatas()),
                                                        _intData(cloneIn.IntDatas()){
}

EngineEvent::~EngineEvent(){
}

EngineEvent& EngineEvent::operator=(const EngineEvent& cloneIn){
    _type = cloneIn.Type() ;
    _stringData = cloneIn.StringDatas() ;
    _intData = cloneIn.IntDatas() ;
    return *this ;
}

const std::string& EngineEvent::Type() const{
    return _type ;
}

const std::string& EngineEvent::StringData(const std::string& keyIn) const{
    return _stringData.at(keyIn) ;
}

int EngineEvent::IntData(const std::string& keyIn) const{
    return _intData.at(keyIn) ;
}

void EngineEvent::SetType(const std::string& typeIn){
    _type = typeIn ;
}

void EngineEvent::AddStringData(const std::pair<std::string, std::string>& newDataIn){
    _stringData.insert(newDataIn) ;
}

void EngineEvent::AddIntData(const std::pair<std::string, int>& newDataIn){
    _intData.insert(newDataIn) ;
}

const std::map<std::string, std::string>& EngineEvent::StringDatas() const{
    return _stringData ;
}

const std::map<std::string, int>& EngineEvent::IntDatas() const{
    return _intData ;
}

void EngineEvent::SendTo(const TypeEngine recipientIn) const{
    _manager->Lock() ;
    _manager->SendMessage(*this, recipientIn) ;
    _manager->UnLock() ;
}
