#ifndef ENGINEEVENT_HPP_INCLUDED
#define ENGINEEVENT_HPP_INCLUDED

/**
 * @file     EngineEvent.hpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Declaration of class EngineEvent.
 */

#include "CoreEngine.hpp"
#include "GraphicEngine.hpp"
#include "SoundEngine.hpp"
#include <map>
#include <string>
#include <utility>
#include <iostream>

/**
 * @class EngineEvent EngineEvent.hpp EngineEvent
 * @brief The message sent by engines.
 */
class EngineEvent
{
private :
    static CoreEngine* _coreEngine ; /**< @brief Attribute : a CoreEngine object pointer . */
    static GraphicEngine* _graphicEngine ; /**< @brief Attribute : a GraphicEngine object pointer . */
    static SoundEngine* _soundEngine ; /**< @brief Attribute : a SoundEngine object pointer . */

public :
    std::string _type ; /**< @brief Attribute : the type of message . */
    std::map<std::string, std::string> _stringData ; /**< @brief Attribute : an array of string data . */
    std::map<std::string, int> _intData ; /**< @brief Attribute : an array of integer data . */

    static inline void SetCoreEngine(const CoreEngine* value){_coreEngine = const_cast<CoreEngine*>(value) ;} ; /** @fn void SetCoreEngine(const CoreEngine* value)
                                                                                                                  * @brief A mutator of _coreEngine attribute.
                                                                                                                  * @param [in] value - the value to be applied. */

    static inline void SetGraphicEngine(const GraphicEngine* value){_graphicEngine = const_cast<GraphicEngine*>(value) ;} ; /** @fn void SetGraphicEngine(const GraphicEngine* value)
                                                                                                                              * @brief A mutator of _graphicEngine attribute.
                                                                                                                              * @param [in] value - the value to be applied. */

    static inline void SetSoundEngine(const SoundEngine* value){_soundEngine = const_cast<SoundEngine*>(value) ;} ; /** @fn void SetSoundEngine(const SoundEngine* value)
                                                                                                                      * @brief A mutator of _soundEngine attribute.
                                                                                                                      * @param [in] value - the value to be applied. */

    static inline void SendToCore(EngineEvent* event){EngineEvent::_coreEngine->PushEvent(event) ;} ; /** @fn void SendToCore(EngineEvent* event)
                                                                                                        * @brief Send a message to _coreEngine.
                                                                                                        * @param [in] event - the event to be sent. */

    static inline void SendToGraphic(EngineEvent* event){EngineEvent::_graphicEngine->PushEvent(event) ;} ; /** @fn SendToGraphic(EngineEvent* event)
                                                                                                              * @brief Send a message to _graphicEngine.
                                                                                                              * @param [in] event - the event to be sent. */

    static inline void SendToSound(EngineEvent* event){EngineEvent::_soundEngine->PushEvent(event) ;} ; /** @fn void SendToSound(EngineEvent* event)
                                                                                                          * @brief Send a message to _soundEngine.
                                                                                                          * @param [in] event - the event to be sent. */
} ;

#endif // ENGINEEVENT_HPP_INCLUDED
