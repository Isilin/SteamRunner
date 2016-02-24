#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

/**
 * @file     Game.hpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Declaration of class Game.
 */

#include "GraphicEngine.hpp"
#include "CoreEngine.hpp"
#include "SoundEngine.hpp"

/**
 * @class Game Game.hpp Game
 * @brief The game.
 */
class Game
{
public :
    Game() ; /** @fn Game()
               * @brief Constructor. */

    ~Game() ; /** @fn ~Game() @brief Destructor. */

    inline const bool IsRunning() const{ return _running ; } ; /** @fn bool IsRunning() const
                                                                 * @brief Check if game is running or not. */

    void Run() ; /** @fn void Run()
                   * @brief Loop of the game. */

    inline void Stop(){ _running = false ; } ; /** @fn void Stop()
                                                 * @brief Stop the game. */

private :
    GraphicEngine* _graphicEngine ; /**< @brief Attribute : the instance of graphicEngine . */
    CoreEngine* _coreEngine ; /**< @brief Attribute : the instance of coreEngine . */
    SoundEngine* _soundEngine ; /**< @brief Attribute : the instance of soundEngine . */
    bool _running ; /**< @brief Attribute : it indicates the status of game . */
} ;

#endif // GAME_HPP_INCLUDED
