/**
 * @file     EventHandlerPlayer.cpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Methods of class EventHandlerPlayer.
 */

#include "EventHandlerPlayer.hpp"

#include "SFML/Window.hpp"
#include <vector>
#include "../EngineEvent.hpp"

using namespace sf ;
using namespace std ;

EventHandlerPlayer::EventHandlerPlayer(GraphicEngine* parent) : EventHandler(parent)
{
}

EventHandlerPlayer::~EventHandlerPlayer()
{
}

void EventHandlerPlayer::OnEvent()
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
    }
}
