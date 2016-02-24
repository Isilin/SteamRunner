#ifndef DISPLAYSPRITE_HPP_INCLUDED
#define DISPLAYSPRITE_HPP_INCLUDED

/**
 * @file     DisplaySprite.hpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Declaration of class DisplaySprite.
 */

#include <vector>
#include <string>

#include "Display.hpp"

/**
  * @class DisplaySprite DisplaySprite.hpp DisplaySprite
  * @brief The sprite's display class.
  */
class DisplaySprite : public Display
{
public :
    DisplaySprite(const std::string pathSprite,
                  const sf::Color layer,
                  const uint16 nbClips,
                  const sf::IntRect sizeClip,
                  const sf::Vector2f position) ; /** @fn DisplaySprite(const std::string pathSprite,
                                                   *                 const sf::Color layer,
                                                   *                 const uint16 nbClips,
                                                   *                 const sf::IntRect sizeClip,
                                                   *                 const sf::Vector2f position)
                                                   * @brief Constructor.
                                                   * @param [in] pathSprite - Path of the image.
                                                   * @param [in] layer - Color that shall be in transparence.
                                                   * @param [in] nbClips - Number of clips.
                                                   * @param [in] sizeClip - Size of one clip.
                                                   * @param [in] position - Position of the sprite. */

    ~DisplaySprite() ; /** @fn ~DisplaySprite()
                         * @brief Destructor. */

    virtual void Refresh() ; /** @fn void Refresh()
                               * @brief Refresh texture of the display object. */

private :
} ;

#endif // DISPLAYSPRITE_HPP_INCLUDED
