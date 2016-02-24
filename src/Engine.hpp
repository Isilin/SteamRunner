#ifndef ENGINE_HPP_INCLUDED
#define ENGINE_HPP_INCLUDED

/**
 * @file     Engine.hpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Declaration of class Engine.
 */

#include <queue>
#include <iostream>
class Game ;
class GraphicEngine ;
class CoreEngine ;
class EngineEvent ;
class SoundEngine ;

/**
 * @class Engine Engine.hpp Engine
 * @brief Declaration of the virtual class engine.
 */
class Engine
{
public :
    Engine(Game* parent) ; /** @fn Engine(Game* parent)
                             * @brief Constructor.
                             * @param [in] parent - A Game class pointer. */

    virtual ~Engine() ;/** @fn ~Engine() @brief Destructor.  */

    virtual void Frame() = 0 ; /** @fn void Frame() @brief Frame of Engine. */

    inline void AttachGraphicEngine(GraphicEngine* value){ _graphicEngine = value ; } ; /** @fn void AttachGraphicEngine(GraphicEngine* value)
                                                                                          * @brief Save a link to a graphic engine.
                                                                                          * @param [in] value - a GraphicEngine object pointer. */

    inline void AttachCoreEngine(CoreEngine* value){ _coreEngine = value ; } ; /** @fn void AttachCoreEngine(CoreEngine* value)
                                                                                 * @brief Save a link to a core engine.
                                                                                 * @param [in] value - a CoreEngine object pointer. */

    inline void AttachSoundEngine(SoundEngine* value) {_soundEngine = value ; } ; /** @fn void AttachSoundEngine(SoundEngine* value)
                                                                                    * @brief Save a link to a sound engine.
                                                                                    * @param [in] value - a SoundEngine object pointer. */

    inline void PushEvent(EngineEvent* event){_eventQueue.push(event) ;} ; /** @fn void PushEvent(EngineEvent* event)
                                                                             * @brief Push an event in the queue.
                                                                             * @param [in] event - the event to be process. */

    void ProcessQueue() ; /** @fn void ProcessQueue()
                            * @brief Process the queue of events. */

    virtual void ProcessEvent(const EngineEvent* event) = 0 ; /** @fn void ProcessEvent(const EngineEvent* event)
                                                                * @brief Process an event.
                                                                * @param [in] event - the event to be process. */

    void SendMessageToGraphic(EngineEvent* event) const ; /** @fn void SendMessageToGraphic(EngineEvent* event) const
                                                            * @brief Send a message to Graphic Engine.
                                                            * @param [in] event - the event to be sent. */

    void SendMessageToCore(EngineEvent* event) const ; /** @fn void SendMessageToCore(EngineEvent* event) const
                                                         * @brief Send a message to Core Engine.
                                                         * @param [in] event - the event to be sent. */

    void SendMessageToSound(EngineEvent* event) const ; /** @fn void SendMessageToSound(EngineEvent* event) const
                                                          * @brief Send a message to Sound Engine.
                                                          * @param [in] event - the event to be sent. */

protected :
    Game* _parent ; /**< @brief Attribute : a game object pointer . */
    GraphicEngine* _graphicEngine ; /**< @brief Attribute : a GraphicEngine object pointer . */
    CoreEngine* _coreEngine ; /**< @brief Attribute : a CoreEngine object pointer . */
    SoundEngine* _soundEngine ; /**< @brief Attribute : a SoundEngine object pointer . */
    std::queue<EngineEvent*> _eventQueue ; /**< @brief Attribute : a queue of events to be process. */
} ;

#endif // ENGINE_HPP_INCLUDED
