#ifndef PART_HPP_INCLUDED
#define PART_HPP_INCLUDED

#include <vector>
#include "Action.hpp"
#include "Condition.hpp"
#include "Biome.hpp"
#include "TypePart.hpp"

class Part : public Named, public TypePart{
public :
    Part(const std::string& nameIn, const TypePart& typeIn) ;
    ~Part() ;

    Part& operator+=(const Action& newActionIn) ;
    Part& operator+=(const Biome& newBiomeIn) ;
    Part& operator+=(const Condition& newConditionIn) ;
protected :
private :
    std::vector<Action> _listActions ;
    std::vector<Biome> _listBiomes ;
    std::vector<Condition> _listConditions ;
} ;

#endif // PART_HPP_INCLUDED
