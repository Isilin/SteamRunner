#ifndef GAMEENGINE_HPP_INCLUDED
#define GAMEENGINE_HPP_INCLUDED

/**
 * @file     CoreEngine.hpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Declaration of class CoreEngine.
 */

#include "Engine.hpp"
#include "./core/PersistantUpgradeTree.hpp"
#include "./core/Rush.hpp"

/**
 * @class CoreEngine CoreEngine.hpp CoreEngine
 * @brief The engine of the core of the game.
 */
class CoreEngine : public Engine
{
public :
    CoreEngine(Game* parent) ; /** @fn CoreEngine(Game* parent)
                                 * @brief Constructor.
                                 * @param [in] parent - A Game class pointer. */

    ~CoreEngine() ; /** @fn ~CoreEngine()
                      * @brief Destructor. */

    virtual inline void Frame(){} ; /** @fn void Frame()
                                      * @brief Frame of CoreEngine. */

    virtual void ProcessEvent(const EngineEvent* event) ; /** @fn void ProcessEvent(const EngineEvent* event)
                                                            * @brief Process an event.
                                                            * @param [in] event - the event to be process. */

    inline void Init() {_persistantUpgradeTree.Init() ;} ; /** @fn  void Init()
                                                             * @brief Initialisation of CoreEngine. */

private :
    PersistantUpgradeTree _persistantUpgradeTree ; /**< @brief Attribute : a persistant upgradre tree . */
    Rush _rush ; /**< @brief Attribute : a rush class. */

} ;

#endif // GAMEENGINE_HPP_INCLUDED
