#ifndef NAMED_HPP_INCLUDED
#define NAMED_HPP_INCLUDED

#include <string>

class Named{
public :
    Named(const std::string& nameIn) ;
    Named(const Named& cloneIn) ;
    virtual ~Named() ;

    const std::string& Name() const ;
    void Rename(const std::string& newNameIn) ;
protected :
    std::string _name ;
private :
} ;

#endif // NAMED_HPP_INCLUDED
