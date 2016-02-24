#ifndef EFFECT_HPP_INCLUDED
#define EFFECT_HPP_INCLUDED

/**
 * @file     Effect.hpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Declaration of class Effect.
 */

#include <string>
class Rush;
class Mob ;
class Player ;

/**
 * @class Effect Effect.hpp Effect
 * @brief A value and a type of one of the effects of an action.
 */
class Effect
{
private :
    int _value ; /**< @brief Attribute : the value of the effect. */
    int _perLevel ; /**< @brief Attribute : the increase amount of the _value attribute of Effect per level of this effect. */
    std::string _typeEffect ; /**< @brief Attribute : the type of the effect. */

public :

    Effect(const int value, const int perLevel, const std::string typeEffect,
           const unsigned short int level) ; /** @fn Effect(const int value, const int perLevel, const std::string typeEffect)
                                                    * @brief Constructor.
                                                    * @param [in] value - The value of the effect.
                                                    * @param [in] perLevel - The increase amount of the _value attribute of Effect per level of this effect.
                                                    * @param [in] type - The type of the effect.
                                                    * @param [in] level - The current level of the effect (difficulty if it's an effect of a mob, the level of the part if it's an effect of a player). */

    ~Effect() ; /** @fn ~Effect()
                  * @brief Destructor. */

    void DoEffect(Player& player, Mob& enemy, const bool mobTurn=false) ; /** @fn  void DoEffect(Player& player, Mob& enemy, const bool mobTurn=false)
                                                                            * @brief Do an effect.
                                                                            * @param [in-out] player - The entity which do the effect.
                                                                            * @param [in-out] enemy - The enemy entity during these effect.
                                                                            * @param [in] mobTurn - true if it's during the turn of a mob, false otherwise and per default. */

    bool DoEffect(Player& player, Rush& rush) ; /** @fn bool DoEffect(Player& player, Rush& rush)
                                                  * @brief Do an effect.
                                                  * @param [in-out] player - The entity which do the effect.
                                                  * @param [in-out] rush - The current rush. */

    void DoEffectDelayed(Player& player, Mob& enemy, const bool mobTurn=false) ; /** @fn  void DoEffectDelayed(Player& player, Mob& enemy, const bool mobTurn=false)
                                                                                   * @brief Do an effect of a delayed action.
                                                                                   * @param [in-out] player - The entity which do the effect.
                                                                                   * @param [in-out] enemy - The enemy entity during these effect.
                                                                                   * @param [in] mobTurn - true if it's during the turn of a mob, false otherwise and per default. */

    void CheckEffect(Player& player, const bool forReloadPart) ; /** @fn  void CheckEffect(Player& player, const bool forReloadPart)
                                                                   * @brief Check the effect of an action of a part of a player.
                                                                   * @param [in] player - The player.
                                                                   * @param [in] forReloadPart - true if the check of the part is for a reload part, false otherwise and per default. */

    void CheckEffect(Mob& mob, const unsigned short int difficulty) ; /** @fn  void CheckEffect(Player& player, const bool forReloadPart)
                                                                        * @brief Check the effect of an action of a part of a mob.
                                                                        * @param [in] mob - The mob.
                                                                        * @param [in] difficulty - The current difficulty. */
} ;

#endif // EFFECT_HPP_INCLUDED
