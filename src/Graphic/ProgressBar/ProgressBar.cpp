#include "ProgressBar/ProgressBar.hpp"
#include <iostream>

ProgressBar::ProgressBar() : _progression(0.0f), _percentage(), _font(), _background(), _bar(), _point(), _swelling(true){
    try{
        _font.loadFromFile("data/fonts/calibri.ttf") ;
    } catch(const std::exception& e){
        std::cout << e.what() << std::endl ;
    }
    _percentage.setFont(_font) ;
    _percentage.setString("Progression : 0%") ;
    _percentage.setPosition(200.0f, 200.0f) ;
    _percentage.setColor(sf::Color::White) ;

    _background.setFillColor(sf::Color::White) ;
    _background.setSize(sf::Vector2f(1024.0f, 32.0f)) ;
    _background.setPosition(200.0f, 100.0f) ;

    _bar.setFillColor(sf::Color::Red) ;
    _bar.setSize(sf::Vector2f(24.0f, _background.getSize().y/2)) ;
    _bar.setPosition(_background.getPosition() + sf::Vector2f(0.0f, (_background.getSize().y-_bar.getSize().y)/2)) ;

    _point.setFillColor(sf::Color::Green) ;
    _point.setRadius(_background.getSize().y/8) ;
    _point.setPosition(_background.getPosition() + sf::Vector2f(_bar.getSize().x-_point.getRadius()*2,
                                                                (_background.getSize().y-_point.getRadius()*2)/2)) ;
}

ProgressBar::~ProgressBar(){
}

void ProgressBar::SetProgression(const float progressionIn){
    _progression = progressionIn ;
    _bar.setSize(sf::Vector2f(24.0f + 10.0f*static_cast<float>(_progression), _background.getSize().y/2)) ;
    _point.setPosition(_background.getPosition() + sf::Vector2f(_bar.getSize().x-_point.getRadius(),
                                                                (_background.getSize().y-_point.getRadius()*2)/2)) ;
    _percentage.setString("Progression : " + std::to_string(_progression).substr(0,5)) ;
}

float ProgressBar::Progression() const{
    return _progression ;
}

void ProgressBar::RefreshPoint(){
    if(_swelling){
        _point.setRadius(_point.getRadius()+0.1f) ;
        if(static_cast<int>(_point.getRadius()) >= 16){
            _swelling = false ;
        }
    } else{
        _point.setRadius(_point.getRadius()-0.1f) ;
        if(static_cast<int>(_point.getRadius()) <= 4){
            _swelling = true ;
        }
    }
    _point.setPosition(_background.getPosition() + sf::Vector2f(_bar.getSize().x-_point.getRadius(),
                                                                (_background.getSize().y-_point.getRadius()*2)/2)) ;
}

void ProgressBar::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(_percentage, states) ;
    target.draw(_background) ;
    target.draw(_bar) ;
    target.draw(_point) ;
}
