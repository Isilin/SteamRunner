/**
 * @file     EventHandlerPU.cpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Methods of class EventHandlerPU.
 */

#include "EventHandlerPU.hpp"
#include "../EngineEvent.hpp"
#include "../GraphicEngine.hpp"
using namespace sf ;
using namespace std ;

EventHandlerPU::EventHandlerPU(GraphicEngine* parent) : EventHandler(parent)
{
}

EventHandlerPU::~EventHandlerPU()
{
}

void EventHandlerPU::OnEvent()
{
    if(type == MouseMoved)
    {
        EngineEvent* message = new EngineEvent();
        message->_intData.insert(pair<string, int>("x", Mouse::getPosition().x)) ;
        message->_intData.insert(pair<string, int>("y", Mouse::getPosition().y)) ;
        message->_type = "mouseMoved" ;
        EngineEvent::SendToGraphic(message) ;
        message = NULL ;
    }

    if(type == MouseButtonPressed && mouseButton.button == Mouse::Left)
    {
        EngineEvent* message = new EngineEvent();
        message->_intData.insert(pair<string, int>("x", Mouse::getPosition().x)) ;
        message->_intData.insert(pair<string, int>("y", Mouse::getPosition().y)) ;
        message->_type = "mousePressed" ;
        EngineEvent::SendToGraphic(message) ;
        message = NULL ;
    }
    else if(type == MouseButtonReleased && mouseButton.button == Mouse::Left)
    {
        EngineEvent* message = new EngineEvent();
        message->_intData.insert(pair<string, int>("x", Mouse::getPosition().x)) ;
        message->_intData.insert(pair<string, int>("y", Mouse::getPosition().y)) ;
        message->_type = "mouseReleased" ;
        EngineEvent::SendToGraphic(message) ;
        message = NULL ;
    }

    if(type == KeyPressed)
    {
        if(key.code == Keyboard::Return)
        {
            EngineEvent* message = new EngineEvent() ;
            message->_stringData.insert(pair<string, string>("key", "return")) ;
            message->_type = "keyPressed" ;
            EngineEvent::SendToGraphic(message) ;
            message = NULL ;
        }
    }
    else if(type == KeyReleased)
    {
        if(key.code == Keyboard::Up)
        {
            EngineEvent* message = new EngineEvent() ;
            message->_stringData.insert(pair<string, string>("key", "up")) ;
            message->_type = "keyReleased" ;
            EngineEvent::SendToGraphic(message) ;
            message = NULL ;
        }

        if(key.code == Keyboard::Down)
        {
            EngineEvent* message = new EngineEvent() ;
            message->_stringData.insert(pair<string, string>("key", "down")) ;
            message->_type = "keyReleased" ;
            EngineEvent::SendToGraphic(message) ;
            message = NULL ;
        }

        if(key.code == Keyboard::Left)
        {
            EngineEvent* message = new EngineEvent() ;
            message->_stringData.insert(pair<string, string>("key", "left")) ;
            message->_type = "keyReleased" ;
            EngineEvent::SendToGraphic(message) ;
            message = NULL ;
        }

        if(key.code == Keyboard::Right)
        {
            EngineEvent* message = new EngineEvent() ;
            message->_stringData.insert(pair<string, string>("key", "right")) ;
            message->_type = "keyReleased" ;
            EngineEvent::SendToGraphic(message) ;
            message = NULL ;
        }

        if(key.code == Keyboard::Return)
        {
            EngineEvent* message = new EngineEvent() ;
            message->_stringData.insert(pair<string, string>("key", "return")) ;
            message->_type = "keyReleased" ;
            EngineEvent::SendToGraphic(message) ;
            message = NULL ;
        }
    }
}
