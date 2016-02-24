/**
 * @file     Game.cpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Methods of class Game.
 */

#include "Game.hpp"
#include "EngineEvent.hpp"
#include <iostream>
using namespace std ;

Game::Game() : _graphicEngine(NULL), _coreEngine(NULL), _soundEngine(NULL), _running(false)
{

    _graphicEngine = new GraphicEngine(this) ;
    _coreEngine = new CoreEngine(this) ;
    _soundEngine = new SoundEngine(this) ;

    _graphicEngine->AttachCoreEngine(_coreEngine) ;
    _graphicEngine->AttachSoundEngine(_soundEngine) ;
    _coreEngine->AttachGraphicEngine(_graphicEngine) ;
    _coreEngine->AttachSoundEngine(_soundEngine) ;
    _soundEngine->AttachCoreEngine(_coreEngine) ;
    _soundEngine->AttachGraphicEngine(_graphicEngine) ;

    EngineEvent::SetCoreEngine(_coreEngine) ;
    EngineEvent::SetGraphicEngine(_graphicEngine) ;
    EngineEvent::SetSoundEngine(_soundEngine) ;
}

Game::~Game()
{
    delete _graphicEngine ;
    delete _coreEngine ;
}

void Game::Run()
{
    _running = true ;
    while(_running)
    {
        _graphicEngine->ProcessQueue() ;
        _coreEngine->ProcessQueue() ;
        _soundEngine->ProcessQueue() ;

        _graphicEngine->Frame() ;
        _coreEngine->Frame() ;
        _soundEngine->Frame() ;
    }
}
