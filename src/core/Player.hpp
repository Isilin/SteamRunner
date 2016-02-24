#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

/**
 * @file     Player.hpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Declaration of class Player.
 */

#include "Entity.hpp"
#include <vector>
#include <string>
class Mob ;

/**
 * @class Player Player.hpp Player
 * @brief Class for the player.
 */
class Player : public Entity
{
private :
    int _pressure ; /**< @brief Attribute : the current pressure of the player. */
    int _maxPressure ; /**< @brief Attribute : the maxPressure of the player. */
    short int _initialPressure ; /**< @brief Attribute : the initial pressure of the player. */
    short int _pressurePerTurn ; /**< @brief Attribute : the pressure per turn of the player. */
    int _steam ; /**< @brief Attribute : the current steam of the player. */
    int _convertionRate ; /**< @brief Attribute : the conversion rate of the entity. */
    bool _enteringInBuilding ; /**< @brief Attribute : true if the player is entering in a building, false otherwise. */
    std::string _partActive ; /**< @brief Attribute : the current active part (doing its effects). */

    void DoTmpEffect(Mob& enemy) ; /** @fn void DoTmpEffect(Mob& enemy)
                                     * @brief Do the temporary effects on the player.
                                     * @param [in] enemy - The enemy of the player. */

    void DoStartTurnAction(Mob& enemy) ; /** @fn void DoStartTurnAction(Mob& enemy)
                                           * @brief Do actions at the start of a turn during a battle.
                                           * @param [in] enemy - The enemy of the player. */

    void DoEndTurnAction(Mob& enemy) ; /** @fn void DoEndTurnAction(Mob& enemy)
                                         * @brief Do actions at the end of a turn during a battle.
                                         * @param [in] enemy - The enemy of the player.*/
public :
    Player() ; /** @fn Player()
                 * @brief Constructor.*/

    virtual ~Player() ; /** @fn Player::~Player()
                          * @brief Destructor. */

    inline const int GetPressure() const {return _pressure ;} ; /** @fn const int GetPressure()
                                                                  * @brief Accessors of _pressure attribute.
                                                                  * @return The current pressure of the player. */

    inline const int GetSteam() const {return _steam ;} ; /** @fn const int GetSteam()
                                                                  * @brief Accessors of _steam attribute.
                                                                  * @return The current steam of the player. */

    inline const int GetMaxPressure() const {return _maxPressure ;} ; /** @fn const int GetMaxPressure()
                                                                  * @brief Accessors of _maxPressure attribute.
                                                                  * @return The max pressure of the player. */

    inline const short int GetPressurePerTurn() const {return _pressurePerTurn ;} ; /** @fn const short int GetPressurePerTurn()
                                                                                      * @brief Accessors of _pressurePerTurn attribute.
                                                                                      * @return The current pressure per turn of the player. */

    inline const int GetConvertionRate() const {return _convertionRate ;} ; /** @fn const int GetConvertionRate()
                                                                              * @brief Accessors of _convertionRate attribute.
                                                                              * @return The current convertion rate of the player. */

    inline const bool GetEnteringInBuilding() const {return _enteringInBuilding ;} ; /** @fn const bool GetEnteringInBuilding()
                                                                                       * @brief Accessors of _direction attribute.
                                                                                       * @return true if the player is entering in a building, false otherwise. */

    inline const std::string GetActivePart() const {return _partActive ;} ; /** @fn const std::string GetActivePart()
                                                                                       * @brief Accessors of _partActive attribute.
                                                                                       * @return The current active part (doing its effects). */


    inline void SetEnteringInBuilding(const bool value) {_enteringInBuilding = value ;} ; /** @fn void SetEnteringInBuilding(const bool value)
                                                                                            * @brief Accessors of _enteringInBuilding attribute.
                                                                                            * @param [in] value - The value to be assigned. */


    void AddPressurePerTurn(const short int value, const bool checkPart=false) ; /** @fn void AddPressurePerTurn(const short int value, const bool checkPart=false)
                                                                                   * @brief Add value passed in parameter at _pressurePerTurn attribute.
                                                                                   * @param [in] value - The value to be added. */

    void AddSteam(const int value, const bool checkPart=false) ; /** @fn void AddSteam(const int value, const bool checkPart=false)
                                                                   * @brief Add value passed in parameter at _steam attribute.
                                                                   * @param [in] value - The value to be added.
                                                                   * @param [in] checkPart - true if it's during a check of a part, false otherwise and per default. */

    void AddPressure(int value, const bool checkPart=false) ; /** @fn void AddPressure(int value, const bool checkPart=false) ;
                                                                * @brief Add value passed in parameter at _pressure attribute.
                                                                * @param [in] value - The value to be added.
                                                                * @param [in] checkPart - true if it's during a check of a part, false otherwise and per default. */

    void SubPressure(const int value) ; /** @fn void SubPressure(const int value)
                                          * @brief Subtract value passed in parameter at _pressure attribute.
                                          * @param [in] value - The value to be subtract. */

    void StartBattle() ; /** @fn void StartBattle()
                           * @brief Start a battle. */

    void EndBattle() ; /** @fn void EndBattle()
                         * @brief End a battle. */

    void StartTurn(Mob& enemy) ; /** @fn void StartTurn(Mob& enemy)
                                   * @brief Start a turn during a battle.
                                   * @param [in] enemy - The enemy of the player. */

    virtual void MoveRight(Mob& enemy) ; /** @fn void MoveRight(Mob& enemy)
                                           * @brief The player move the right during a battle.
                                           * @param [in] enemy - The enemy of the player. */

    virtual void MoveLeft(Mob& enemy) ; /** @fn void MoveLeft(Mob& enemy)
                                          * @brief The player move the left during a battle.
                                          * @param [in] enemy - The enemy of the player. */

    virtual void MoveLeftx2(Mob& enemy) ; /** @fn void MoveLeftx2(Mob& enemy)
                                            * @brief The player move twice to the left during a battle, ignoring an eventual obstacle.
                                            * @param [in] enemy - The enemy of the player. */

    virtual void MoveRightx2(Mob& enemy) ; /** @fn void MoveRightx2(Mob& enemy)
                                             * @brief The player move twice to the right during a battle, ignoring an eventual obstacle.
                                             * @param [in] enemy - The enemy of the player. */

    virtual void MoveToEnemy(Mob& enemy, const int value) ; /** @fn void MoveToEnemy(Mob& enemy, const int value)
                                                              * @brief The player move to his enemy during a battle.
                                                              * @param [in] enemy - The enemy of the player.
                                                              * @param [in] value - The value of the movement. */

    void Reroll(std::string typePart) ; /** @fn void Reroll(std::string typePart)
                                          * @brief Reroll a part of the player, which the type is passed in parameter.
                                          * @param [in] typePart - The type of the part to be reroll. */

    void DoAction(const std::string part, const std::string direction, Mob& enemy) ; /** @fn void DoAction(const std::string part, const std::string direction, Mob& enemy)
                                                                                       * @brief Do the action, which the type of the part and the direction are passed in parameter.
                                                                                       * @param [in] part - The type of the part.
                                                                                       * @param [in] direction - The direction of the action.
                                                                                       * @param [in] enemy - The enemy of the player. */

    void ProcHead(std::string type, Mob& enemy) ; /** @fn void ProcHead(std::string type, Mob& enemy)
                                                    * @brief Do some effects depend of the type of the proc (programmed random occurrence).
                                                    * @param [in] type - The type of the proc.
                                                    * @param [in] enemy - The enemy of the player. */

} ;

#endif // PLAYER_HPP_INCLUDED
