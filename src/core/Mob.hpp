#ifndef MOB_HPP_INCLUDED
#define MOB_HPP_INCLUDED

/**
 * @file     Mob.hpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Declaration of class Mob.
 */

#include "Entity.hpp"
#include <vector>
#include <string>
class Player ;

/**
 * @class Mob Mob.hpp Mob
 * @brief Class for Mobs.
 */
class Mob: public Entity
{
private :
    short int _numberOfAction ; /**< @brief Attribute : the number of action per turn during a battle. */
    short int _currentNumberOfAction ; /**< @brief Attribute : the current number of action during a battle. */

    void DoTmpEffect(Player& enemy) ; /** @fn void DoTmpEffect(Player& enemy)
                                        * @brief Do the temporary effects on the mob.
                                        * @param [in] enemy - The enemy of the mob. */

    void MoveToDoAction(Player& enemy, std::string type) ; /** @fn void MoveToDoDoAction(Player& enemy, std::string type)
                                                                                          * @brief Move to do the action, which the type is passed in parameter.
                                                                                          * @param [in] enemy - The enemy of the mob.
                                                                                          * @param [in] type - The type of the action. */

public :
    Mob(const std::string biome, unsigned short int difficulty) ; /** @fn Mob(const std::string biome, unsigned short int difficulty)
                                                                    * @brief Constructor.
                                                                    * @param [in] biome - The biome of the current room of the rush.
                                                                    * @param [in] difficulty - The current difficulty. */

    virtual ~Mob() ; /** @fn Mob::~Mob()
                       * @brief Destructor. */

    inline const short int GetAction() {return _currentNumberOfAction ;} ; /** @fn const short int GetAction()
                                                                             * @brief Accessors of _currentNumberOfActions attribute.
                                                                             * @return The current number of action of the mob. */

    void DoTurn(Player& enemy) ; /** @fn void Mob::DoTurn(Player* enemy)
                                   * @brief Mob do its turn.
                                   * @param [in] enemy - The enemy of the mob during its turn. */

    virtual void MoveRight(Player& enemy) ; /** @fn void MoveRight(Player& enemy)
                                              * @brief The mob move the right during a battle.
                                              * @param [in] enemy - The enemy of the mob. */

    virtual void MoveLeft(Player& enemy) ; /** @fn void MoveLeft(Player& enemy)
                                             * @brief The mob move the left during a battle.
                                             * @param [in] enemy - The enemy of the mob. */

    virtual void MoveLeftx2(Player& enemy) ; /** @fn void MoveLeftx2(Player& enemy)
                                               * @brief The mob move twice to the left during a battle, ignoring an eventual obstacle.
                                               * @param [in] enemy - The enemy of the mob. */

    virtual void MoveRightx2(Player& enemy) ; /** @fn void MoveRightx2(Player& enemy)
                                                * @brief The mob move twice to the right during a battle, ignoring an eventual obstacle.
                                                * @param [in] enemy - The enemy of the mob. */

    virtual void MoveToEnemy(Player& enemy, const int value) ; /** @fn void MoveToEnemy(Player& enemy, const int value)
                                                                 * @brief The mob move to his enemy during a battle.
                                                                 * @param [in] enemy - The enemy of the mob.
                                                                 * @param [in] value - The value of the movement. */

    void AddMaxAction(const short int value) ; /** @fn  void AddAction(const short int value)
                                              * @brief Add to _numberOfAction attribute the value passed in parameter.
                                              * @param [in] value - The value add to the number of action of the mob. */

    inline void SubAction() {_currentNumberOfAction-=1 ;} ; /** @fn  void SubbAction()
                                                               * @brief Subtract one to the current number of action of the mob. */

} ;

#endif // MOB_HPP_INCLUDED
