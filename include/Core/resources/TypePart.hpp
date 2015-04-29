#ifndef TYPEPART_HPP_INCLUDED
#define TYPEPART_HPP_INCLUDED

#include <string>

class TypePart{
public :
    TypePart(const std::string& typeIn) ;
    TypePart(const TypePart& cloneIn) ;
    virtual ~TypePart() ;

    const std::string& Type() const ;
protected :
    std::string _type ;
private :
} ;

#endif // TYPEPART_HPP_INCLUDED
