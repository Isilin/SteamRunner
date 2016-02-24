#ifndef DISPLAYBACKGROUND_HPP_INCLUDED
#define DISPLAYBACKGROUND_HPP_INCLUDED

/**
 * @file     DisplayBackground.hpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Declaration of class DisplayBackground.
 */

#include "Display.hpp"

/**
  * @class DisplayBackground DisplayBackground.hpp DisplayBackground
  * @brief The background's display class.
  */
class DisplayBackground : public Display
{
public :
    DisplayBackground(const std::string backgroundPath) ; /** @fn DisplayBackground(const std::string backgroundPath)
                                                            * @brief Constructor with just a background.
                                                            * @param [in] backgroundPath - Path of the backgroud image. */

    DisplayBackground(const std::string backgroundPath,
                      const std::string foregroundPath,
                      const sf::Color layer,
                      const uint16 nbClips = 1,
                      const sf::IntRect clip = sf::IntRect(0, 0, 0, 0)) ; /** @fn DisplayBackground(const std::string backgroundPath,
                                                                            *                       const std::string foregroundPath,
                                                                            *                       const sf::Color layer,
                                                                            *                       const uint16 nbClips = 1,
                                                                            *                       const sf::IntRect clip = sf::IntRect(0, 0, 0, 0))
                                                                            * @brief Constructor with a background and a foreground.
                                                                            * @param [in] backgroundPath - Path of the backgroud image.
                                                                            * @param [in] foregroundPath - Path of the foregroud image.
                                                                            * @param [in] layer - Color that shall be in transparence.
                                                                            * @param [in] nbClips - Number of clips.
                                                                            * @param [in] clip - Size of one clip. */

    virtual ~DisplayBackground() ; /** @fn ~DisplayBackground()
                                     * @brief Destructor. */

private :
} ;

#endif // DISPLAYBACKGROUND_HPP_INCLUDED
