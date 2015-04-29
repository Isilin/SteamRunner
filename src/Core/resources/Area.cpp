#include "Area.hpp"

Area::Area(const int distanceMinIn, const int distanceMaxIn) : _distanceMin(distanceMinIn), _distanceMax(distanceMaxIn){
}

Area::Area(const Area& cloneIn) : _distanceMin(cloneIn.DistanceMin()), _distanceMax(cloneIn.DistanceMax()){
}

Area::~Area(){
}

bool Area::IsInArea(const int positionIn){
    return (positionIn <= _distanceMax && positionIn >= _distanceMin) ;
}

int Area::DistanceMin() const{
    return _distanceMin ;
}

int Area::DistanceMax() const{
    return _distanceMax ;
}
