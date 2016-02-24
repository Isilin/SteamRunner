#ifndef EVENTHANDLERGAME_HPP_INCLUDED
#define EVENTHANDLERGAME_HPP_INCLUDED

/**
 * @file     EventHandlerGame.hpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Declaration of class EventHandlerGame.
 */

#include "EventHandler.hpp"

/**
 * @class EventHandlerGame EventHandlerGame.hpp EventHandlerGame
 * @brief The event's handler on game screen.
 */
class EventHandlerGame : public EventHandler
{
public :
    EventHandlerGame(GraphicEngine* parent) ; /** @fn EventHandlerGame(GraphicEngine* parent)
                                                * @brief Constructor.
                                                * @param [in] parent - A Graphic engine object pointer. */

    ~EventHandlerGame() ; /** @fn ~EventHandlerGame()
                            * @brief Destructor. */

    virtual void OnEvent() ; /** @fn void OnEvent()
                               * @brief Handles the events. */

private :
} ;

#endif // EVENTHANDLERGAME_HPP_INCLUDED
