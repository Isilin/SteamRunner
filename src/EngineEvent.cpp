/**
 * @file     EngineEvent.cpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Initialization of static attributes in class EngineEvent.
 */

#include "EngineEvent.hpp"

CoreEngine* EngineEvent::_coreEngine = NULL ;
GraphicEngine* EngineEvent::_graphicEngine = NULL ;
SoundEngine* EngineEvent::_soundEngine = NULL ;
