#include "TransitionScreen.hpp"

TransitionScreen::TransitionScreen() : _background(), _disappearing(false){
    _background.setPosition(0.0f, 0.0f) ;
    _background.setSize(sf::Vector2f(1366.0f, 768.0f)) ;
    _background.setFillColor(sf::Color::Black) ;
}

TransitionScreen::~TransitionScreen(){
}

void TransitionScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(_background, states) ;
}
