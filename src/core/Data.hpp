#ifndef DATA_HPP_INCLUDED
#define DATA_HPP_INCLUDED

/**
 * @file     Data.hpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Declaration of class Data.
 */

#include <string>
#include <vector>

/**
 * @class Data Data.hpp Data
 * @brief Class of static function to manipulate data and string.
 Data format : One value :  #keys=value~
               Many values : ##keys= #keys=value~#keys=value~....#keysN=valueN~ ~~

Exemples :
#type=head-0~#name=RH1-N0~#description=[1 (+1/niveau) armure] [Quand vous arrivez au corps à corps d'un ennemi, vous lui réduisez son armure de 1 (+1/niveau). Portée : 1]~#level=1~#pressureCost0=0~#minDistance0=1~#maxDistance0=1~##effects0= #value0=1~#perLevel0=1~#typeEffect0=enemyLessArmor~#initialeValue0=1~ ~~#direction0=up~ #pressureCost1=0~#minDistance1=0~#maxDistance1=0~##effects1= #value0=1~#perLevel0=1~#typeEffect0=armor~#initialeValue0=1~ ~~#direction1=none~
#type=head-1~#name=OV3-RL04D~#description=[20 (+20/niveau) intégrité] [Quand vous arrivez a 0 de pression, vous effectuer une attaque à distance qui inflige 1 (+1/niveau) par pression par tour. Portée : max]~#level=1~#pressureCost0=0~#minDistance0=1~#maxDistance0=7~##effects0= #value0=1~#perLevel0=1~#typeEffect0=AttackPerPressurePerTurn~#initialeValue0=1~ ~~#direction0=up~ #pressureCost1=0~#minDistance1=0~#maxDistance1=0~##effects1= #value0=20~#perLevel0=20~#typeEffect0=maxIntegrity~#initialeValue0=20~ ~~#direction1=none~
 */
class Data
{
private :
    static std::vector<std::string> _playerTxt ; /**< @brief Data about player. */
    static std::vector<std::string> _saveTxt ; /**< @brief Data about saveable data. */
    static std::vector<std::string> _mobjungleTxt ; /**< @brief Data about mob in biome jungle. */
    static std::vector<std::string> _mobdesertTxt ; /**< @brief Data about mob in biome desert. */
    static std::vector<std::string> _mobmineTxt ; /**< @brief Data about mob in biome mine. */
    static std::vector<std::string> _tutorielTxt ; /**< @brief The tutorial. */
    static std::vector<std::string> _creditTxt ; /**< @brief The credit. */
    static std::vector<std::string> _roomTxt ; /**< @brief Data about rooms. */

public :
    static std::string Read(const std::string type, const std::string keys="") ; /** @fn string Data::Read(const string type, string keys)
                                                                                   * @brief Read and return an information.
                                                                                   * @return
                                                                                   * @param [in] type - The type of the data to read.
                                                                                   * @param [in] keys - The keys to find the data to read. */

    static void Upgrade(const std::string type, const std::string keys) ; /** @fn void Upgrade(const std::string type, const std::string keys)
                                                                            * @brief Upgrade in data which the type and keys to identify it are passed in parameter.
                                                                            * @param [in] type - The type of the data to upgrade.
                                                                            * @param [in] keys - The keys to find the data to upgrade. */

    static std::string SearchInString(const std::string myString, const std::string mySearch,
                                      bool tildDoubled=false) ; /** @fn std::string SearchInString(const std::string myString, const std::string mySearch, bool tildDoubled=false)
                                                                  * @brief Search in a string passed in parameter, a other string passed in parameter.
                                                                  * @param [in] myString - The string in which we search.
                                                                  * @param [in] mySearch - The string we have to find.
                                                                  * @param [in] tildDoubled - true if return the string between "mySearch=" and the first "~~" find after, false otherwise and per default.
                                                                  * @return The string between "mySearch=" and the first "~", or "~~", find after the "=" just after mySearch.*/

    static std::string ToString(const int r) ; /** @fn std::string ToString(const int r)
                                                 * @brief Transform a int into a string containing this number.
                                                 * @param [in] r - The int to be convert.
                                                 * @return The string containing the number. */

    static int ToInt(const std::string s) ; /** @fn int ToInt(const std::string s)
                                              * @brief Transform a string containing a number into an int.
                                              * @param [in] s - The string to be convert.
                                              * @return The int. */

    static std::vector<std::string> SplitString(std::string myString, std::string mySplit) ; /** @fn std::vector<std::string> SplitString(std::string myString, std::string mySplit)
                                                                                               * @brief Split a string passed in parameter depend of a separator passed in parameter.
                                                                                               * @param [in] myString - The string which will be split.
                                                                                               * @param [in] mySplit - The separator searched between strings.
                                                                                               * @return A vector of string containing the different string due to the split. */

    static void InitData() ; /** @fn void InitData()
                               * @brief Initialize all statics vector of strings containing the data from files. */

    static void SaveData() ; /** @fn void SaveData()
                               * @brief Write all statics vector of strings to files. */

    static void CloseData() ; /** @fn void CloseData()
                                * @brief Clear all statics vector of string. */

    static void Reset() ; /** @fn void Reset()
                            * @brief Reset the values wich to be reset in files. */

    static void Write(const std::string keys, int value) ; /** @fn void Write(const std::string keys, int value)
                                                             * @brief Write a value passed in parameter in somewhere in a file which is identify with the string passed in parameter.
                                                             * @param [in] keys - The keys to identify in which file and where write the value.
                                                             * @param [in] value - The value to be write. */
} ;

#endif // DATA_HPP_INCLUDED
