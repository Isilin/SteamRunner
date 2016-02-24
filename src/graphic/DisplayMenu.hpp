#ifndef DISPLAYMENU_HPP_INCLUDED
#define DISPLAYMENU_HPP_INCLUDED

/**
 * @file     DisplayMenu.hpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Declaration of class DisplayMenu.
 */

#include "Display.hpp"

/**
  * @class DisplayMenu DisplayMenu.hpp DisplayMenu
  * @brief The menu's display class.
  */
class DisplayMenu : public Display
{
public :
    DisplayMenu(const sf::Color filter,
                const std::string path,
                const std::string text,
                const sf::IntRect sizeSprite,
                const sf::IntRect position,
                const uint16 nbButtons = 1) ; /** @fn DisplayMenu(const sf::Color filter,
                                                *                 const std::string path,
                                                *                 const std::string text,
                                                *                 const sf::IntRect sizeSprite,
                                                *                 const sf::IntRect position,
                                                *                 const uint16 nbButtons = 1)
                                                * @brief Constructor.
                                                * @param [in] filter - Color that shall be in transparence.
                                                * @param [in] path - Path of the image.
                                                * @param [in] text - Text of the buttons.
                                                * @param [in] sizeSprite - Size of the sprite.
                                                * @param [in] position - Position of a button and the next.
                                                * @param [in] nbButtons - Number of buttons. */

	~DisplayMenu() ;  /** @fn ~DisplayMenu()
                        * @brief Destructor. */

    virtual void Refresh() ; /** @fn void Refresh()
                               * @brief Refresh texture of the display object. */

private :
    sf::IntRect _position ; /**< @brief Attribute : the position of the object . */
    /* position.left = x, position.top = y, position.height = décalage en hauteur, position.width = décalage en largeur */
} ;

#endif // DISPLAYMENU_HPP_INCLUDED
