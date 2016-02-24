#ifndef DISPLAYTEXT_HPP_INCLUDED
#define DISPLAYTEXT_HPP_INCLUDED

/**
 * @file     DisplayText.hpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Declaration of class DisplayText.
 */

#include "Display.hpp"

/**
  * @class DisplayText DisplayText.hpp DisplayText
  * @brief The text's display class.
  */
class DisplayText : public Display
{
public :
    DisplayText(const std::string text,
                const sf::Vector2f sizeBox,
                const std::string pathFont,
                const uint16 fontSize,
                const bool splitted,
                const bool moved,
                const sf::Vector2f position,
                const sf::Color fontColor = sf::Color::Black,
                const std::string pathBox = "") ; /** @fn DisplayText(const std::string text,
                                                    *                 const sf::Vector2f sizeBox,
                                                    *                 const std::string pathFont,
                                                    *                 const uint16 fontSize,
                                                    *                 const bool splitted,
                                                    *                 const bool moved,
                                                    *                 const sf::Vector2f position,
                                                    *                 const sf::Color fontColor = sf::Color::Black,
                                                    *                 const std::string pathBox = "")
                                                    * @brief Constructor.
                                                    * @param [in] text - The text.
                                                    * @param [in] sizeBox - Size of the object's box.
                                                    * @param [in] pathFont - Path of the font of text.
                                                    * @param [in] fontSize - The font size of text.
                                                    * @param [in] splitted - If the text have to be splitted.
                                                    * @param [in] moved - If it have to be moved because of the size of screen.
                                                    * @param [in] position - Position of the object.
                                                    * @param [in] fontColor - The font color of text.
                                                    * @param [in] pathBox - Path of the box's background. */

    ~DisplayText() ; /** @fn ~DisplayText()
                       * @brief Destructor. */

    virtual void Refresh() ; /** @fn void Refresh()
                               * @brief Refresh texture of the display object. */

private :
} ;

#endif // DISPLAYTEXT_HPP_INCLUDED
