/**
 * @file     GraphicEngine.cpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Methods of class GraphicEngine.
 */

#include "GraphicEngine.hpp"

#include "./core/Data.hpp"
#include "Game.hpp"
#include "Event.hpp"
#include "Graphic.hpp"
#include "EngineEvent.hpp"
using namespace sf ;
using namespace std ;
#include <iostream>

GraphicEngine::GraphicEngine(Game* parent) : Engine(parent), _eventHandlers(), _displays(), _currentLocation(ON_HOME),
                                             _resolution(VideoMode::getDesktopMode()), _selector(-1), _validator((Location)(-1 )), _mousePosition(0, 0), _unfixedElement(-1)
{
    _coreEngine = NULL ;
    _graphicEngine = this ;

    // création de la fenêtre
    //_window.create(_resolution, "Steam Runner");
    _window.create(_resolution, "Steam Runner", sf::Style::Fullscreen); //mettre fullscreen

    _eventHandlers.push_back(new EventHandlerHome(this));
    _eventHandlers.push_back(new EventHandlerPU(this));
    _eventHandlers.push_back(new EventHandlerPlayer(this));
    _eventHandlers.push_back(new EventHandlerGame(this));
    _eventHandlers.push_back(new EventHandlerCredits(this));
    _eventHandlers.push_back(new EventHandlerCredits(this));

    DisplayHome(true) ;
}

GraphicEngine::~GraphicEngine()
{
    _eventHandlers.clear() ;
    _displays.clear() ;
}

void GraphicEngine::Frame()
{
    //On vérifie que la fenêtre est ouverte
    if(_window.isOpen())
    {
        //on traite les évènements de l'écoute courante
        while(_window.pollEvent(*_eventHandlers[_currentLocation]))
        {
            // fermeture de la fenêtre lorsque l'utilisateur le souhaite
            if (_eventHandlers[_currentLocation]->type == sf::Event::Closed)
            {
                _window.close();
                _parent->Stop() ;
            }
            else
                _eventHandlers[_currentLocation]->OnEvent() ;
        }

        // effacement de la fenêtre en noir
        _window.clear(sf::Color::Black);
        // c'est ici qu'on dessine tout
        // window.draw(...);
        for(vector<Display*>::iterator i = _displays.begin() ; i != _displays.end() ; ++i)
        {
            (*i)->DisplayOn(&_window) ;
        }
        // fin de la frame courante, affichage de tout ce qu'on a dessiné
        _window.display();
    }
    else
    {
        _parent->Stop() ;
    }
}

void GraphicEngine::DisplayHome(const bool haveToBeInitialized)
{
    if(haveToBeInitialized)
    {
        _mousePosition = Vector2f(0, 0) ;
        _validator = (Location)(-1 );
        _selector = -1 ;
        _displays.clear() ;
        _currentLocation = ON_HOME ;

        _displays.push_back(new DisplayBackground("./data/png/background/home.png")) ;
        _displays.push_back(new DisplayMenu(Color(255,0,0), "./data/png/bouton/boutonHomeX2.png", "Jouer Tutoriel Options Crédits Quitter ", IntRect(0, 0, 512, 128),
                                            IntRect(650, 100, 0, 150), 5)) ;
    }

    for(vector<Display*>::iterator i = _displays.begin() ; i != _displays.end() ; ++i)
    {
        (*i)->Refresh() ;
    }
}

void GraphicEngine::DisplayPU(const bool haveToBeInitialized)
{
    if(haveToBeInitialized)
    {
        _mousePosition = Vector2f(0, 0) ;
        _validator = (Location)(-1 ) ;
        _selector = -1 ;
        _displays.clear() ;
        _currentLocation = ON_PU ;

        _displays.push_back(new DisplayBackground("./data/png/background/puTree.png")) ;
        _displays.push_back(new DisplayMenu(Color::Red, "./data/png/bouton/boutonHomeX2.png", "Retour Continuer", IntRect(0, 0, 512, 128),
                                            IntRect(0, 900, 1408, 0), 2)) ;
        _displays.push_back(new DisplaySprite("./data/png/icone/minerai.png", Color::White, 1, IntRect(0, 0, 64, 64), Vector2f(10, 10))) ;
    }

    for(vector<Display*>::iterator i = _displays.begin() ; i != _displays.end() ; ++i)
    {
        (*i)->Refresh() ;
    }
}
void GraphicEngine::DisplayPlayer(const bool haveToBeInitialized)
{
    if(haveToBeInitialized)
    {
        _mousePosition = Vector2f(0, 0) ;
        _validator = (Location)(-1 );
        _selector = -1 ;
        _displays.clear() ;
        _currentLocation = ON_PLAYER ;

        _displays.push_back(new DisplayBackground("./data/png/background/player.png")) ;
        _displays.push_back(new DisplayMenu(Color::Red, "./data/png/bouton/boutonHomeX2.png", "Continuer", IntRect(0, 0, 512, 128),
                                            IntRect(1408, 900, 0, 0), 1)) ;
        _displays.push_back(new DisplaySprite("./data/png/icone/reroll.png", Color::White, 3, IntRect(0, 0, 64, 64), Vector2f(1800, 10))) ;
    }

    for(vector<Display*>::iterator i = _displays.begin() ; i != _displays.end() ; ++i)
    {
        (*i)->Refresh() ;
    }

}

void GraphicEngine::DisplayGame(const bool haveToBeInitialized)
{
    if(haveToBeInitialized)
    {
        _mousePosition = Vector2f(0, 0) ;
        _selector = -1 ;
        _displays.clear() ;
        _currentLocation = ON_GAME ;
    }

    for(vector<Display*>::iterator i = _displays.begin() ; i != _displays.end() ; ++i)
    {
        (*i)->Refresh() ;
    }
}

void GraphicEngine::DisplayCredits(const bool haveToBeInitialized)
{
    if(haveToBeInitialized)
    {
        _mousePosition = Vector2f(0, 0) ;
        _selector = -1 ;
        _displays.clear() ;
        _currentLocation = ON_CREDITS ;
    }

    for(vector<Display*>::iterator i = _displays.begin() ; i != _displays.end() ; ++i)
    {
        (*i)->Refresh() ;
    }
}

void GraphicEngine::DisplayOptions(const bool haveToBeInitialized)
{

}

