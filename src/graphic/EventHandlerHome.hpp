#ifndef EVENTHANDLERHOME_HPP_INCLUDED
#define EVENTHANDLERHOME_HPP_INCLUDED

/**
 * @file     EventHandlerHome.hpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Declaration of class EventHandlerHome.
 */

#include "EventHandler.hpp"

/**
 * @class EventHandlerHome EventHandlerHome.hpp EventHandlerHome
 * @brief The event's handler on home screen.
 */
class EventHandlerHome : public EventHandler
{
public :
    EventHandlerHome(GraphicEngine* parent) ; /** @fn EventHandlerHome(GraphicEngine* parent)
                                                * @brief Constructor.
                                                * @param [in] parent - A Graphic engine object pointer. */

    ~EventHandlerHome() ; /** @fn ~EventHandlerHome()
                            * @brief Destructor. */

    virtual void OnEvent() ; /** @fn void OnEvent()
                               * @brief Handles the events. */

private :
} ;

#endif // EVENTHANDLERHOME_HPP_INCLUDED
