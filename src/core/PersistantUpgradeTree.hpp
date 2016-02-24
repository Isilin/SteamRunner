#ifndef PERSISTANTUPGRADETREE_HPP_INCLUDED
#define PERSISTANTUPGRADETREE_HPP_INCLUDED

/**
 * @file     PersistantUpgradeTree.hpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Declaration of class PersistantUpgradeTree.
 */

#include <vector>
#include <string>

/**
 * @class PersistantUpgradeTree PersistantUpgradeTree.hpp PersistantUpgradeTree
 * @brief A tree of persistants upgrades between differents rushs.
 */
class PersistantUpgradeTree
{
private :
    std::vector<std::string> _persistantUpgrades ; /**< @brief Attribute : identify all persistants upgrades. */
    int _stockOre ; /**< @brief Attribute : the amount of ore avaible during an upgrade session. */


public :
    PersistantUpgradeTree() ; /** @fn PersistantUpgradeTree()
                                * @brief Constructor. */

    ~PersistantUpgradeTree() ; /** @fn ~PersistantUpgradeTree()
                                 * @brief Destructor. */

    inline int GetStockOre() const {return _stockOre ;} ;

    const bool SubStockOre(const int value) ; /** @fn const bool SubStockOre(const int value)
                                                * @brief Subtract the value passed in parameter to the _stockOre.
                                                * @param [in] value - The value to be subtract.
                                                * @return true if there is no problem, false otherwise. */

    const bool WillTrueEnded() ; /** @fn const bool WillTrueEnded()
                                   * @brief Return true if the end will be the true end.
                                   * @return true if the end will be the true end, false otherwise. */

    void Upgrade(const std::string typePersistantUpgrade, const std::string keys) ; /** @fn void Upgrade(const std::string typePersistanteUpgrade, const std::string keys)
                                                                                       * @brief Upgrade a persistant upgrade identify by two strings passed in parameter.
                                                                                       * @param [in] typePersistanteUpgrade - A string to identify the type of persistant upgrade : "Save" or "PlayerPart".
                                                                                       * @param [in] keys - A string to identify the persistant upgrade. */

    void Init() ; /** @fn void Init()
                    * @brief Initialisation of PersistantUpgradeTree. */

    void SendCostToGraphicEngine(std::string typePersistantUpgrade) ; /** @fn string PersistantUpgradeTree::SendDescriptionToGraphicEngine(string typePersistantUpgrade)
                                                                                            * @brief Send to graphic engine the description of a persistent upgrade which the type is passed in parameter.
                                                                                            * @param [in] typePersistantUpgrade - The type of the persistent upgrade.
                                                                                            * @return The description of the persistent upgrade. */
} ;

#endif // PERSISTANTUPGRADETREE_HPP_INCLUDED

