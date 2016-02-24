#ifndef ENTITY_HPP_INCLUDED
#define ENTITY_HPP_INCLUDED

/**
 * @file     Entity.hpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Declaration of class Entity.
 */

#include <vector>
#include <string>
#include "Part.hpp"
#include "Action.hpp"
#include "Effect.hpp"
class Player ;
class Mob ;

/**
 * @class Entity Entity.hpp Entity
 * @brief Abstract mother class of Player and Mob.
 */
class Entity
{
protected :
    int _integrity ; /**< @brief Attribute : the current integrity of the entity. */
    int _maxIntegrity ; /**< @brief Attribute : the maximum integrity of the entity. */
    short int _armor ; /**< @brief Attribute : the current armor of the entity. */
    std::string _typeEntity ; /**< @brief Attribute : the type ("Mob", "Player") of the entity. */
    short int _position ; /**< @brief Attribute : the current position of the entity, for the battle. */
    unsigned short int _direction ; /**< @brief Attribute : the current direction (0 to the left, 1 to the right) of the entity, for the battle. */
    std::vector<Part> _parts ; /**< @brief Attribute : the parts of the entity. */

    bool _immobilize ; /**< @brief Attribute : true if the entity is immoblize, false otherwise. */

    std::vector<Effect> _tmpEffects ; /**< @brief Attribute : the temporary effects on the entity. */

    bool _delayedAction ; /**< @brief Attribute : true if the entity as undertaking an delayed action, false otherwise. */
    std::vector<Action*> _delayedActions ; /**< @brief Attribute : The list of delayed actions. */

    void SendPositionToGraphic() ; /** @fn void SendPositionToGraphic()
                                     * @brief Send the current position of the entity to graphic engine. */


public :
    Entity() ; /** @fn Entity::Entity()
                 * @brief Constructor. */

    virtual ~Entity() ; /** @fn Entity::~Entity()
                          * @brief Destructor. */

    inline const short int GetPosition() const {return _position ;} ; /** @fn const short int GetPosition()
                                                                        * @brief Accessors of _position attribute.
                                                                        * @return The current position of the entity. */

    inline const unsigned short int GetDirection() const {return _direction ;} ; /** @fn const unsigned short int GetDirection()
                                                                                   * @brief Accessors of _direction attribute.
                                                                                   * @return The current direction of the entity. */

    inline const int GetIntegrity() const {return _integrity ;} ; /** @fn int GetIntegrity()
                                                                    * @brief Accessors of _integrity attribute.
                                                                    * @return The current integrity of the entity. */

    inline const int GetMaxIntegrity() const {return _maxIntegrity ;} ; /** @fn int GetMaxIntegrity()
                                                                    * @brief Accessors of _maxIntegrity attribute.
                                                                    * @return The max integrity of the entity. */

    inline const int GetArmor() const {return _armor ;} ; /** @fn int GetArmor()
                                                                * @brief Accessors of _armor attribute.
                                                                * @return The current armor of the entity. */

    const Part& GetPart(const unsigned short int i) const ; /** @fn const Part& GetPart(const unsigned short int i)
                                                              * @brief Accessor of _parts[i] attribute.
                                                              * @return A part.
                                                              * @param [in] i - Index of array. */

    inline const bool GetDelayedAction() const {return _delayedAction ;} ; /** @fn const bool GetDelayedAction()
                                                                             * @brief Accessors of _delayedAction attribute.
                                                                             * @return The current delayed action of the entity. */

    inline void SetDelayedAction(const bool value) {_delayedAction = value ;}; /** @fn void SetDelayedAction(const bool value)
                                                                                 * @brief Mutator of _delayedAction attribute.
                                                                                 * @param [in] value - The value to be assigned. */

    void AddDelayedAction(Action* action) ; /** @fn void AddDelayedAction(Action* value)
                                             * @brief Add a delayed actions to the entity.
                                             * @param [in] action - The delayed action. */

    void SetPosition(const short int value) ; /** @fn void SetPosition(const short int value)
                                                * @brief Mutator of _position attribute.
                                                * @param [in] value - The value to be assigned. */

