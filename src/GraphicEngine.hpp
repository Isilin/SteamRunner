#ifndef GRAPHICENGINE_HPP_INCLUDED
#define GRAPHICENGINE_HPP_INCLUDED

/**
 * @file     GraphicEngine.hpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Declaration of class GraphicEngine.
 */

#include "SFML/Window.hpp"
#include <vector>
#include "graphic/EventHandler.hpp"
#include "graphic/Display.hpp"
#include "Engine.hpp"

class EventHandlerHome ;

/**
 * @class GraphicEngine GraphicEngine.hpp GraphicEngine
 * @brief The graphic engine of the game.
 */
class GraphicEngine : public Engine
{
public :
    GraphicEngine(Game* parent) ; /** @fn GraphicEngine(Game* parent)
                                    * @brief Constructor.
                                    * @param [in] parent - A Game class pointer. */

    ~GraphicEngine() ; /** @fn ~GraphicEngine()
                         * @brief Destructor. */


    virtual void Frame() ; /** @fn void Frame()
                             * @brief Frame of GraphicEngine. */

    inline void CloseWindow(){ _window.close() ; } ; /** @fn void CloseWindow()
                                                       * @brief Close the window of GUI. */

    void DisplayHome(const bool haveToBeInitialized) ; /** @fn void DisplayHome(const bool haveToBeInitialized)
                                                         * @brief Refresh screen if we are on home screen.
                                                         * @param [in] haveToBeInitialized - it indicates if we have to reinitialize the display. */

    void DisplayPU(const bool haveToBeInitialized) ; /** @fn void DisplayPU(const bool haveToBeInitialized)
                                                         * @brief Refresh screen if we are on PU Tree screen.
                                                         * @param [in] haveToBeInitialized - it indicates if we have to reinitialize the display. */

    void DisplayPlayer(const bool haveToBeInitialized) ; /** @fn void DisplayPlayer(const bool haveToBeInitialized)
                                                         * @brief Refresh screen if we are on player choice screen.
                                                         * @param [in] haveToBeInitialized - it indicates if we have to reinitialize the display. */

    void DisplayGame(const bool haveToBeInitialized) ; /** @fn void DisplayGame(const bool haveToBeInitialized)
                                                         * @brief Refresh screen if we are in game.
                                                         * @param [in] haveToBeInitialized - it indicates if we have to reinitialize the display. */

    void DisplayCredits(const bool haveToBeInitialized) ; /** @fn void DisplayCredits(const bool haveToBeInitialized)
                                                         * @brief Refresh screen if we are on credits screen.
                                                         * @param [in] haveToBeInitialized - it indicates if we have to reinitialize the display. */

    void DisplayOptions(const bool haveToBeInitialized) ; /** @fn void DisplayOptions(const bool haveToBeInitialized)
                                                         * @brief Refresh screen if we are on options screen.
                                                         * @param [in] haveToBeInitialized - it indicates if we have to reinitialize the display. */

    virtual void ProcessEvent(const EngineEvent* event) ; /** @fn void ProcessEvent(const EngineEvent* event)
                                                            * @brief Process an event.
                                                            * @param [in] event - the event to be process. */

    /**
      * @enum Location
      * @brief It indicates the current display.
      */
    enum{ ON_HOME, /**< @brief On home. */
          ON_PU, /**< @brief On PU Tree. */
          ON_PLAYER, /**< @brief On player choice */
          ON_GAME, /**< @brief In game. */
          ON_CREDITS, /**< @brief On credits. */
          ON_OPTIONS /**< @brief On options. */
        } typedef Location ;

private :
    std::vector<EventHandler*> _eventHandlers ; /**< @brief Attribute : an array of event's handlers . */
    std::vector<Display*> _displays ; /**< @brief Attribute : an array of displaying objects . */
    Location _currentLocation ; /**< @brief Attribute : the current display . */
    sf::VideoMode _resolution ; /**< @brief Attribute : the resolution of screen . */
    sf::RenderWindow _window ; /**< @brief Attribute : the window of GUI . */
    int _selector ; /**< @brief Attribute : the button's selector . */
    Location _validator ; /**< @brief Attribute : an anti-bug click . */
    sf::Vector2f _mousePosition ; /**< @brief Attribute : the last mouse position  . */
    int _unfixedElement ; /**< @brief Attribute : the current displaying unfixed object . */
} ;

#endif // GRAPHICENGINE_HPP_INCLUDED
