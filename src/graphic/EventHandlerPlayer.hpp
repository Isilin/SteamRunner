#ifndef EVENTHANDLERPLAYER_HPP_INCLUDED
#define EVENTHANDLERPLAYER_HPP_INCLUDED

/**
 * @file     EventHandlerPlayer.hpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Declaration of class EventHandlerPlayer.
 */

#include "EventHandler.hpp"

/**
 * @class EventHandlerPlayer EventHandlerPlayer.hpp EventHandlerPlayer
 * @brief The event's handler on player screen.
 */
class EventHandlerPlayer : public EventHandler
{
public :
    EventHandlerPlayer(GraphicEngine* parent) ; /** @fn EventHandlerPlayer(GraphicEngine* parent)
                                                  * @brief Constructor.
                                                  * @param [in] parent - A Graphic engine object pointer. */

    ~EventHandlerPlayer() ; /** @fn ~EventHandlerPlayer()
                              * @brief Destructor. */

    virtual void OnEvent() ; /** @fn void OnEvent()
                               * @brief Handles the events. */

private :
} ;

#endif // EVENTHANDLERPLAYER_HPP_INCLUDED
