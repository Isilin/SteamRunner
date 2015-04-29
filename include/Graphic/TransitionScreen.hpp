#ifndef TRANSITIONSCREEN_HPP_INCLUDED
#define TRANSITIONSCREEN_HPP_INCLUDED

#include "SFML/Graphics.hpp"

class TransitionScreen{
public :
    TransitionScreen() ;
    ~TransitionScreen() ;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const ;
protected :
private :
    sf::RectangleShape _background ;
    bool _disappearing ;
} ;

#endif // TRANSITIONSCREEN_HPP_INCLUDED
