#ifndef SOUNDENGINE_HPP_INCLUDED
#define SOUNDENGINE_HPP_INCLUDED

#include "SFML/Audio.hpp"
#include "Engine.hpp"
#include <vector>
#include <string>

class SoundEngine : public Engine
{
public:
    SoundEngine(Game* parent) ; /** @fn SoundEngine(Game* parent)
                                  * @brief Constructor.
                                  * @param [in] parent - A game class pointer. */

    ~SoundEngine() ; /** @fn ~SoundEngine()
                       * @brief Destructor. */


    void ChangeMusic(std::string typeMusic) ; /** @fn void ChangeMusic(std::string typeMusic)
                                                            * @brief Change the current music which the type is passed in parameter.
                                                            * @param [in] typeMusic - The type of the music which has to be change. */

    void PlayMusicBattle() ; /** @fn void PlayMusicBattle()
                               * @brief Start to play a random music of type battle. */

    void PlayMusicRush() ; /** @fn void PlayMusicRush()
                             * @brief Start to play a random music of type rush. */

    void PlayMusicMenu() ; /** @fn void PlayMusicMenu()
                             * @brief Start to play a random music of type menu. */

    void PlaySound(std::string typeSound) ; /** @fn void PlaySound(std::string typeSound)
                                              * @brief Play a sound which the type is passed in parameter.
                                              * @param [in] typeSound - the type of the sound. */

    void PlayClick() ; /** @fn void PlayClick()
                         * @brief Play the click sound. */


    virtual void Frame() ; /** @fn void Frame() @brief Frame of SoundEngine. */

    virtual void ProcessEvent(const EngineEvent* event) ; /** @fn void ProcessEvent(const EngineEvent* event)
                                                            * @brief Process an event.
                                                            * @param [in] event - the event to be process. */

private:
    sf::Clock _timerBattleMusic ; /**< @brief Attribute : a timer to change battle music. */
    sf::Clock _timerRushMusic ; /**< @brief Attribute : a timer to change rush music. */
    sf::SoundBuffer _clickBuffer ; /**< @brief Attribute : the buffer for the click sound. */
    sf::SoundBuffer _effectBuffer ; /**< @brief Attribute : the buffer for the others type of sound. */
    sf::Music _battleMusic ; /**< @brief Attribute : the music of the rush. */
    sf::Music _rushMusic ; /**< @brief Attribute : the music of the battle. */
    sf::Sound _effect ; /**< @brief Attribute : the sound of play from the _effectBuffer. */
    sf::Sound _click ; /**< @brief Attribute : the sound of play from the _clickBuffer. */
    sf::Time _playedTime ; /**< @brief Attribute : a time for some operation. */
    float _volumeMusic ; /**< @brief Attribute : the current volume of the music. */
    float _volumeSound ; /**< @brief Attribute : the current volume of sound. */
    std::vector<int> _playedBattleMusic ; /**< @brief Attribute : a way to save played battle music to various the rotate. */
    std::vector<int> _playedRushMusic ; /**< @brief Attribute : a way to save played rush music to various the rotate. */
    bool _onMenu ; /**< @brief Attribute : a way to know if we are on the menu or not.. */

    bool In(std::string typeVector, int i) ; /** @fn bool In(std::string typeVector, int i)
                                               * @brief Check if the ieme music have been already played, type of the music is passed in parameter.
                                               * @param [in] typeVector - the type of the music, so of the vector.
                                               * @param [in] i - the number of the music.
                                               * @return true if the ieme music have been already played, false otherwise.. */
};

#endif // SOUNDENGINE_HPP_INCLUDED
