#ifndef ACTION_HPP_INCLUDED
#define ACTION_HPP_INCLUDED

/**
 * @file     Action.hpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Declaration of class Action.
 */

#include <vector>
#include <string>
#include "Effect.hpp"
class Mob ;
class Player ;

 /**
 * @class Action Action.hpp Action
 * @brief An action of a part with a list of effects.
 */
class Action
{
private :
    short int _pressureCost ; /**< @brief Attribute : the pressure cost of the action. */
    std::string _direction ; /**< @brief Attribute : the direction of the action. */
    std::vector<Effect> _effects ; /**< @brief Attribute : the effects of the action. */
    short int _minDistance ; /**< @brief Attribute : the minimum distance of the action. */
    short int _maxDistance ; /**< @brief Attribute : the maximum distance of the action. */

    void AddEffect(const int value, const int perLevel, const std::string typeEffect,
                   const unsigned short int level) ; /** @fn void AddEffect(const int value, const int perLevel, const std::string typeEffect)
                                                            * @brief Add an effect to the action.
                                                            * @param [in] value - The value of the effect.
                                                            * @param [in] perLevel - The increase amount of the _value attribute of Effect per level of this effect.
                                                            * @param [in] type - The type of the effect.
                                                            * @param [in] level - The current level of the effect (difficulty if it's an effect of a mob, the level of the part if it's an effect of a player. */

public :

    Action(const unsigned short int pressureCost, const short int minDistance,
           const short int maxDistance, std::string infoEffect, const std::string direction,
           const unsigned short int level) ; /** @fn Action(const unsigned short int pressureCost, const short int minDistance,
                                                    *                     const short int maxDistance, std::string infoEffect, const std::string direction,
                                                    *                     const unsigned short int difficulty) ;)
                                                    * @brief Constructor.
                                                    * @param [in] pressureCost - The pressure cost of the action.
                                                    * @param [in] minDistance - The minimum distance of the action.
                                                    * @param [in] maxDistance - The maximum distance of the action.
                                                    * @param [in] infoEffects - The string containing informations on the effects of the action.
                                                    * @param [in] direction - The direction of the action.
                                                    * @param [in] lvel - The current level of the effect (difficulty if it's an effect of a mob, the level of the part if it's an effect of a player. */

    ~Action() ; /** @fn ~Action()
                  * @brief Destructor. */

    inline const std::string GetDirection() const {return _direction ;} ; /** @fn const std::string GetDirection()
                                                                            * @brief Accessors of _direction attribute.
                                                                            * @return The direction of the action. */

    void DoAction(Player& player, Mob& enemy, const bool mobTurn=false) ; /** @fn void DoAction(Player& player, Mob& enemy, const bool mobTurn=false)
                                                                              * @brief Do the action.
                                                                              * @param [in] player - The player.
                                                                              * @param [in] enemy - The enemy of the player.
                                                                              * @param [in] mobTurn - true if it's during the turn of a mob, false otherwise and per default. */

    void DoActionDelayed(Player& player, Mob& enemy, const bool mobTurn=false) ; /** @fn void DoActionDelayed(Player& player, Mob& enemy, const bool mobTurn=false)
                                                                                   * @brief Do a delayed action.
                                                                                   * @param [in] player - The player.
                                                                                   * @param [in] enemy - The enemy of the player.
                                                                                   * @param [in] mobTurn - true if it's during the turn of a mob, false otherwise and per default. */

    void CheckAction(Player& player, const bool forReloadPart) ; /** @fn void CheckAction(Player& player, const bool forReloadPart)
                                                                   * @brief Check the action of a part of a player.
                                                                   * @param [in] player - The player.
                                                                   * @param [in] forReloadPart - true if the check of the part is for a reload part, false otherwise and per default. */

    void CheckAction(Mob& mob, const unsigned short int difficulty) ; /** @fn void CheckAction(Mob& mob, const unsigned short int difficulty)
                                                                              * @brief Check the action of a part of a mob.
                                                                              * @param [in] mob - The mob.
                                                                              * @param [in] difficulty - The current difficulty. */

    void MoveToDoAction(Player& enemy, Mob& Mob) const ; /** @fn void MoveToDoAction(Player& enemy, Mob& Mob, string type)
                                                                        * @brief The mob move to his enemy to do the actions.
                                                                        * @param [in] enemy - The enemy of the mob.
                                                                        * @param [in] mob - The mob. */

} ;

#endif // ACTION_HPP_INCLUDED
