#ifndef EVENTHANDLERCREDITS_HPP_INCLUDED
#define EVENTHANDLERCREDITS_HPP_INCLUDED

/**
 * @file     EventHandlerCredits.hpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Declaration of class EventHandlerCredits.
 */

#include "EventHandler.hpp"

/**
 * @class EventHandlerCredits EventHandlerCredits.hpp EventHandlerCredits
 * @brief The event's handler on credits screen.
 */
class EventHandlerCredits : public EventHandler
{
public :
    EventHandlerCredits(GraphicEngine* parent) ; /** @fn EventHandlerCredits(GraphicEngine* parent)
                                                   * @brief Constructor.
                                                   * @param [in] parent - A Graphic engine object pointer. */

    ~EventHandlerCredits() ; /** @fn ~EventHandlerCredits()
                               * @brief Destructor. */

    virtual void OnEvent() ; /** @fn void OnEvent()
                               * @brief Handles the events. */

private :
} ;

#endif // EVENTHANDLERCREDITS_HPP_INCLUDED
