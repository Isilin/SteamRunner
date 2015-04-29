#ifndef TYPEEFFECT_HPP_INCLUDED
#define TYPEEFFECT_HPP_INCLUDED

#include <string>

class TypeEffect{
public :
    TypeEffect(const std::string& typeIn, const std::string& targetIn) ;
    TypeEffect(const TypeEffect& cloneIn) ;
    virtual ~TypeEffect() ;

    const std::string& Type() const ;
    const std::string& Target() const ;
protected :
    std::string _type ;
    std::string _target ;
private :

} ;

#endif // TYPEEFFECT_HPP_INCLUDED
