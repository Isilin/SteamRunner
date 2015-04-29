#ifndef BIOME_HPP_INCLUDED
#define BIOME_HPP_INCLUDED

#include "Named.hpp"

class Biome : public Named{
public :
    Biome(const std::string& nameIn) ;
    Biome(const Biome& cloneIn) ;
    ~Biome() ;

    bool operator==(const Biome& rightOperandIn) const ;
protected :
private :
} ;

#endif // BIOME_HPP_INCLUDED
