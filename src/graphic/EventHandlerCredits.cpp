/**
 * @file     EventHandlerCredits.cpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Methods of class EventHandlerCredits.
 */

#include "EventHandlerCredits.hpp"

#include "SFML/Window.hpp"
#include <vector>
#include "../EngineEvent.hpp"

using namespace sf ;
using namespace std ;

EventHandlerCredits::EventHandlerCredits(GraphicEngine* parent) : EventHandler(parent)
{
}

EventHandlerCredits::~EventHandlerCredits()
{
}

void EventHandlerCredits::OnEvent()
{
    if(type == KeyReleased)
    {
        if(key.code == Keyboard::Escape)
        {
            EngineEvent* message = new EngineEvent() ;
            message->_stringData.insert(pair<string, string>("key", "escape")) ;
            message->_type = "keyReleased" ;
            EngineEvent::SendToGraphic(message) ;
            message = NULL ;
        }
    }
}
