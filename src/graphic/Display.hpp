#ifndef DISPLAY_HPP_INCLUDED
#define DISPLAY_HPP_INCLUDED

/**
 * @file     Display.hpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Declaration of class Display.
 */

#include "SFML/Graphics.hpp"
#include <string>
#include <vector>

/**
  * @class Display Display.hpp Display
  * @brief The general display class.
  */
class Display
{

public :
    typedef unsigned short int uint16 ;

    /** @enum Type
      * @brief The type of object */
    enum Type{SPRITE, /**< @brief A sprite. */
              TEXT /**< @brief A text. */
             } ;

    Display() ;/** @fn Display()
                 * @brief Constructor by default. */

    Display(const std::string path,
            const sf::Vector2f position = sf::Vector2f(0,0),
            const uint16 nbClips = 1,
            const sf::IntRect clip = sf::IntRect(0, 0, 0, 0)) ; /** @fn DisplayBackground(const std::string path,
                                                                  *                       const sf::Vector2f position = sf::Vector2f(0,0),
                                                                  *                       const uint16 nbClips = 1,
                                                                  *                       const sf::IntRect clip = sf::IntRect(0, 0, 0, 0))
                                                                  * @brief Constructor without layer color.
                                                                  * @param [in] path - Path of the image.
                                                                  * @param [in] position - Position of the sprite.
                                                                  * @param [in] nbClips - Number of clips.
                                                                  * @param [in] clip - Size of one clip. */

    Display(const std::string path,
            const sf::Color layer,
            const sf::Vector2f position = sf::Vector2f(0,0),
            const uint16 nbClips = 1,
            const sf::IntRect clip = sf::IntRect(0, 0, 0, 0)) ; /** @fn Display(const std::string path,
                                                                  *             const sf::Color layer,
                                                                  *             const sf::Vector2f position = sf::Vector2f(0,0),
                                                                  *             const uint16 nbClips = 1,
                                                                  *             const sf::IntRect clip = sf::IntRect(0, 0, 0, 0))
                                                                  * @brief Constructor with layer color.
                                                                  * @param [in] path - Path of the image.
                                                                  * @param [in] layer - Color that shall be in transparence.
                                                                  * @param [in] position - Position of the sprite.
                                                                  * @param [in] nbClips - Number of clips.
                                                                  * @param [in] clip - Size of one clip. */

    Display(const sf::Vector2f position,
            const std::string text,
            const std::string pathFont = "./data/fonts/steampunk.ttf",
            const sf::Color fontColor = sf::Color(255, 255, 255),
            const uint16 fontSize = 30) ; /** @fn Display(const sf::Vector2f position,
                                            *             const std::string text,
                                            *             const std::string pathFont = "./data/fonts/steampunk.ttf",
                                            *             const sf::Color fontColor = sf::Color(255, 255, 255),
                                            *             const uint16 fontSize = 30)
                                            * @brief Constructor with just text.
                                            * @param [in] position - Position of the text.
                                            * @param [in] text - The text.
                                            * @param [in] pathFont - Font's path for the text.
                                            * @param [in] fontColor - Font's color for the text.
                                            * @param [in] fontSize - Font's size for the text. */

    virtual ~Display() ; /** @fn ~Display()
                           * @brief Destructor. */

    const bool AddSprite(const std::string path,
                         const uint16 nbClips,
                         const sf::Vector2f position = sf::Vector2f(0, 0),
                         const sf::IntRect clip = sf::IntRect(0, 0, 0, 0)) ; /** @fn AddSprite(const std::string path,
                                                                               *               const sf::Vector2f position = sf::Vector2f(0,0),
                                                                               *               const uint16 nbClips = 1,
                                                                               *               const sf::IntRect clip = sf::IntRect(0, 0, 0, 0))
                                                                               * @brief Add a sprite without layer color to an existing display.
                                                                               * @param [in] path - Path of the image.
                                                                               * @param [in] position - Position of the sprite.
                                                                               * @param [in] nbClips - Number of clips.
                                                                               * @param [in] clip - Size of one clip. */

    const bool AddSprite(const std::string path,
                         const sf::Color layer,
                         const uint16 nbClips,
                         const sf::Vector2f position = sf::Vector2f(0, 0),
                         const sf::IntRect clip = sf::IntRect(0, 0, 0, 0)) ; /** @fn AddSprite(const std::string path,
                                                                               *               const sf::Color layer,
                                                                               *               const sf::Vector2f position = sf::Vector2f(0,0),
                                                                               *               const uint16 nbClips = 1,
                                                                               *               const sf::IntRect clip = sf::IntRect(0, 0, 0, 0))
                                                                               * @brief Add a sprite with layer color to an existing display.
                                                                               * @param [in] path - Path of the image.
                                                                               * @param [in] layer - Color that shall be in transparence.
                                                                               * @param [in] position - Position of the sprite.
                                                                               * @param [in] nbClips - Number of clips.
                                                                               * @param [in] clip - Size of one clip. */

    const bool AddText(const sf::Vector2f position,
                       const std::string text,
                       const std::string pathFont = "./data/fonts/steampunk.ttf",
                       const sf::Color fontColor = sf::Color(255, 255, 255),
                       const uint16 fontSize = 30) ; /** @fn AddText(const sf::Vector2f position,
                                                       *             const std::string text,
                                                       *             const std::string pathFont = "./data/fonts/steampunk.ttf",
                                                       *             const sf::Color fontColor = sf::Color(255, 255, 255),
                                                       *             const uint16 fontSize = 30)
                                                       * @brief Add a text to an existing display.
                                                       * @param [in] position - Position of the text.
                                                       * @param [in] text - The text.
                                                       * @param [in] pathFont - Font's path for the text.
                                                       * @param [in] fontColor - Font's color for the text.
                                                       * @param [in] fontSize - Font's size for the text. */

