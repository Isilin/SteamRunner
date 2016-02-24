#ifndef EVENTHANDLERPU_HPP_INCLUDED
#define EVENTHANDLERPU_HPP_INCLUDED

/**
 * @file     EventHandlerPU.hpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Declaration of class EventHandlerPU.
 */

#include "EventHandler.hpp"

/**
 * @class EventHandlerPU EventHandlerPU.hpp EventHandlerPU
 * @brief The event's handler on PU tree screen.
 */
class EventHandlerPU : public EventHandler
{
public :
    EventHandlerPU(GraphicEngine* parent) ; /** @fn EventHandlerPU(GraphicEngine* parent)
                                              * @brief Constructor.
                                              * @param [in] parent - A Graphic engine object pointer. */

    ~EventHandlerPU() ; /** @fn ~EventHandlerPU()
                          * @brief Destructor. */

    virtual void OnEvent() ; /** @fn void OnEvent()
                               * @brief Handles the events. */

private :
} ;

#endif // EVENTHANDLERPU_HPP_INCLUDED
