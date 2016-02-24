#ifndef EVENTHANDLER_HPP_INCLUDED
#define EVENTHANDLER_HPP_INCLUDED

/**
 * @file     EventHandler.hpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Declaration of class EventHandler.
 */

#include "SFML/Window.hpp"
class EngineEvent ;
class GraphicEngine ;

/**
 * @class EventHandler EventHandler.hpp EventHandler
 * @brief The general event's handler.
 */
class EventHandler : public sf::Event
{
public :
    EventHandler(GraphicEngine* parent) ; /** @fn EventHandler(GraphicEngine* parent)
                                            * @brief Constructor.
                                            * @param [in] parent - A Graphic engine object pointer. */

    virtual ~EventHandler() ; /** @fn ~EventHandler()
                                * @brief Destructor. */

    virtual void OnEvent() = 0 ; /** @fn void OnEvent()
                                   * @brief Handles the events. */

protected :
    GraphicEngine* _parent ; /**< @brief Attribute : A Graphic engine object pointer . */
} ;

#endif // EVENTHANDLER_HPP_INCLUDED