    const bool RefreshFont(const std::string pathFont = "./data/fonts/steampunk.ttf") ; /** @fn const bool RefreshFont(const std::string pathFont = "./data/fonts/steampunk.ttf")
                                                                                          * @brief Change the font of the object.
                                                                                          * @param [in] pathFont - The path of the font. */

    const bool RefreshSprite(const std::string pathSprite,
                             const unsigned short int indiceArray,
                             const sf::Color layer) ; /** @fn const bool Display::RefreshSprite(const std::string pathSprite, const unsigned short int indiceArray,
                                                        *                                       const Color layer)
                                                        * @brief Change the sprite of the object.
                                                        * @param [in] pathSprite - The path of the sprite.
                                                        * @param [in] indiceArray - The indice of text array.
                                                        * @param [in] layer - Color that shall be in transparence. */

    inline void SetText(const uint16 indiceArray,
                        const std::string text){_strings.at(indiceArray) = text ; _texts.at(indiceArray).setString(text) ;} ;
                                                /** @fn void SetText(const uint16 indiceArray, const std::string text)
                                                  * @brief Change the text of a text object.
                                                  * @param [in] indiceArray - The indice of text array.
                                                  * @param [in] text - The new text. */

    void SetText(const uint16 indiceArray, const std::string text, const bool splitted,
                 const sf::Vector2f sizeBox, const unsigned short int fontSize) ; /** @fn void SetText(const uint16 indiceArray, const std::string text)
                                                                        * @brief Change the text of a text object.
                                                                        * @param [in] indiceArray - The indice of text array.
                                                                        * @param [in] text - The new text.
                                                                        * @param [in] splitted - If the text need to be splitted or not.
                                                                        * @param [in] sizeBox - Size of the object.
                                                                        * @param [in] fontSize - Size of the font. */

    void SetPosition(const Type type, const uint16 indiceArray, const sf::Vector2f position) ; /** @fn void SetPosition(const Type type, const uint16 indiceArray,
                                                                                                 *                      const sf::Vector2f position)
                                                                                                 * @brief Rotate an object.
                                                                                                 * @param [in] type - The type of object which need to be rotated.
                                                                                                 * @param [in] indiceArray - The indice of text array.
                                                                                                 * @param [in] position - The future position of the target. */

    void ChangeFrame(const uint16 indiceArray, const uint16 currentFrame) ; /** @fn void ChangeFrame(const uint16 indiceArray, const uint16 currentFrame)
                                                                              * @brief Load an other clip of the sprite.
                                                                              * @param [in] indiceArray - The indice of text array.
                                                                              * @param [in] position - The new current frame of the sprite. */

    void Rotate(const Type type, const uint16 indiceArray, const float angle) ; /** @fn void Rotate(const Type type, const uint16 indiceArray, const float angle)
                                                                                  * @brief Rotate an object.
                                                                                  * @param [in] type - The type of object which need to be rotated.
                                                                                  * @param [in] indiceArray - The indice of text array.
                                                                                  * @param [in] angle - The angle of rotation. */

    bool IsContained(uint16 indiceArray, int x, int y) ; /** @fn bool IsContained(uint16 indiceArray, int x, int y)
                                                           * @brief Return if point is in a box.
                                                           * @param [in] indiceArray - The indice of text array.
                                                           * @param [in] x - The X-coordinate of the mouse pointer.
                                                           * @param [in] y - The Y-coordinate of the mouse pointer. */

    inline uint16 GetNbSprites() const{ return _sprites.size() ; } ; /** @fn uint16 GetNbSprites() const
                                                                       * @brief An accessor of _sprites.size() parameter. */

    inline uint16 GetNbTexts() const{ return _texts.size() ; } ; /** @fn uint16 GetNbTexts() const
                                                                   * @brief An accessor of _texts.size() parameter. */

    inline std::string GetText(uint16 indiceArray) const{ return _texts.at(indiceArray).getString() ; } ; /** @fn std::string GetText(uint16 indiceArray) const
                                                                                                            * @brief An accessor of text parameter.
                                                                                                            * @param [in] indiceArray - The indice of text array. */

    virtual void Refresh() ; /** @fn void Refresh()
                               * @brief Refresh texture of the display object. */

    virtual void DisplayOn(sf::RenderWindow* window) const ; /** @fn void DisplayOn(sf::RenderWindow* window) const
                                                               * @brief Display the object on the window.
                                                               * @param [in] window - The target window. */

protected :

    struct Sprite
    {
        sf::Texture texture ;
        sf::Sprite sprite ;
        uint16 nbClips ;
        uint16 currentFrame ;
        sf::IntRect clip ;
    } ;

    std::vector<Sprite> _sprites ;  /**< @brief Attribute : an array of sprite objects. */
    std::vector<std::string> _strings ;  /**< @brief Attribute : an array of texts. */
    std::vector<sf::Text> _texts ; /**< @brief Attribute : an array of texts objects. */
    sf::Font _font ; /**< @brief Attribute : a font. */
} ;

#endif // DISPLAY_HPP_INCLUDED
