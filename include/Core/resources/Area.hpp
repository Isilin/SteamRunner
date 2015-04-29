#ifndef AREA_HPP_INCLUDED
#define AREA_HPP_INCLUDED

class Area{
public :
    Area(const int distanceMinIn, const int distanceMaxIn) ;
    Area(const Area& cloneIn) ;
    virtual ~Area() ;

    bool IsInArea(const int positionIn) ;
protected :
    int DistanceMin() const ;
    int DistanceMax() const ;
private :
    int _distanceMin ;
    int _distanceMax ;
} ;

#endif // AREA_HPP_INCLUDED