void GraphicEngine::ProcessEvent(const EngineEvent* event)
{
    if(event->_type.compare("mouseMoved")==0)
    {
        _mousePosition = Vector2f(event->_intData.at("x"), event->_intData.at("y")) ;
    }

    if( _currentLocation == ON_HOME)
    {
        if(event->_type.compare("mouseMoved")==0)
        {
            if(_displays.at(1)->IsContained(0, event->_intData.at("x"), event->_intData.at("y")))
            {
                if(_selector != -1)
                {
                    _displays.at(1)->ChangeFrame(_selector, 0) ;
                }
                _selector = 0 ;
                _displays.at(1)->ChangeFrame(0, 1) ;
            }
            else if(_displays.at(1)->IsContained(1, event->_intData.at("x"), event->_intData.at("y")))
            {
                if(_selector != -1)
                {
                    _displays.at(1)->ChangeFrame(_selector, 0) ;
                }
                _selector = 1 ;
                _displays.at(1)->ChangeFrame(1, 1) ;
            }
            else if(_displays.at(1)->IsContained(2, event->_intData.at("x"), event->_intData.at("y")))
            {
                if(_selector != -1)
                {
                    _displays.at(1)->ChangeFrame(_selector, 0) ;
                }
                _selector = 2 ;
                _displays.at(1)->ChangeFrame(2, 1) ;
            }
            else if(_displays.at(1)->IsContained(3, event->_intData.at("x"), event->_intData.at("y")))
            {
                if(_selector != -1)
                {
                    _displays.at(1)->ChangeFrame(_selector, 0) ;
                }
                _selector = 3 ;
                _displays.at(1)->ChangeFrame(3, 1) ;
            }
            else if(_displays.at(1)->IsContained(4, event->_intData.at("x"), event->_intData.at("y")))
            {
                if(_selector != -1)
                {
                    _displays.at(1)->ChangeFrame(_selector, 0) ;
                }
                _selector = 4 ;
                _displays.at(1)->ChangeFrame(4, 1) ;
            }
        }
        else if(event->_type.compare("mousePressed")==0)
        {
            _validator = ON_HOME ;
            if(_displays.at(1)->IsContained(0, event->_intData.at("x"), event->_intData.at("y")))
            {
                EngineEvent* message = new EngineEvent() ;
                message->_type = "click" ;
                EngineEvent::SendToSound(message) ;
                message = NULL ;
                _displays.at(1)->ChangeFrame(0, 2) ;
            }
            else if(_displays.at(1)->IsContained(1, event->_intData.at("x"), event->_intData.at("y")))
            {
                EngineEvent* message = new EngineEvent() ;
                message->_type = "click" ;
                EngineEvent::SendToSound(message) ;
                message = NULL ;
                _displays.at(1)->ChangeFrame(1, 2) ;
            }
            else if(_displays.at(1)->IsContained(2, event->_intData.at("x"), event->_intData.at("y")))
            {
                EngineEvent* message = new EngineEvent() ;
                message->_type = "click" ;
                EngineEvent::SendToSound(message) ;
                message = NULL ;
                _displays.at(1)->ChangeFrame(2, 2) ;
            }
            else if(_displays.at(1)->IsContained(3, event->_intData.at("x"), event->_intData.at("y")))
            {
                EngineEvent* message = new EngineEvent() ;
                message->_type = "click" ;
                EngineEvent::SendToSound(message) ;
                message = NULL ;
                _displays.at(1)->ChangeFrame(3, 2) ;
            }
            else if(_displays.at(1)->IsContained(4, event->_intData.at("x"), event->_intData.at("y")))
            {
                EngineEvent* message = new EngineEvent() ;
                message->_type = "click" ;
                EngineEvent::SendToSound(message) ;
                message = NULL ;
                _displays.at(1)->ChangeFrame(4, 2) ;
            }
            else
            {
                if(_selector != -1)
                {
                    _displays.at(1)->ChangeFrame(_selector, 0) ;
                }
            }
        }
        else if(event->_type.compare("mouseReleased")==0 && _validator == ON_HOME)
        {
            if(_displays.at(1)->IsContained(0, event->_intData.at("x"), event->_intData.at("y")))
            {
                EngineEvent* message = new EngineEvent() ;
                message->_type = "play" ;
                EngineEvent::SendToCore(message) ;
                message = NULL ;

                _displays.at(1)->ChangeFrame(0, 0) ;

                DisplayPU(true) ;
            }
            else if(_displays.at(1)->IsContained(1, event->_intData.at("x"), event->_intData.at("y")))
            {
                cerr << "tutoriel" << endl ;

                _displays.at(1)->ChangeFrame(1, 0) ;
            }
            else if(_displays.at(1)->IsContained(2, event->_intData.at("x"), event->_intData.at("y")))
            {
                cerr << "option" << endl ;

                _displays.at(1)->ChangeFrame(2, 0) ;
            }
            else if(_displays.at(1)->IsContained(3, event->_intData.at("x"), event->_intData.at("y")))
            {
                EngineEvent* message = new EngineEvent() ;
                message->_type = "credit" ;
                EngineEvent::SendToCore(message) ;
                message = NULL ;

                _displays.at(1)->ChangeFrame(3, 0) ;

                DisplayCredits(true) ;
            }
            else if(_displays.at(1)->IsContained(4, event->_intData.at("x"), event->_intData.at("y")))
            {

                _displays.at(1)->ChangeFrame(4, 0) ;

               CloseWindow() ;
            }
            else
            {
                if(_selector != -1)
                {
                    _displays.at(1)->ChangeFrame(_selector, 0) ;
                }
            }
            _validator = (Location)(-1) ;
        }
        else if(event->_type.compare("keyReleased")==0)
        {
            if(event->_stringData.at("key").compare("return")==0)
            {
                if(_selector == 0)
                {

                    EngineEvent* message = new EngineEvent() ;
                    message->_type = "play" ;
                    EngineEvent::SendToCore(message) ;
                    message = NULL ;

                    _displays.at(1)->ChangeFrame(_selector, 0) ;

                    DisplayPU(true) ;
                }
                else if(_selector == 4)
                {
                    _displays.at(1)->ChangeFrame(_selector, 0) ;
                    CloseWindow() ;
                }
            }
        }
        else if(event->_type.compare("keyPressed")==0)
        {
            if(event->_stringData.at("key").compare("up")==0)
            {
                if(_selector == -1)
                {
                    _selector = 4 ;
                    _displays.at(1)->ChangeFrame(4, 1) ;
                }
                else
                {
                    _displays.at(1)->ChangeFrame(_selector, 0) ;
                    _selector-- ;
                    if(_selector < 0)
                        _selector = 4 ;
                    _displays.at(1)->ChangeFrame(_selector, 1) ;
                }
            }
            if(event->_stringData.at("key").compare("down")==0)
            {
                if(_selector == -1)
                {
                    _selector = 0 ;
                    _displays.at(1)->ChangeFrame(0, 1) ;
                }
                else
                {
                    _displays.at(1)->ChangeFrame(_selector, 0) ;
                    _selector++ ;
                    if(_selector > 4)
                        _selector = 0 ;
                    _displays.at(1)->ChangeFrame(_selector, 1) ;
                }
            }
            if(event->_stringData.at("key").compare("return")==0)
            {
                _displays.at(1)->ChangeFrame(_selector, 2) ;
            }
        }
    }
    else if( _currentLocation == ON_PU)
    {
        if(event->_type.compare("PUStockOre")==0)
        {
            if(_displays.at(2)->GetNbTexts() == 0)
            {
                _displays.at(2)->AddText(Vector2f(90, 42), event->_stringData.at("stockOre"), "./data/fonts/steampunk.ttf", Color::Black, 20) ;
            }
            else
            {
                _displays.at(2)->SetText(0, event->_stringData.at("stockOre")) ;
            }
            DisplayPU(false) ;
        }
        else if(event->_type.compare("PUDescription")!=0 && event->_type.compare("PUStockOre")!=0 && event->_type.compare("PUCost")!=0
            && (event->_type.substr(0, 2).compare("PU"))==0)
        {
            Vector2f tmpPosition(0, 0) ;
            int nbDisplays = (_displays.size() - 3)/2 ;
            if(nbDisplays < 4) /* Head */
            {
                tmpPosition.x = (nbDisplays%2)*148 + 822 ; tmpPosition.y = (nbDisplays/2)*148 + 20 ;
            }
            else if(nbDisplays >= 4 && nbDisplays < 8) /* Chest */
            {
                nbDisplays -= 4 ;
                tmpPosition.x = (nbDisplays%2)*248 + 768 ; tmpPosition.y = (nbDisplays/2)*248 + 320 ;
            }
            else if(nbDisplays >= 8 && nbDisplays < 12) /* Legs */
            {
                nbDisplays -= 8 ;
                tmpPosition.x = (nbDisplays%2)*168 + 812 ; tmpPosition.y = (nbDisplays/2)*218 + 720 ;
            }
            else if(nbDisplays >= 12 && nbDisplays < 18) /* Left Arms + spe */
            {
                nbDisplays -= 12 ;
                tmpPosition.x = (nbDisplays/3)*300 + 310 ; tmpPosition.y = (nbDisplays%3)*150 + 320 ;
            }
            else if(nbDisplays >= 18 && nbDisplays < 24) /* Right Arms + spe */
            {
                nbDisplays -= 18 ;
                tmpPosition.x = (nbDisplays/3)*300 + 1180 ; tmpPosition.y = (nbDisplays%3)*150 + 320 ;
            }
            _displays.push_back(new DisplaySprite("./data/png/icone/pu.png", Color::White, 2, IntRect(0, 0, 128, 128), tmpPosition)) ;
            tmpPosition.y += 96 ;
            string tmpLevel = event->_stringData.at("level") ;
            tmpLevel.append(" / ") ; tmpLevel.append(event->_stringData.at("maxLevel")) ;
            _displays.back()->AddText(tmpPosition, tmpLevel, "./data/fonts/arial.ttf", Color::Black, 16) ;
            tmpPosition.x += 96 ;
            _displays.push_back(new DisplaySprite("./data/png/icone/add.png", Color::White, 3, IntRect(0, 0, 32, 32), tmpPosition)) ;
            DisplayPU(false) ;
        }
        else if(event->_type.compare("stockOreError")==0)
        {
            if(_displays.size() == 52)
            {
                _unfixedElement = -1 ;
                _displays.erase(_displays.begin()+51) ;
            }
            _displays.push_back(new DisplayText("Vous n'avez pas assez de minerais !", Vector2f(512, 256), "./data/fonts/arial.ttf", 16, true, false,
                                                    Vector2f(600, 600), Color::Black, "./data/png/bouton/textBox.png")) ;
            _displays.push_back(new DisplayMenu(Color::Red, "./data/png/bouton/boutonHomePetit.png", "Ok", IntRect(0, 0, 256, 64),
                                IntRect(700, 728, 0, 0), 1)) ;
            DisplayPU(false) ;
        }
        else if(event->_type.compare("mouseMoved")==0)
        {
            bool tmp = false ;
            if(_displays.at(1)->IsContained(0, event->_intData.at("x"), event->_intData.at("y")) && _displays.size() != 53)
            {
                tmp = true ;
                if(_selector != -1)
                {
                    if(_selector == 0 || _selector == 1)
                    {
                        _displays.at(1)->ChangeFrame(_selector, 0) ;
                    }
                    else
                    {
                        _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    }
                }
                _selector = 0 ;
                _displays.at(1)->ChangeFrame(_selector, 1) ;
            }
            else if(_displays.at(1)->IsContained(1, event->_intData.at("x"), event->_intData.at("y")) && _displays.size() != 53)
            {
                tmp = true ;
                if(_selector != -1)
                {
                    if(_selector == 0 || _selector == 1)
                    {
                        _displays.at(1)->ChangeFrame(_selector, 0) ;
                    }
                    else
                    {
                        _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    }
                }
                _selector = 1 ;
                _displays.at(1)->ChangeFrame(_selector, 1) ;
            }
            for(unsigned short int i = 2 ; i <= 48 ; i+=2)
            {
                if(_displays.at(i+1)->IsContained(0, event->_intData.at("x"), event->_intData.at("y"))
                   && !_displays.at(i+2)->IsContained(0, event->_intData.at("x"), event->_intData.at("y")) && _displays.size() != 53)
                {
                    tmp = true ;
                    if(_selector != -1)
                    {
                        if(_selector == 0 || _selector == 1)
                        {
                            _displays.at(1)->ChangeFrame(_selector, 0) ;
                        }
                        else
                        {
                            _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                        }
                    }
                    _selector = i ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                    if(event->_type.compare("PUDescription")!=0)
                    {
                        vector<string> tmp ;
                        tmp.push_back("head-0") ; tmp.push_back("head-1") ; tmp.push_back("head-2") ; tmp.push_back("head-3") ;
                        tmp.push_back("chest-0") ; tmp.push_back("chest-1") ; tmp.push_back("chest-2") ; tmp.push_back("chest-3") ;
                        tmp.push_back("legs-0") ; tmp.push_back("legs-1") ; tmp.push_back("legs-2") ; tmp.push_back("legs-3") ;
                        tmp.push_back("maxPressure") ; tmp.push_back("reroll") ; tmp.push_back("orePerEnemy") ;
                        tmp.push_back("arm-0") ; tmp.push_back("arm-1") ; tmp.push_back("arm-2") ;
                        tmp.push_back("arm-3") ; tmp.push_back("arm-4") ; tmp.push_back("arm-5") ;
                        tmp.push_back("convertionRate") ; tmp.push_back("endRate") ; tmp.push_back("initialPressure") ;
                        EngineEvent* message = new EngineEvent() ;
                        message->_type = "PUDescription" ;
                        message->_stringData.insert(pair<string,string>("type",tmp.at((i-2)/2))) ;
                        EngineEvent::SendToCore(message) ;
                        message = NULL ;
                    }
                    break ;
                }
                else if(_displays.at(i+2)->IsContained(0, event->_intData.at("x"), event->_intData.at("y")) && _displays.size() != 53)
                {
                    tmp = true ;
                    if(_selector != -1)
                    {
                        if(_selector == 0 || _selector == 1)
                        {
                            _displays.at(1)->ChangeFrame(_selector, 0) ;
                        }
                        else
                        {
                            _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                        }
                    }
                    _selector = i+1 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                    if(event->_type.compare("PUCost")!=0)
                    {
                        vector<string> tmp ;
                        tmp.push_back("head-0") ; tmp.push_back("head-1") ; tmp.push_back("head-2") ; tmp.push_back("head-3") ;
                        tmp.push_back("chest-0") ; tmp.push_back("chest-1") ; tmp.push_back("chest-2") ; tmp.push_back("chest-3") ;
                        tmp.push_back("legs-0") ; tmp.push_back("legs-1") ; tmp.push_back("legs-2") ; tmp.push_back("legs-3") ;
                        tmp.push_back("maxPressure") ; tmp.push_back("reroll") ; tmp.push_back("orePerEnemy") ;
                        tmp.push_back("arm-0") ; tmp.push_back("arm-1") ; tmp.push_back("arm-2") ;
                        tmp.push_back("arm-3") ; tmp.push_back("arm-4") ; tmp.push_back("arm-5") ;
                        tmp.push_back("convertionRate") ; tmp.push_back("endRate") ; tmp.push_back("initialPressure") ;
                        EngineEvent* message = new EngineEvent() ;
                        message->_type = "PUCost" ;
                        message->_stringData.insert(pair<string,string>("type",tmp.at((i-2)/2))) ;
                        EngineEvent::SendToCore(message) ;
                        message = NULL ;
                    }
                    break ;
                }
                else if(_displays.size() == 53)
                {
                    if(_displays.at(52)->IsContained(0, event->_intData.at("x"), event->_intData.at("y")))
                    {
                        tmp = true ;
                        if(_selector == 0 || _selector == 1)
                        {
                            _displays.at(1)->ChangeFrame(_selector, 0) ;
                        }
                        else
                        {
                            _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                        }
                        _selector = 51 ;
                        _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                    }
                }
            }
            if(!tmp)
            {
                if(_displays.size() == 52)
                {
                    _unfixedElement = -1 ;
                    _displays.erase(_displays.begin()+51) ;
                }
            }
        }
        else if(event->_type.compare("mousePressed")==0)
        {
            _validator = ON_PU ;
            if(_displays.at(1)->IsContained(0, event->_intData.at("x"), event->_intData.at("y")) && _displays.size() != 53)
            {
                EngineEvent* message = new EngineEvent() ;
                message->_type = "click" ;
                EngineEvent::SendToSound(message) ;
                message = NULL ;
                _displays.at(1)->ChangeFrame(_selector, 2) ;
            }
            else if(_displays.at(1)->IsContained(1, event->_intData.at("x"), event->_intData.at("y")) && _displays.size() != 53)
            {
                EngineEvent* message = new EngineEvent() ;
                message->_type = "click" ;
                EngineEvent::SendToSound(message) ;
                message = NULL ;
                _displays.at(1)->ChangeFrame(_selector, 2) ;
            }
            else if(_displays.at(_selector+1)->IsContained(0, event->_intData.at("x"), event->_intData.at("y")) && _selector >= 27 && _displays.size() != 53 && (_selector%2 != 0 || _selector == 0))
            {
                _displays.at(_selector+1)->ChangeFrame(0, 2) ;
            }
            else if(_displays.at(_selector+1)->IsContained(0, event->_intData.at("x"), event->_intData.at("y")) && (_selector%2 != 0 || _selector == 0))
            {
                _displays.at(_selector+1)->ChangeFrame(0, 2) ;
            }
        }
        else if(event->_type.compare("mouseReleased")==0 && _validator == ON_PU)
        {
            if(_displays.at(1)->IsContained(0, event->_intData.at("x"), event->_intData.at("y")) && _displays.size() != 53)
            {
                EngineEvent* message = new EngineEvent() ;
                message->_type = "end" ;
                EngineEvent::SendToCore(message) ;
                message = NULL ;
                DisplayHome(true) ;
            }
            else if(_displays.at(1)->IsContained(1, event->_intData.at("x"), event->_intData.at("y")) && _displays.size() != 53)
            {
                EngineEvent* message = new EngineEvent() ;
                message->_type = "endPU" ;
                EngineEvent::SendToCore(message) ;
                message = NULL ;
                DisplayPlayer(true) ;
            }
            else if(_displays.at(_selector+1)->IsContained(0, event->_intData.at("x"), event->_intData.at("y")) && _selector%2==1 && _displays.size() != 53)
            {
                vector<string> tmp ;
                tmp.push_back("head-0") ; tmp.push_back("head-1") ; tmp.push_back("head-2") ; tmp.push_back("head-3") ;
                tmp.push_back("chest-0") ; tmp.push_back("chest-1") ; tmp.push_back("chest-2") ; tmp.push_back("chest-3") ;
                tmp.push_back("legs-0") ; tmp.push_back("legs-1") ; tmp.push_back("legs-2") ; tmp.push_back("legs-3") ;
                tmp.push_back("maxPressure") ; tmp.push_back("reroll") ; tmp.push_back("orePerEnemy") ;
                tmp.push_back("arm-0") ; tmp.push_back("arm-1") ; tmp.push_back("arm-2") ;
                tmp.push_back("arm-3") ; tmp.push_back("arm-4") ; tmp.push_back("arm-5") ;
                tmp.push_back("convertionRate") ; tmp.push_back("endRate") ; tmp.push_back("initialPressure") ;
                EngineEvent* message = new EngineEvent() ;
                message->_type = "PUUpgrade" ;
                message->_stringData.insert(pair<string,string>("type",tmp.at((_selector-3)/2))) ;
                EngineEvent::SendToCore(message) ;
                message = NULL ;
                _displays.at(_selector+1)->ChangeFrame(0, 1) ;
            }
            else if(_displays.at(_selector+1)->IsContained(0, event->_intData.at("x"), event->_intData.at("y")) && (_selector%2 != 0 || _selector == 0))
            {
                _displays.erase(_displays.begin()+52) ;
                _displays.erase(_displays.begin()+51) ;
                _selector = -1 ;
            }
            _validator = (Location)(-1) ;
        }
        else if(event->_type.compare("keyPressed")==0)
        {
        }
        else if(event->_type.compare("keyReleased")==0)
        {
            if(event->_stringData.at("key").compare("up")==0 && (_selector%2 == 0 || _selector == -1 || _selector == 1))
            {
                if((_selector == -1 || _selector == 26) && _displays.size() != 53)
                {
                    if(_selector != -1)
                    {
                        _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    }
                    _selector = 0 ;
                    _displays.at(1)->ChangeFrame(_selector, 1) ;
                }
                else if(_selector == 44 && _displays.size() != 53)
                {
                    _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector = 1 ;
                    _displays.at(1)->ChangeFrame(_selector, 1) ;
                }
                else if(_selector == 0 && _displays.size() != 53)
                {
                    _displays.at(1)->ChangeFrame(_selector, 0) ;
                    _selector = 30 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
                else if(_selector == 1 && _displays.size() != 53)
                {
                    _displays.at(1)->ChangeFrame(_selector, 0) ;
                    _selector = 48 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
                else if(_selector == 2 && _displays.size() != 53)
                {
                    _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector = 22 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
                else if(_selector == 4 && _displays.size() != 53)
                {
                    _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector = 24 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
                else if(_selector == 32 || _selector == 38)
                {
                     _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector += 4 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
                else if(_selector >= 28 && _displays.size() != 53 && _selector != 32 && _selector != 38 && _selector != 44)
                {
                     _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector -= 2 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
                else if(_displays.size() != 53)
                {
                     _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector -= 4 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
            }
            else if(event->_stringData.at("key").compare("down")==0 && (_selector%2 == 0 || _selector == -1 || _selector == 1))
            {
                if(_selector == -1 && _displays.size() != 53)
                {
                    _selector = 2 ;
                    _displays.at(_selector)->ChangeFrame(0, 1) ;
                }
                else if(_selector == 30 && _displays.size() != 53)
                {
                    _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector = 0 ;
                    _displays.at(1)->ChangeFrame(_selector, 1) ;
                }
                else if(_selector == 48 && _displays.size() != 53)
                {
                    _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector = 1 ;
                    _displays.at(1)->ChangeFrame(_selector, 1) ;
                }
                else if(_selector == 0 && _displays.size() != 53)
                {
                    _displays.at(1)->ChangeFrame(_selector, 0) ;
                    _selector = 26 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
                else if(_selector == 1 && _displays.size() != 53)
                {
                    _displays.at(1)->ChangeFrame(_selector, 0) ;
                    _selector = 44 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
                else if(_selector == 22 && _displays.size() != 53)
                {
                    _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector = 2 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
                else if(_selector == 24 && _displays.size() != 53)
                {
                    _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector = 4 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
                else if(_selector == 36 || _selector == 42)
                {
                     _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector -= 4 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
                else if(_selector >= 26 && _displays.size() != 53 && _selector != 36 && _selector != 42 && _selector != 48)
                {
                     _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector += 2 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
                else if(_displays.size() != 53)
                {
                     _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector += 4 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
            }
            if(event->_stringData.at("key").compare("left")==0 && (_selector%2 == 0 || _selector == -1 || _selector == 1))
            {
                if(_selector == -1 || _selector == 0)
                {
                    if(_selector == 0)
                    {
                        _displays.at(1)->ChangeFrame(_selector, 0) ;
                    }
                    _selector = 1 ;
                    _displays.at(1)->ChangeFrame(_selector, 1) ;
                }
                else if(_selector == 1)
                {
                    _displays.at(1)->ChangeFrame(_selector, 0) ;
                    _selector = 24 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
                else if(_selector == 22)
                {
                    _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector = 0 ;
                    _displays.at(1)->ChangeFrame(_selector, 1) ;
                }
                else if(_selector == 2 || _selector == 6 || _selector == 18)
                {
                    _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector += 2 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
                else if(_selector == 10)
                {
                    _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector = 32 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
                else if(_selector == 14)
                {
                    _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector = 36 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
                else if(_selector == 26 || _selector == 28 || _selector == 30)
                {
                    _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector += 18 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
                else if(_selector == 38 || _selector == 42)
                {
                    _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector -= 26 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
                else if(_selector == 40)
                {
                    _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector = 34 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
                else if((_selector >= 32 && _selector <= 36) || (_selector >= 44 && _selector <= 48))
                {
                    _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector -= 6 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
                else
                {
                    _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector -= 2 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
            }
            if(event->_stringData.at("key").compare("right")==0 && (_selector%2 == 0 || _selector == -1 || _selector == 1))
            {
                if(_selector == -1 || _selector == 1)
                {
                    if(_selector == 1)
                    {
                        _displays.at(1)->ChangeFrame(_selector, 0) ;
                    }
                    _selector = 0 ;
                    _displays.at(1)->ChangeFrame(_selector, 1) ;
                }
                else if(_selector == 0)
                {
                    _displays.at(1)->ChangeFrame(_selector, 0) ;
                    _selector = 22 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
                else if(_selector == 24)
                {
                    _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector = 1 ;
                    _displays.at(1)->ChangeFrame(_selector, 1) ;
                }
                else if(_selector == 4 || _selector == 8 || _selector == 20)
                {
                    _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector -= 2 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
                else if(_selector == 12)
                {
                    _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector = 38 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
                else if(_selector == 16)
                {
                    _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector = 42 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
                else if(_selector == 44 || _selector == 46 || _selector == 48)
                {
                    _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector -= 18 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
                else if(_selector == 32 || _selector == 36)
                {
                    _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector -= 22 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
                else if(_selector == 34)
                {
                    _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector = 40 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
                else if((_selector >= 26 && _selector <= 30) || (_selector >= 38 && _selector <= 42))
                {
                    _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector += 6 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
                else
                {
                    _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                    _selector += 2 ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
            }
            if(event->_stringData.at("key").compare("return")==0)
            {
            }
        }
        else if(event->_type.compare("PUDescription")==0)
        {
            if(_unfixedElement == 1)
            {
                _displays.erase(_displays.begin()+51) ;
            }
            if(_unfixedElement != 0)
            {
                _unfixedElement = 0 ;
                string tmp = event->_stringData.at("name") ;
                tmp.append("\n\n") ;
                tmp.append(event->_stringData.at("description")) ;
                _displays.push_back(new DisplayText(tmp, Vector2f(512, 256), "./data/fonts/Augusta.ttf", 16, true, true,
                                                    _mousePosition, Color::Black, "./data/png/bouton/textBox.png")) ;
                DisplayPU(false) ;
            }
        }
        else if(event->_type.compare("PUCost")==0)
        {
            if(_unfixedElement == 0)
            {
                _displays.erase(_displays.begin()+51) ;
            }
            if(_unfixedElement != 1)
            {
                _unfixedElement = 1 ;
                _displays.push_back(new DisplayText(event->_stringData.at("cost"),
                                        Vector2f(128, 128), "./data/fonts/steampunk.ttf", 16, true, true,
                                        _mousePosition, Color::Black, "./data/png/icone/text.png")) ;
                DisplayPU(false) ;
            }
        }
    }
    else if(_currentLocation == ON_PLAYER)
    {
        if(event->_type.compare("reroll")==0)
        {
            if(_displays.at(2)->GetNbTexts() == 0)
            {
                _displays.at(2)->AddText(Vector2f(1874, 42), event->_stringData.at("value"), "./data/fonts/steampunk.ttf", Color::Black, 20) ;
            }
            else
            {
                _displays.at(2)->SetText(0, event->_stringData.at("value")) ;
            }
            DisplayPU(false) ;
        }
        else if(event->_type.compare("rerollError")==0)
        {
            _displays.push_back(new DisplayText("Vous n'avez pas assez de relance !", Vector2f(512, 256), "./data/fonts/arial.ttf", 16, true, false,
                                                    Vector2f(600, 600), Color::Black, "./data/png/bouton/textBox.png")) ;
            _displays.push_back(new DisplayMenu(Color::Red, "./data/png/bouton/boutonHomePetit.png", "Ok", IntRect(0, 0, 256, 64),
                                IntRect(700, 728, 0, 0), 1)) ;
            DisplayPlayer(false) ;
        }
        else if(event->_type.compare("startPart")==0)
        {
            /* preparer chemin de l'image */
            string tmpPath = "./data/png/player/" ;
            tmpPath.append(event->_stringData.at("type")) ;
            if(_displays.size() < 18)
            {
                /* preparer position de l'image selon le type de partie */
                Vector2f tmpSpritePosition(1124, 50) ;
                Vector2f tmpTextPosition(306, 50) ;
                if((tmpPath.substr(0, 22)).compare("./data/png/player/head") == 0)
                {
                    tmpSpritePosition.x += 256 ;
                }
                else if((tmpPath.substr(0, 23)).compare("./data/png/player/chest") == 0)
                {
                    tmpSpritePosition.x += 256 ;
                    tmpSpritePosition.y += 256 ;
                    tmpTextPosition.y += 256 ;
                }
                else if((tmpPath.substr(0, 22)).compare("./data/png/player/legs") == 0)
                {
                    tmpSpritePosition.x += 256 ;
                    tmpSpritePosition.y += 512 ;
                    tmpTextPosition.y += 768 ;
                }
                else if((tmpPath.substr(0, 21)).compare("./data/png/player/arm") == 0)
                {
                    tmpSpritePosition.y += 256 ;
                    tmpTextPosition.y += 512 ;
                    tmpTextPosition.x -= 256 ;
                }
                else if((tmpPath.substr(0, 25)).compare("./data/png/player/leftArm") == 0)
                {
                    tmpSpritePosition.x += 512 ;
                    tmpSpritePosition.y += 256 ;
                    tmpTextPosition.y += 512 ;
                    tmpTextPosition.x += 256 ;
                }

                if((event->_stringData.at("type")).substr(0, 4).compare("left") == 0)
                {
                    tmpPath.replace(18, 5, "a") ;
                }
                tmpPath.append(".png") ;

                _displays.push_back(new DisplaySprite(tmpPath, Color::White, 3, IntRect(0, 0, 256, 256), tmpSpritePosition)) ;
                tmpSpritePosition.x += 192 ; tmpSpritePosition.y += 192 ;
                _displays.push_back(new DisplaySprite("./data/png/icone/reroll.png", Color::White, 3, IntRect(0, 0, 64, 64), tmpSpritePosition)) ;
                string tmpText = event->_stringData.at("name") ;
                tmpText.append("\n\n") ;
                tmpText.append(event->_stringData.at("description")) ;
                _displays.push_back(new DisplayText(tmpText, Vector2f(512, 256), "./data/fonts/arial.ttf", 16, true, false,
                                                    tmpTextPosition, Color::Black, "./data/png/bouton/textBox.png")) ;
            }
            else
            {
                if((event->_stringData.at("type")).substr(0, 4).compare("left") == 0)
                {
                    tmpPath.replace(18, 5, "a") ;
                }
                tmpPath.append(".png") ;
                unsigned short int i ;
                if((event->_stringData.at("type")).substr(0, 4).compare("head") == 0)
                    i = 3 ;
                else if((event->_stringData.at("type")).substr(0, 5).compare("chest") == 0)
                    i = 6 ;
                else if((event->_stringData.at("type")).substr(0, 3).compare("arm") == 0)
                    i = 9 ;
                else if((event->_stringData.at("type")).substr(0, 4).compare("legs") == 0)
                    i = 12 ;
                else if((event->_stringData.at("type")).substr(0, 7).compare("leftArm") == 0)
                    i = 15 ;

                _displays.at(i)->RefreshSprite(tmpPath, 0, Color::White) ;
                string tmpText = event->_stringData.at("name") ;
                tmpText.append("\n\n") ;
                tmpText.append(event->_stringData.at("description")) ;
                _displays.at(i+2)->SetText(0, tmpText, true, Vector2f(512, 256), 16) ;

            }
            DisplayPlayer(false) ;
        }
        else if(event->_type.compare("mouseMoved")==0)
        {
            if(_displays.size() <= 18)
            {
                if(_displays.at(1)->IsContained(0, event->_intData.at("x"), event->_intData.at("y")))
                {
                    if(_selector != -1)
                    {
                        if(_selector == 0 || _selector == 1)
                        {
                            _displays.at(1)->ChangeFrame(_selector, 0) ;
                        }
                        else
                        {
                            _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                        }
                    }
                    _selector = 0 ;
                    _displays.at(1)->ChangeFrame(_selector, 1) ;
                }
                for(unsigned short int i = 3 ; i < 16 ; i+=3)
                {
                    if(_displays.at(i+1)->IsContained(0, event->_intData.at("x"), event->_intData.at("y")) && i%3 == 0)
                    {
                        if(_selector != -1)
                        {
                            if(_selector == 0)
                            {
                                _displays.at(1)->ChangeFrame(_selector, 0) ;
                            }
                            else
                            {
                                _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                            }
                        }
                        _selector = i ;
                        _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                    }
                }
            }
            else
            {
                if(_displays.at(19)->IsContained(0, event->_intData.at("x"), event->_intData.at("y")))
                {
                    if(_selector != -1)
                    {
                        if(_selector == 0)
                        {
                            _displays.at(1)->ChangeFrame(_selector, 0) ;
                        }
                        else if(_selector != 19)
                        {
                            _displays.at(_selector+1)->ChangeFrame(0, 0) ;
                        }
                    }
                    _selector = 19 ;
                    _displays.at(19)->ChangeFrame(0, 1) ;

                }
            }
        }
        else if(event->_type.compare("mousePressed")==0)
        {
            _validator = ON_PLAYER ;
            if(_displays.size() <= 18)
            {
                if(_displays.at(1)->IsContained(0, event->_intData.at("x"), event->_intData.at("y")))
                {
                    EngineEvent* message = new EngineEvent() ;
                    message->_type = "click" ;
                    EngineEvent::SendToSound(message) ;
                    message = NULL ;
                    _displays.at(1)->ChangeFrame(_selector, 2) ;
                }
                else if(_displays.at(_selector)->IsContained(0, event->_intData.at("x"), event->_intData.at("y")) && _selector != 0 && _selector != 1
                         && _selector%3 == 0)
                {
                    _displays.at(_selector+1)->ChangeFrame(0, 2) ;
                }
            }
            else
            {
                if(_displays.at(19)->IsContained(0, event->_intData.at("x"), event->_intData.at("y")))
                {
                    _displays.at(_selector)->ChangeFrame(0, 2) ;
                }
            }
        }
        else if(event->_type.compare("mouseReleased")==0 && _validator == ON_PLAYER)
        {
            if(_displays.size() <= 18)
            {
                if(_displays.at(1)->IsContained(0, event->_intData.at("x"), event->_intData.at("y")))
                {
                    EngineEvent* message = new EngineEvent() ;
                    message->_type = "endStart" ;
                    EngineEvent::SendToCore(message) ;
                    message = NULL ;
                    _displays.at(1)->ChangeFrame(_selector, 0) ;
                    DisplayGame(true) ;
                }
                else if(_displays.at(_selector)->IsContained(0, event->_intData.at("x"), event->_intData.at("y")) && _selector != 0 && _selector != 1
                         && _selector%3 == 0)
                {
                    vector<string> tmp ;
                    tmp.push_back("head") ; tmp.push_back("chest") ; tmp.push_back("arm") ; tmp.push_back("legs") ; tmp.push_back("leftArm") ;

                    EngineEvent* message = new EngineEvent() ;
                    message->_type = "reroll" ;
                    message->_stringData.insert(pair<string,string>("type",tmp.at((_selector-3)/3))) ;
                    EngineEvent::SendToCore(message) ;
                    message = NULL ;
                    _displays.at(_selector+1)->ChangeFrame(0, 1) ;
                }
            }
            else
            {
                cerr << _displays.size() << endl ;
                if(_displays.at(19)->IsContained(0, event->_intData.at("x"), event->_intData.at("y")))
                {
                    _displays.at(_selector)->ChangeFrame(0, 0) ;
                    _selector = -1 ;
                    _displays.erase(_displays.begin()+19) ;
                    _displays.erase(_displays.begin()+18) ;
                    DisplayPlayer(false) ;
                }
            }
            _validator = (Location)(-1) ;
        }
    }
    else if(_currentLocation == ON_GAME)
    {
        if(event->_type.compare("mouseMoved")!=0 && event->_type.compare("mouseClicked")!=0 && event->_type.compare("mouseReleased")!=0)
            cerr << event->_type << endl ;
        if(event->_type.compare("room")==0)
        {
            DisplayGame(true) ;
            if(event->_stringData.at("background").compare("restart")== 0 || event->_stringData.at("background").compare("archive")== 0
               || event->_stringData.at("background").compare("leaveCity")== 0)
            {
                string tmp = "./data/png/background/" ;
                tmp.append(event->_stringData.at("background")) ; tmp.append(".png") ;
                _displays.push_back(new DisplayBackground(tmp)) ;
            }
            else
            {
                string i = Data::ToString(rand()%4) ;
                string tmpBackground = "./data/png/background/", tmpForeground = "./data/png/background/" ;
                (((tmpBackground.append(event->_stringData.at("biome"))).append("-")).append(i)).append(".png") ;
                (tmpForeground.append(event->_stringData.at("background"))).append(".png") ;
                _displays.push_back(new DisplayBackground(tmpBackground, tmpForeground, Color::White, 1, IntRect(0, 0, 0, 0))) ;
            }

            _displays.push_back(new DisplaySprite("./data/png/icone/minerai.png", Color::White, 1, IntRect(0, 0, 64, 64), Vector2f(10, 10))) ;
            _displays.back()->AddText(Vector2f(90, 42), event->_stringData.at("stockOre"), "./data/fonts/steampunk.ttf", Color::White, 20) ;

            _displays.push_back(new DisplaySprite("./data/png/icone/vestige.png", Color::White, 1, IntRect(0, 0, 64, 64), Vector2f(100, 10))) ;
            _displays.back()->AddText(Vector2f(180, 42), event->_stringData.at("stockVestige"), "./data/fonts/steampunk.ttf", Color::White, 20) ;

            _displays.push_back(new DisplaySprite("./data/png/icone/convertion.png", Color::White, 1, IntRect(0, 0, 32, 32), Vector2f(10, 100))) ;

            _displays.push_back(new DisplaySprite("./data/png/icone/steam.png", Color::White, 1, IntRect(0, 0, 64, 512), Vector2f(10, 150))) ;
            _displays.back()->AddText(Vector2f(90, 406), event->_stringData.at("steam"), "./data/fonts/steampunk.ttf", Color::White, 20) ;


            _displays.push_back(new DisplaySprite("./data/png/icone/pressure.png", Color::White, 1, IntRect(0, 0, 256, 256), Vector2f(10, 662))) ;
            string tmp = event->_stringData.at("pressure") ;
            (tmp.append(" / ")).append(event->_stringData.at("maxPressure")) ;
            _displays.back()->AddText(Vector2f(150, 690), tmp, "./data/fonts/steampunk.ttf", Color::White, 20) ;
            tmp = "Integrite : " ; tmp.append(event->_stringData.at("integrity")) ;
            (tmp.append(" / ")).append(event->_stringData.at("maxIntegrity")) ;
            _displays.back()->AddText(Vector2f(150, 730), tmp, "./data/fonts/steampunk.ttf", Color::White, 20) ;
            tmp = "Armure : " ; tmp.append(event->_stringData.at("armor")) ;
            _displays.back()->AddText(Vector2f(150, 770), tmp, "./data/fonts/steampunk.ttf", Color::White, 20) ;
            tmp = "Pression par tour : " ; tmp.append(event->_stringData.at("pressurePerTurn")) ;
            _displays.back()->AddText(Vector2f(150, 810), tmp, "./data/fonts/steampunk.ttf", Color::White, 20) ;

            _displays.push_back(new DisplayText(event->_stringData.at("description"), Vector2f(1024, 512), "./data/fonts/Augusta.ttf", 18, true, true,
                                                    Vector2f(400, 50), Color::Black, "./data/png/bouton/descriptionRoom.png")) ;

            _displays.push_back(new DisplayMenu(Color::Red, "./data/png/bouton/boutonHomeX2.png", "Continuer", IntRect(0, 0, 512, 128),
                                                IntRect(1408, 50, 0, 0), 1)) ;

            DisplayGame(false) ;
        }
        else if(event->_type.compare("playerPart")==0)
        {
            /* preparer chemin de l'image */
            string tmpPath = "./data/png/playerRush/" ;
            tmpPath.append(event->_stringData.at("type")) ;
            /* preparer position de l'image selon le type de partie */
            Vector2f tmpSpritePosition(300, 550) ;
            if((tmpPath.substr(0, 26)).compare("./data/png/playerRush/head") == 0)
            {
                tmpSpritePosition.x += 128 ;
            }
            else if((tmpPath.substr(0, 27)).compare("./data/png/playerRush/chest") == 0)
            {
                tmpSpritePosition.x += 128 ;
                tmpSpritePosition.y += 128 ;
            }
            else if((tmpPath.substr(0, 26)).compare("./data/png/playerRush/legs") == 0)
            {
                tmpSpritePosition.x += 128 ;
                tmpSpritePosition.y += 256 ;
            }
            else if((tmpPath.substr(0, 25)).compare("./data/png/playerRush/arm") == 0)
            {
                tmpSpritePosition.x += 192 ;
                tmpSpritePosition.y += 128 ;
            }
            else if((tmpPath.substr(0, 29)).compare("./data/png/playerRush/leftArm") == 0)
            {
                tmpSpritePosition.x += 192 ;
                tmpSpritePosition.y += 128 ;
            }

            /* Fin du chemin */
            if((event->_stringData.at("type")).substr(0, 4).compare("left") == 0)
            {
                tmpPath.replace(22, 5, "a") ;
            }
            tmpPath.append(".png") ;

            _displays.push_back(new DisplaySprite(tmpPath, Color::White, 3, IntRect(0, 0, 128, 128), tmpSpritePosition)) ;
            DisplayGame(false) ;
        }
        else if(event->_type.compare("PlayerRushIntegrity")==0)
        {

        }
        else if(event->_type.compare("playerMoreIntegrity")==0)
        {

        }
        else if(event->_type.compare("mobPart")==0)
        {
            if(_displays.size() == 13)
            {
                _displays.push_back(new DisplaySprite("./data/png/icone/battle.png", Color::White, 1, IntRect(0, 0, 1024, 256), Vector2f(300, 750))) ;
                cerr << _displays.size() ;
                for(unsigned short int i = 0 ; i < 4 ; i++)
                {
                    _displays.push_back(new DisplaySprite("./data/png/icone/reroll.png", Color::White, 3, IntRect(0, 0, 64, 64), Vector2f(1408+ i*80, 200))) ;
                    _displays.push_back(new DisplaySprite("./data/png/icone/reroll.png", Color::White, 3, IntRect(0, 0, 64, 64), Vector2f(1408+ i*80, 300))) ;
                }
            }
            /* preparer chemin de l'image */
            string tmpPath = "./data/png/mob/" ;
            /* preparer position de l'image selon le type de partie */
            Vector2f tmpSpritePosition(1500, 550) ;
            if(((event->_stringData.at("type")).substr(0, 4)).compare("head") == 0)
            {
                tmpSpritePosition.x += 128 ;
                if(((event->_stringData.at("type")).substr(4,3)).compare("Des") == 0)
                {
                    tmpPath.append("desert/") ;
                }
                else if(((event->_stringData.at("type")).substr(4,3)).compare("Jun") == 0)
                {
                    tmpPath.append("jungle/") ;
                }
                else if(((event->_stringData.at("type")).substr(4,3)).compare("Min") == 0)
                {
                    tmpPath.append("mine/") ;
                }
            }
            else if(((event->_stringData.at("type")).substr(0, 5)).compare("chest") == 0)
            {
                tmpSpritePosition.x += 128 ;
                tmpSpritePosition.y += 128 ;
                if(((event->_stringData.at("type")).substr(5,3)).compare("Des") == 0)
                {
                    tmpPath.append("desert/") ;
                }
                else if(((event->_stringData.at("type")).substr(5,3)).compare("Jun") == 0)
                {
                    tmpPath.append("jungle/") ;
                }
                else if(((event->_stringData.at("type")).substr(5,3)).compare("Min") == 0)
                {
                    tmpPath.append("mine/") ;
                }
            }
            else if(((event->_stringData.at("type")).substr(0, 4)).compare("legs") == 0)
            {
                tmpSpritePosition.x += 128 ;
                tmpSpritePosition.y += 256 ;
                if(((event->_stringData.at("type")).substr(4,3)).compare("Des") == 0)
                {
                    tmpPath.append("desert/") ;
                }
                else if(((event->_stringData.at("type")).substr(4,3)).compare("Jun") == 0)
                {
                    tmpPath.append("jungle/") ;
                }
                else if(((event->_stringData.at("type")).substr(4,3)).compare("Min") == 0)
                {
                    tmpPath.append("mine/") ;
                }
            }
            else if(((event->_stringData.at("type")).substr(0, 3)).compare("arm") == 0)
            {
                tmpSpritePosition.x += 64 ;
                tmpSpritePosition.y += 128 ;
                if(((event->_stringData.at("type")).substr(3,3)).compare("Des") == 0)
                {
                    tmpPath.append("desert/") ;
                }
                else if(((event->_stringData.at("type")).substr(3,3)).compare("Jun") == 0)
                {
                    tmpPath.append("jungle/") ;
                }
                else if(((event->_stringData.at("type")).substr(3,3)).compare("Min") == 0)
                {
                    tmpPath.append("mine/") ;
                }
            }

            tmpPath.append(event->_stringData.at("type")) ;
            tmpPath.append(".png") ;

            _displays.push_back(new DisplaySprite(tmpPath, Color::White, 3, IntRect(0, 0, 128, 128), tmpSpritePosition)) ;
            DisplayGame(false) ;
        }
        else if(event->_type.compare("rushPressure")==0)
        {

        }
        else if(event->_type.compare("mouseMoved")==0)
        {
            if(_displays.at(7)->IsContained(0, event->_intData.at("x"), event->_intData.at("y")))
            {
                if(_selector != -1)
                {
                    _displays.at(_selector)->ChangeFrame(0, 0) ;
                }
                _selector = 7 ;
                _displays.at(_selector)->ChangeFrame(0, 1) ;
            }
            if(_displays.size() > 13)
            {
                for(unsigned int i = 0 ; i < 8 ; i++)
                {

                    if(_displays.at(i+14)->IsContained(0, event->_intData.at("x"), event->_intData.at("y")))
                    {
                        if(_selector != -1)
                        {
                            _displays.at(_selector)->ChangeFrame(0, 0) ;
                        }
                        _selector = i+14 ;
                        _displays.at(_selector)->ChangeFrame(0, 1) ;
                    }
                }
            }
        }
        else if(event->_type.compare("mousePressed")==0)
        {
            _validator = ON_GAME ;
            if(_displays.at(7)->IsContained(0, event->_intData.at("x"), event->_intData.at("y")))
            {
                EngineEvent* message = new EngineEvent() ;
                message->_type = "click" ;
                EngineEvent::SendToSound(message) ;
                message = NULL ;
                _displays.at(_selector)->ChangeFrame(0, 2) ;
            }

        }
        else if(event->_type.compare("mouseReleased")==0 && _validator == ON_GAME)
        {
            if(_displays.at(7)->IsContained(0, event->_intData.at("x"), event->_intData.at("y")))
            {
                EngineEvent* message = new EngineEvent() ;
                message->_type = "leaveRoom" ;
                EngineEvent::SendToCore(message) ;
                message = NULL ;
                _displays.at(_selector)->ChangeFrame(0, 0) ;
                DisplayGame(true) ;
            }
            _validator = (Location)(-1) ;
        }
        else if(event->_type.compare("keyPressed")==0)
        {
            if(event->_stringData.at("key").compare("escape")==0)
            {
//                EngineEvent* message = new EngineEvent() ;
//                message->_type = "endRush" ;
//                EngineEvent::SendToCore(message) ;
//                message = NULL ;
                DisplayHome(true) ;
            }
        }
        else if(event->_type.compare("keyReleased")==0)
        {
            if(event->_stringData.at("key").compare("up")==0)
            {
                if(_selector >= 14 && _selector <= 22)
                {
                    _displays.at(_selector)->RefreshSprite("./data/png/icone/flecheHaut.png", 0, Color::White) ;
                }
                DisplayGame(false) ;
            }
            else if(event->_stringData.at("key").compare("down")==0)
            {
                if(_selector >= 14 && _selector <= 22)
                {
                    _displays.at(_selector)->RefreshSprite("./data/png/icone/flecheBas.png", 0, Color::White) ;
                }
                DisplayGame(false) ;
            }
            else if(event->_stringData.at("key").compare("left")==0)
            {
                if(_selector >= 14 && _selector <= 22)
                {
                    _displays.at(_selector)->RefreshSprite("./data/png/icone/flecheGauche.png", 0, Color::White) ;
                }
                DisplayGame(false) ;
            }
            else if(event->_stringData.at("key").compare("right")==0)
            {
                if(_selector >= 14 && _selector <= 22)
                {
                    _displays.at(_selector)->RefreshSprite("./data/png/icone/flecheDroite.png", 0, Color::White) ;
                }
                DisplayGame(false) ;
            }
            _selector = -1 ;
        }
    }
    else if(_currentLocation == ON_OPTIONS)
    {

    }
    else if(_currentLocation == ON_CREDITS)
    {
        if(event->_type.compare("keyReleased")==0)
        {
            if(event->_stringData.at("key").compare("escape")==0)
            {
                DisplayHome(true) ;
            }
        }
        if(event->_type.compare("credit")==0)
        {
            _displays.push_back(new DisplayText(event->_stringData.at("credit"), Vector2f(1000, 540), "./data/fonts/arial.ttf", 20, false, false,
                                                Vector2f(460, 400), Color::White, "")) ;
            DisplayCredits(false) ;
        }
    }
}
