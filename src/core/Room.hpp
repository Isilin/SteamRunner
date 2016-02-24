#ifndef ROOM_HPP_INCLUDED
#define ROOM_HPP_INCLUDED

/**
 * @file     Room.hpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Declaration of class Room.
 */

#include <string>
#include <vector>
#include "Effect.hpp"
#include "Mob.hpp"
class Rush;

/**
 * @class Room Room.hpp Room
 * @brief Mother class of Discovery and Battle.
 */
class Room
{
private :
    std::string _biome ; /**< @brief Attribute : the biome ("Jungle", "Mine", "Desert") of the room. */
    std::string _description ; /**< @brief Attribute : description of the room. */
    std::string _typeBackground; /**< @brief Attribute : the type of the background of the room. */
    Rush& _rush ; /**< @brief Attribute : the rush. */
    Mob* _enemy ; /**< @brief Attribute : the current enemy. */
    bool _chosen ; /**< @brief Attribute : false if the effect is done automatically, true otherwise. */
    std::vector<Effect> _effects ; /**< @brief Attribute : effects of the room. */

    void AddEffect(const int value, const int perLevel,
                   const std::string type, const unsigned short int difficulty) ; /** @fn void AddEffect(const int value, const int perLevel, const std::string type, const unsigned short int difficulty)
                                                                                    * @brief Add an effect to the room.
                                                                                    * @param [in] value - The value of the effect.
                                                                                    * @param [in] perLevel - The increase amount of the _value attribute of Effect per level of this effect.
                                                                                    * @param [in] type - The type of the effect.
                                                                                    * @param [in] difficulty - The current difficulty of the rush. */


public :
    Room (Rush& rush) ; /** @fn Room::Room()
                          * @brief Constructor.
                          * @param [in] rush - a Rush class pointer. */

    ~Room() ; /** @fn Room::~Room()
                * @brief Destructor. */

    inline void SetBiome(std::string value) {_biome = value ;} ; /** @fn void SetBiome(std::string value)
                                                                   * @brief Mutator of _biome attribute.
                                                                   * @param [in] value - The value to be assigned. */

    inline Mob* GetEnemy() {return _enemy ;} ; /** @fn Mob* GetEnemy() {return _enemy ;}
                                                 * @brief Accessors of _enemy attribute.
                                                 * @return The current enemy. */

    void StartBattle() ; /** @fn void StartBattle()
                           * @brief Start a battle. */

    void ClearRoom() ; /** @fn void ClearRoom()
                         * @brief Clear the room. */

    void NewEnemy() ; /** @fn void NewEnemy()
                        * @brief Create a new enemy. */

    void NewDiscovery(const std::string type) ; /** @fn void NewDiscovery(const std::string type)
                                                  * @brief Create a new random event for the room.
                                                  * @param [in] type - Type of the event : "building", "special", "discovery". */

    void DoEffects() ; /** @fn void DoEffects()
                         * @brief Do the effects of the room. */

    void EndTurn() ; /** @fn void EndTurn()
                       * @brief End turn of the player and do the enemy turn. */

    void EndBattle() ; /** @fn void EndBattle()
                         * @brief End the battle. */

    void EnterInRoom() ; /** @fn void EnterInRoom()
                           * @brief Enter in the room. */
} ;

#endif // ROOM_HPP_INCLUDED
