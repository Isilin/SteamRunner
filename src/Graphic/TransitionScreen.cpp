#include "TransitionScreen.hpp"

TransitionScreen::TransitionScreen() : _background(), _disappearing(false){
    _background.setPosition(0.0f, 0.0f) ;
    _background.setSize(sf::Vector2f(1366.0f, 768.0f)) ;
    _background.setFillColor(sf::Color(0.0f, 0.0f, 0.0f, 0.0f)) ;
}

TransitionScreen::~TransitionScreen(){
}

bool TransitionScreen::Refresh(){
    if(!_disappearing){
        _background.setFillColor(sf::Color(0.0f, 0.0f, 0.0f, static_cast<sf::Uint8>(_background.getFillColor().a + 1))) ;
        if(_background.getFillColor().a >= 255){
            _disappearing = true ;
        }
    } else{
        _background.setFillColor(sf::Color(0.0f, 0.0f, 0.0f, static_cast<sf::Uint8>(_background.getFillColor().a - 1))) ;
    }
    return _disappearing && _background.getFillColor().a <= 0 ;
}

void TransitionScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(_background, states) ;
}
