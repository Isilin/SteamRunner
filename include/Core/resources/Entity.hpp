#ifndef ENTITY_HPP_INCLUDED
#define ENTITY_HPP_INCLUDED

#include <vector>
#include "Attribute.hpp"
#include "Part.hpp"
#include "Condition.hpp"

// TODO (IsilinBN#1#): Verifier l'utilisation de la class Attribute (un attribut est ajouter à l'entité depuis l'ajout d'une partie)

class Entity{
public :
    Entity() ;
    ~Entity() ;

    void Suffer() ;
    void Receive(const Condition& newConditionIn) ;
protected :
    void Apply(const Effect& effectIn) ;
private :
    std::vector<Attribute> _listAttributes ;
    std::vector<Part> _listParts ;
    std::vector<Condition> _listConditions ;
} ;

#endif // ENTITY_HPP_INCLUDED
