/**
 * @file     Engine.cpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Methods of class Engine.
 */

#include "Engine.hpp"
#include "GraphicEngine.hpp"
#include "CoreEngine.hpp"
#include "EngineEvent.hpp"
#include "SoundEngine.hpp"
#include <iostream>

Engine::Engine(Game* parent) : _parent(parent)
{

}

Engine::~Engine()
{

}

void Engine::ProcessQueue()
{
    while(!_eventQueue.empty())
    {
        ProcessEvent(_eventQueue.front()) ;
        delete(_eventQueue.front()) ;
        _eventQueue.pop() ;
    }
}

void Engine::SendMessageToGraphic(EngineEvent* event) const
{
    _graphicEngine->PushEvent(event) ;
}

void Engine::SendMessageToCore(EngineEvent* event) const
{
    _coreEngine->PushEvent(event) ;
}

void Engine::SendMessageToSound(EngineEvent* event) const
{
    _soundEngine->PushEvent(event) ;
}

