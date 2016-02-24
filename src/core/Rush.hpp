#ifndef RUSH_HPP_INCLUDED
#define RUSH_HPP_INCLUDED

/**
 * @file     Rush.hpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Declaration of class Rush.
 */

#include "Player.hpp"
#include "Room.hpp"

/**
 * @class Rush Rush.hpp Rush
 * @brief A player who travel across rooms.
 */
class Rush
{
private :
    unsigned short int _difficulty ; /**< @brief Attribute : the current difficulty of the rush : 0-10. */
    unsigned short int _maxDifficulty ; /**< @brief Attribute : the current maximum difficulty unlock by the gamer : 0-10. */
    unsigned short int _rerolls ; /**< @brief Attribute : the number of rerolls available during the creation of the player. */
    int _stockOre ; /**< @brief Attribute : the amount of ore available during the rush. */
    int _orePerEnemyMax ; /**< @brief Attribute : the maximum amount of ore earn when defeating an enemy. */
    int _orePerEnemyMin ; /**< @brief Attribute : the minimum amount of ore earn when defeating an enemy. */
    short int _stockVestige ; /**< @brief Attribute : the amount of vestige available during the rush. */
    short int _indiceCurrentRoom ; /**< @brief Attribute : the index of the current room of the rush. */
    bool _trueEnd ; /**< @brief Attribute : true if the end will be the true end, false otherwise. */
    bool _rushEnded ; /**< @brief Attribute : true if the rush is ended, false otherwise. */
    Room _currentRoom ; /**< @brief Attribute : the current room. */
    Player _player ; /**< @brief Attribute : the player. */

public :
    Rush() ; /** @fn Rush::Rush()
               * @brief Constructor. */

    ~Rush() ; /** @fn Rush::~Rush()
                * @brief Destructor. */

    inline const unsigned short int GetDifficulty() const {return _difficulty ;} ; /** @fn const unsigned short int GetDifficulty()
                                                                                     * @brief Accessors of _difficulty attribute.
                                                                                     * @return The current difficulty. */

    inline Player& GetPlayer() {return _player ;} ; /** @fn Player& GetPlayer()
                                                      * @brief Accessors of _player attribute.
                                                      * @return The player. */

    inline const int GetStockOre() const {return _stockOre ;} ; /** @fn const int GetStockOre()
                                                                  * @brief Accessors of _stockOre attribute.
                                                                  * @return The current stock ore. */

   inline const short int GetStockVestige() const {return _stockVestige ;} ; /** @fn const short int GetStockVestige()
                                                                               * @brief Accessors of _stockVestige attribute.
                                                                               * @return The current stock vestige. */

    inline const bool GetTrueEnd() const  {return _trueEnd ;} ; /** @fn const bool GetTrueEnd()
                                                                  * @brief Accessors of _trueEnd attribute.
                                                                  * @return Return true if the end will be the true end, false otherwise. */

    inline const unsigned short int GetReroll() const {return _rerolls ;} ; /** @fn const unsigned short int GetReroll()
                                                                              * @brief Accessors of _rerolls attribute.
                                                                              * @return The current number of reroll available. */

    inline Room& GetCurrentRoom() {return _currentRoom ;} ; /** @fn Room& GetCurrentRoom()
                                                              * @brief Accessors of _currentRoom attribute.
                                                              * @return The current room. */


    void SetStockOre(const int value) ; /** @fn void SetStockOre(const int value)
                                          * @brief Mutator of _stockOre attribute.
                                          * @param [in] value - The value to be assigned. */

    void AddOre(const int value) ; /** @fn void AddOre(const int value)
                                     * @brief Add the value passed in parameter to the _stockOre.
                                     * @param [in] value - The value to be add. */

    void AddVestige(const short int value) ; /** @fn void AddVestige(const short int value)
                                               * @brief Add the value passed in parameter to the _stockVestige.
                                               * @param [in] value - The value to be add. */

    void SetDifficulty(const unsigned short int value) ; /** @fn void Rush::SetMaxdifficulty(const unsigned short int value)
                                                           * @brief Mutator of _maxDifficulty attribute.
                                                           * @param [in] value - The value to be assigned. */

    void IncrementsIndiceCurrentRoom() ; /** @fn void Rush::IncrementsIndiceCurrentRoom()
                                           * @brief Increase by one _indiceCurrentRoom attribute. */

    void SetTrueEnd(const bool value) ; /** @fn  void SetTrueEnd(const bool value)
                                          * @brief Mutator of _trueEnd attribute.
                                          * @param [in] value - The value to be assigned. */


    void LeaveRoom() ; /** @fn void Rush::LeaveRoom()
                         * @brief Leave current room and create a new one. */

    void ConvertOreInSteam() ; /** @fn void ConvertOreInSteam()
                                  * @brief Convert 5 ore in steam, amount depend of _convertionRate attribute of Player class. */

    void EndRush() ; /** @fn void EndRush()
                       * @brief end the rush. */

    void Reroll(std::string typePart) ; /** @fn void Reroll(std::string typePart)
                                          * @brief Reroll a part of the player which the type is identify by the string passed in parameter.
                                          * @param [in] typePart - The type of the part which has to be reroll. */

    void EndBattle() ; /** @fn void EndBattle()
                         * @brief End a battle. */

    void DisplayPlayer(std::string typeMessage) ; /** @fn void DisplayPlayer(std::string typeMessage)
                                                    * @brief Subtract the value passed in parameter to the stockOre.
                                                    * @param [in] typeMessage - The type of display : "start" for the creation screen, "rush" to display the player during a rush. */

} ;

#endif // RUSH_HPP_INCLUDED
