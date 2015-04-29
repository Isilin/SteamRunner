#ifndef GRAPHICENGINE_HPP_INCLUDED
#define GRAPHICENGINE_HPP_INCLUDED

#include "SFML/Graphics.hpp"
#include "Engine.hpp"
#include "ProgressBar/ProgressBar.hpp"

class GraphicEngine : public Engine{
public :
    GraphicEngine() ;
    ~GraphicEngine() ;

    GraphicEngine(const GraphicEngine&) = delete ;
    GraphicEngine& operator=(const GraphicEngine&) = delete ;

    virtual TypeEngine Id() const ;
    virtual void ExecuteThread() ;
protected :
    virtual void ProcessEvent(const EngineEvent& eventIn) ;
    virtual void Frame() ;
private :
    void ProcessWindowEvents() ;
    void Update(sf::Time dTimeIn) ;
    void Render() ;

    sf::RenderWindow* _window ;
    sf::Clock _clock ;
    sf::Time _lastUpdate ;
    sf::Text _fps ;
    sf::Font _font ;
    int _frame ;
    ProgressBar _bar ;
} ;

#endif // COREENGINE_HPP_INCLUDED