    inline void SetImmobilize(const bool value) {_immobilize = value ;} ; /** @fn void SetImmobilize(constbool value)
                                                                           * @brief Mutator of _immobilize attribute.
                                                                           * @param [in] value - The value to be assigned. */

    void AddIntegrity(const int value, const bool checkPart=false) ; /** @fn void Entity::AddIntegrity(const int value)
                                                                       * @brief Add value passed in parameter to integrity attribute.
                                                                       * @param [in] value - The value to be added. */

    void AddMaxIntegrity(const int value) ; /** @fn void AddMaxIntegrity(const int value)
                                              * @brief Add value passed in parameter to maxIntegrity attribute.
                                              * @param [in] value - The value to be added. */

    void AddArmor(const short int value, const bool checkPart=false) ; /** @fn void Entity::AddArmor(const short int value)
                                                                         * @brief Add value passed in parameter to armor attribute.
                                                                         * @param [in] value - The value to be added. */

    void AddTmpEffect(const int value, const std::string typeEffect) ; /** @fn void AddTmpEffect(const int value, const int perLEvel, const std::string typeEffect)
                                                                         * @brief Mutator of _tmpArmorModifier attribute.
                                                                         * @param [in] value - The value to be assigned.
                                                                         * @param [in] typeEffect - The type of the effect. */

    void AddPart(const std::string type, Player& player) ; /** @fn void AddPart(const std::string type, Player& player)
                                                             * @brief Add a part to an entity of type "Player".
                                                             * @param [in] type - The type of the part to be add.
                                                             * @param [in] player - The player. */

    void AddPart(const std::string type, Mob& mob, std::string biome, const unsigned short int difficulty) ; /** @fn void AddPart(const std::string type, Mob& mob, std::string biome, const unsigned short int difficulty)
                                                                                                               * @brief Add a part to an entity of type "Mob".
                                                                                                               * @param [in] type - The type of the part to be add.
                                                                                                               * @param [in] mob - The mob.
                                                                                                               * @param [in] difficulty - The current difficulty. */

    void TakeDamage(const unsigned int damage, const bool armorIgnored=false) ; /** @fn void Entity::TakeDamage(const unsigned int damage, const bool armorIgnored)
                                                                                  * @brief Entity takes an amount of damage.
                                                                                  * @param [in] damage - The amount of damage done to the entity.
                                                                                  * @param [in] armorIgnored - true if armor is ignored, false otherwise and per default. */


    virtual void MoveLeft(Entity& enemy) ; /** @fn void MoveLeft(Entity& enemy)
                                             * @brief The entity move to the left during a battle.
                                             * @param [in] enemy - The enemy of the entity. */

    virtual void MoveRight(Entity& enemy) ; /** @fn void MoveRight(Entity& enemy)
                                              * @brief The entity move to the right during a battle.
                                              * @param [in] enemy - The enemy of the entity. */

    virtual void MoveLeftx2(Entity& enemy) ; /** @fn void MoveLeftx2(Entity& enemy)
                                               * @brief The entity move twice to the left during a battle, ignoring an eventual obstacle.
                                               * @param [in] enemy - The enemy of the entity. */

    virtual void MoveRightx2(Entity& enemy) ; /** @fn void MoveRightx2(Entity& enemy)
                                                * @brief The entity move twice to the right during a battle, ignoring an eventual obstacle.
                                                * @param [in] enemy - The enemy of the entity. */

    virtual void MoveToEnemy(Entity& enemy, const int value) ; /** @fn void MoveToEnemy(Entity& enemy, const int value
                                                                 * @brief The entity move to his enemy during a battle.
                                                                 * @param [in] enemy - The enemy of the entity.
                                                                 * @param [in] value - The value of the movement. */

    void DisplayEntity(std::string typeMessage) ; /** @fn void DisplayEntity(std::string typeMessage)
                                                    * @brief Send message to graphic engine to diplay the entity.
                                                    * @param [in] typeMessage - The type of display : "start" for the creation screen if the entity is a player, "rush" to display the entity during a rush. */

    void Rotate() ; /** @fn void Rotate()
                      * @brief The entity rotate. */
} ;

#endif // ENTITY_HPP_INCLUDED
