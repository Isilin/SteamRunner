#ifndef PART_HPP_INCLUDED
#define PART_HPP_INCLUDED

/**
 * @file     Part.hpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Declaration of class Part.
 */

#include <vector>
#include <string>
#include "Action.hpp"
class Player ;
class Mob ;

/**
 * @class Part Part.hpp Part
 * @brief A Part of an entity, with a list of actions.
 */
class Part
{
private :
    std::string _type ; /**< @brief Attribute : the type of the part. */
    std::string _name ; /**< @brief Attribute : the name of the part. */
    std::string _description ; /**< @brief Attribute : the description of the part. */
    std::vector<Action> _actions ; /**< @brief Attribute : actions of the part. */

    void AddAction(const short int pressureCost, const short int minDistance,
                   const short int maxDistance, const std::string infoEffects,
                   const std::string direction, const unsigned short int level) ; /** @fn void AddAction(const short int pressureCost, const short int minDistance,
                                                                                         *                     const short int maxDistance, const std::string infoEffects,
                                                                                         *                     const std::string direction, const unsigned short int difficulty) ;
                                                                                         * @brief Add an action to the part of a mob.
                                                                                         * @param [in] pressureCost - The pressure cost of the action.
                                                                                         * @param [in] minDistance - The minimum distance of the action.
                                                                                         * @param [in] maxDistance - The maximum distance of the action.
                                                                                         * @param [in] infoEffects - The string containing informations on the effects of the action.
                                                                                         * @param [in] direction - The direction of the action.
                                                                                         * @param [in] level - The current level of the effect (difficulty if it's an effect of a mob, the level of the part if it's an effect of a player. */

    void CheckPart(Player& player,const  bool forReloadPart=false) ; /** @fn void CheckPart(Player& player,const  bool forReloadPart)
                                                                       * @brief Check a part of a player.
                                                                       * @param [in] player - The player.
                                                                       * @param [in] forReloadPart - true if the check of the part is for a reload part, false otherwise and per default. */

    void CheckPart(Mob& mob, const unsigned short int difficulty) ; /** @fn void CheckPart(Mob& mob, const unsigned short int difficulty)
                                                                      * @brief Check a part of a mob.
                                                                      * @param [in] mob - The mob.
                                                                      * @param [in] difficulty - The current difficulty. */

 public :
    Part() ; /** @fn Part()
               * @brief Constructor. */

    ~Part() ; /** @fn ~Part()
                * @brief Destructor. */

    inline const std::string GetType() const {return _type ;} ; /** @fn const std::string GetType()
                                                                  * @brief Accessors of _type attribute.
                                                                  * @return The type of the part. */

    inline const std::string GetName() const {return _name ;} ; /** @fn const std::string GetName()
                                                                  * @brief Accessors of _name attribute.
                                                                  * @return The name of the part. */
    inline const std::string GetDescription() const {return _description ;} ; /** @fn const std::string GetDescription()
                                                                                * @brief Accessors of _description attribute.
                                                                                * @return The description of the part. */

    void LoadPart(const std::string typePart, Player& player) ; /** @fn void LoadPart(const std::string typePart, Player& player)
                                                                  * @brief Load the part which the type is passed in parameter of a player.
                                                                  * @param [in] typePart - The type of the part to be load.
                                                                  * @param [in] player - The player. */

    void LoadPart(const std::string typePart, Mob& mob,
                  const std::string biome, const unsigned short int difficulty) ; /** @fn void LoadPart(const std::string typePart, Mob& mob,
                                                                                    *                   const std::string biome, const unsigned short int difficulty)
                                                                                    * @brief Load the part which the type is passed in parameter of a mob.
                                                                                    * @param [in] typePart - The type of the part to be load.
                                                                                    * @param [in] mob - The mob.
                                                                                    * @param [in] biome - The biome of the room in which the mob will be pop.
                                                                                    * @param [in] difficulty - The current difficulty. */

    void ReloadPart(Player& player) ; /** @fn void ReloadPart(Player& player)
                                        * @brief Reload the part of a player.
                                        * @param [in] player - The player. */


    void DoAction(const std::string direction,
                  Player& player, Mob& enemy, bool mobTurn=false) ; /** @fn void DoAction(const std::string direction, Player& player, Mob& enemy, bool mobTurn = false)
                                                                      * @brief Do an action which the direction is passed in parameter the  of the part.
                                                                      * @param [in] direction - The direction of the actions.
                                                                      * @param [in] player - The player.
                                                                      * @param [in] enemy - The enemy of the player.
                                                                      * @param [in] mobTurn - true if it's during the turn of a mob, false otherwise and per default. */

    void DisplayPart(std::string typeMessage) const ; /** @fn void DisplayPart(std::string typeMessage)
                                                        * @brief Send message to graphic engine to display the part.
                                                        * @param [in] typeMessage - The type of display : "start" for the creation screen if the entity is a player, "rush" to display the entity during a rush. */

    void MoveToDoAction(Player& enemy, Mob& Mob, std::string type) const ; /** @fn void MoveToDoAction(Player& enemy, Mob& Mob, string type)
                                                                             * @brief The mob move to his enemy to do the actions.
                                                                             * @param [in] enemy - The enemy of the mob.
                                                                             * @param [in] mob - The mob.
                                                                             * @param [in] type - The type of the action. */
} ;

#endif // PART_HPP_INCLUDED
