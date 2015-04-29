#ifndef ACTION_HPP_INCLUDED
#define ACTION_HPP_INCLUDED

#include <vector>
#include <string>
#include "Area.hpp"
#include "Direction.hpp"
#include "Named.hpp"
#include "Condition.hpp"

class Entity ;

class Action : public Area, public Direction, public Named{
public :
    Action(const Area& aoeIn, const Direction& directionIn, const int costIn, const std::string nameIn) ;
    Action(const Action& cloneIn) ;
    ~Action() ;

    Action& operator+=(const Condition& newConditionIn) ;

    int Cost() const ;

    void Execute(Entity& targetIn) ;
protected :
    const Condition& GetConditions(const int indiceIn) const ;
    int NumberOfConditions() const ;
private :
    std::vector<Condition> _listConditions ;
    int _cost ;
} ;

#endif // ACTION_HPP_INCLUDED
