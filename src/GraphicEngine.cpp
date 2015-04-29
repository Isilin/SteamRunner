#include "GraphicEngine.hpp"
#include <iostream>
#include <SFML/OpenGL.hpp>

GraphicEngine::GraphicEngine() : Engine(), _window(nullptr), _clock(), _lastUpdate(sf::Time::Zero), _fps(),
                                            _font(), _frame(0), _bar(){
    try{
        _font.loadFromFile("data/fonts/calibri.ttf") ;
    } catch(const std::exception& e){
        std::cout << e.what() << std::endl ;
    }
    _fps.setString("FPS : 0") ;
    _fps.setFont(_font) ;
    _fps.setCharacterSize(static_cast<unsigned int>(14.0f)) ;
    _fps.setPosition(sf::Vector2f(16, 16)) ;
    _fps.setColor(sf::Color(255, 255, 255, 255)) ;
}

GraphicEngine::~GraphicEngine(){
    delete(_window) ;
}

TypeEngine GraphicEngine::Id() const{
    return GRAPHIC ;
}

void GraphicEngine::ExecuteThread(){
    _window = new sf::RenderWindow(sf::VideoMode(1366, 768), "SteamRunner", sf::Style::Default) ;
    _window->setFramerateLimit(60) ;
    _window->setKeyRepeatEnabled(false) ;
    glEnable(GL_TEXTURE_2D) ;
    _clock.restart() ;
    Engine::ExecuteThread() ;
}

void GraphicEngine::ProcessEvent(const EngineEvent& eventIn){
}

void GraphicEngine::Frame(){
    _frame++ ;
    if(_window->isOpen()){
        ProcessWindowEvents() ;
        if(_clock.getElapsedTime().asMilliseconds() >= 1000){
            Update(_clock.restart()) ;
        }
        Render() ;
    }
}


void GraphicEngine::ProcessWindowEvents(){
    /* ===== Mouse events & keyboard events ===== */
    sf::Event tmpEvent ;
    while(_window->pollEvent(tmpEvent)){
        if (tmpEvent.type == sf::Event::Closed
            || (tmpEvent.type == sf::Event::KeyPressed && tmpEvent.key.code == sf::Keyboard::Escape)){
            _window->close() ;
            StopThread() ;
        }
    }

    if(_bar.Progression() < 100){
        _bar.SetProgression(_bar.Progression()+0.5f) ;
    }
    _bar.RefreshPoint() ;
}

void GraphicEngine::Update(sf::Time dTimeIn){
    _fps.setString("FPS : "+ std::to_string(_frame * 1/ (dTimeIn.asMilliseconds() * 0.001))) ;
    _frame = 0 ;
}

void GraphicEngine::Render(){
    if(_window->isOpen()){
        /* ===== Clear the window ===== */
        _window->clear(sf::Color::Black) ;

        /* ===== Draw on the window ===== */
        _window->draw(_fps) ;
        _window->draw(_bar) ;
        /* ===== Display the window ===== */
        _window->display() ;
    }
}
