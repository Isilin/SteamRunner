#include "EngineEventManager.hpp"

EngineEventManager::EngineEventManager() : _account(), _accountError(), _guardian(){
    EngineEvent::AttachManager(this) ;
}

EngineEventManager::~EngineEventManager(){
    _account.clear() ;
}

void EngineEventManager::SendMessage(const EngineEvent& messageIn, const TypeEngine recipientIn){
    if(_account.count(recipientIn) > 0){
        _account.at(recipientIn).push(messageIn) ;
    } else{
        _accountError.push(messageIn) ;
    }
}

void EngineEventManager::AddAccount(const TypeEngine accountIn){
    _account.insert(std::pair<TypeEngine, std::queue<EngineEvent> >(accountIn, std::queue<EngineEvent>())) ;
}

EngineEvent EngineEventManager::PopFirstMessage(const TypeEngine accountIn){
    EngineEvent tmp = _account.at(accountIn).front() ;
    _account.at(accountIn).pop() ;
    return tmp ;
}

bool EngineEventManager::NewMessages(const TypeEngine accountIn) const{
    return !_account.at(accountIn).empty() ;
}

void EngineEventManager::Lock(){
    _guardian.lock() ;
}

void EngineEventManager::UnLock(){
    _guardian.unlock() ;
}
