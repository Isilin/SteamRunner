#ifndef PROGRESSBAR_HPP_INCLUDED
#define PROGRESSBAR_HPP_INCLUDED

#include "SFML/Graphics.hpp"

class ProgressBar : public sf::Drawable{
public :
    ProgressBar() ;
    ~ProgressBar() ;

    ProgressBar(const ProgressBar&) = delete ;
    ProgressBar& operator=(const ProgressBar&) = delete ;

    void SetProgression(const float progressionIn) ;
    float Progression() const ;
    void RefreshPoint() ;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const ;
protected :
private :
    float _progression ;
    sf::Text _percentage ;
    sf::Font _font ;
    sf::RectangleShape _background ;
    sf::RectangleShape _bar ;
    sf::CircleShape _point ;
    bool _swelling ;
} ;

#endif // PROGRESSBAR_HPP_INCLUDED
