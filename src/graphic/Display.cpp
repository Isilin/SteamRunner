/**
 * @file     Display.cpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Methods of class Display.
 */

#include "Display.hpp"

using namespace std ;
using namespace sf ;
#include <iostream>

Display::Display() : _sprites(), _strings(), _texts(), _font()
{
}

Display::Display(const string path,
                 const Vector2f position,
                 const uint16 nbClips,
                 const IntRect clip) : _sprites(), _strings(), _texts(), _font()
{
    Sprite tmp ;
    if(!tmp.texture.loadFromFile(path))
    {
        cerr << "Error of loading from : " << path << "to a sf::Texture." << endl ;
    }
    else
    {
        tmp.clip = clip ;
        if(nbClips > 1)
        {
            tmp.sprite.setTextureRect(tmp.clip) ;
        }
        tmp.sprite.setOrigin(Vector2f(-position.x, -position.y)) ;
        tmp.sprite.setScale((float)(VideoMode::getDesktopMode().width/1920.0), (float)(VideoMode::getDesktopMode().height/1080.0)) ;

    }
    tmp.currentFrame = 0 ;
    tmp.nbClips = nbClips ;
    _sprites.push_back(tmp) ;
}

Display::Display(const string path,
                 const Color layer,
                 const Vector2f position,
                 const uint16 nbClips,
                 const IntRect clip) : _sprites(), _texts(), _font()
{
    Sprite tmp ;

    Image image ;
    if(!image.loadFromFile(path))
    {
        cerr << "Error of loading from : " << path << "to a sf::Image." << endl ;
    }
    else
    {
        image.createMaskFromColor(layer) ;
        tmp.texture.loadFromImage(image) ;
        tmp.clip = clip ;
        if(nbClips > 1)
        {
            tmp.sprite.setTextureRect(clip) ;
        }
        tmp.sprite.setOrigin(Vector2f(-position.x, -position.y)) ;
        tmp.sprite.setScale((float)(VideoMode::getDesktopMode().width/1920.0), (float)(VideoMode::getDesktopMode().height/1080.0)) ;
    }
    tmp.currentFrame = 0 ;
    tmp.nbClips = nbClips ;
    _sprites.push_back(tmp) ;
}

Display::Display(const Vector2f position,
                 const string text,
                 const string pathFont,
                 const Color fontColor,
                 const uint16 fontSize) : _sprites(), _strings(), _texts(), _font()
{
    if(!_font.loadFromFile(pathFont))
    {
            cerr << "Error of loading from : " << pathFont << "to a sf::Font." << endl ;
    }
    else
    {
        _strings.push_back(text) ;
        Text tmp(_strings.back(), _font, fontSize) ;
        tmp.setColor(fontColor) ;
        tmp.setOrigin(Vector2f(-position.x + tmp.getGlobalBounds().width/2, -position.y + tmp.getGlobalBounds().height/2)) ;
        tmp.setScale((float)(VideoMode::getDesktopMode().width/1920.0), (float)(VideoMode::getDesktopMode().height/1080.0)) ;
        _texts.push_back(tmp) ;
    }
}

Display::~Display()
{
    _sprites.clear() ;
    _strings.clear() ;
    _texts.clear() ;
}

const bool Display::AddSprite(const string path,
                        const uint16 nbClips,
                        const Vector2f position,
                        const IntRect clip)
{
    Sprite tmp ;
    tmp.currentFrame = 0 ;
    tmp.nbClips = nbClips ;

    if(nbClips <= 1 && !_sprites.back().texture.loadFromFile(path))
    {
        cerr << "Error of loading from : " << path << "to a sf::Texture." << endl ;
        return false ;
    }
    else
    {
        tmp.clip = clip ;
        if(nbClips > 1)
        {
            tmp.sprite.setTextureRect(_sprites.front().clip) ;
        }
        tmp.sprite.setOrigin(Vector2f(-position.x, -position.y)) ;
        tmp.sprite.setScale((float)(VideoMode::getDesktopMode().width/1920.0), (float)(VideoMode::getDesktopMode().height/1080.0)) ;
        _sprites.push_back(tmp) ;
        return true ;
    }
}

const bool Display::AddSprite(const string path,
                        const Color layer,
                        const uint16 nbClips,
                        const Vector2f position,
                        const IntRect clip)
{
    Display::Sprite tmp ;
    tmp.currentFrame = 0 ;
    tmp.nbClips = nbClips ;

    Image image ;
    if(!image.loadFromFile(path))
    {
        cerr << "Error of loading from : " << path << "to a sf::Image." << endl ;
        return false ;
    }
    else
    {
        image.createMaskFromColor(layer) ;
        tmp.texture.loadFromImage(image) ;
        tmp.clip = clip ;
        if(nbClips > 1)
        {
            tmp.sprite.setTextureRect(tmp.clip) ;
        }
        tmp.sprite.setOrigin(Vector2f(-position.x, -position.y)) ;
        tmp.sprite.setScale((float)(VideoMode::getDesktopMode().width/1920.0), (float)(VideoMode::getDesktopMode().height/1080.0)) ;
        _sprites.push_back(tmp) ;
        return true ;
    }
}

const bool Display::AddText(const Vector2f position,
                            const string text,
                            const string pathFont,
                            const Color fontColor,
                            const uint16 fontSize)
{
    if(!_font.loadFromFile(pathFont))
    {
            cerr << "Error of loading from : " << pathFont << "to a sf::Font." << endl ;
            return false ;
    }
    else
    {
        _strings.push_back(text) ;
        Text tmp(_strings.back(), _font, fontSize) ;
        tmp.setColor(fontColor) ;
        tmp.setOrigin(Vector2f(-position.x + tmp.getGlobalBounds().width/2, -position.y + tmp.getGlobalBounds().height/2)) ;
        tmp.setScale((float)(VideoMode::getDesktopMode().width/1920.0), (float)(VideoMode::getDesktopMode().height/1080.0)) ;
        _texts.push_back(tmp) ;
        return true ;
    }
}

const bool Display::RefreshFont(const std::string pathFont)
{
    if(!_font.loadFromFile(pathFont))
    {
        cerr << "Error of loading from : " << pathFont << "to a sf::Font." << endl ;
        return false ;
    }
    else
    {
        for(vector<Text>::iterator i = _texts.begin() ; i != _texts.end() ; ++i)
        {
            i->setFont(_font) ;
        }
        return true ;
    }
}

const bool Display::RefreshSprite(const std::string pathSprite, const unsigned short int indiceArray, const Color layer)
{
    Image image ;
    if(!image.loadFromFile(pathSprite))
    {
        cerr << "Error of loading from : " << pathSprite << "to a sf::Image." << endl ;
        return false ;
    }
    else
    {
        image.createMaskFromColor(layer) ;
        _sprites.at(indiceArray).texture.loadFromImage(image) ;
        return true ;
    }
}

void Display::SetText(const uint16 indiceArray, const string text, const bool splitted, const Vector2f sizeBox, const unsigned short int fontSize)
{
    string tmpString = text ;
    if(splitted)
    {
        unsigned int tmp = 2*sizeBox.x / fontSize ;
        unsigned int next = 0, last = 0 ;
        while(tmpString.size() - last > tmp)
        {
            if(last!=string::npos && tmpString.find("\n", last+1) - last < tmp)
            {
                last = tmpString.find("\n", last+1) ;
            }
            else
            {
                if(next<last)
                {
                    next = tmpString.find(" ", last) ;
                    if( next == string::npos )
                    {
                        next = tmpString.size() ;
                    }
                }
                if(next != tmpString.size() && tmpString.find(" ", next+1) > last + tmp)
                {
                    tmpString.replace(next, 1, string("\n")) ;
                    last = next ;
                }
                next = tmpString.find(" ", next+1) ;
                if( next == string::npos )
                {
                    next = tmpString.size() ;
                }
                if((next - last) > tmp)
                {
                    tmpString.insert(last + tmp, string("\n")) ;
                    last += tmp ;
                }
            }
        }
    }
    _strings.at(indiceArray) = tmpString ;
    _texts.at(indiceArray).setString(tmpString) ;
}

void Display::SetPosition(const Type type, const uint16 indiceArray, const sf::Vector2f position)
{
    if(type == SPRITE && indiceArray < _sprites.size())
    {
        _sprites.at(indiceArray).sprite.setPosition(position) ;
        _sprites.at(indiceArray).sprite.setScale((float)(VideoMode::getDesktopMode().width/1920.0), (float)(VideoMode::getDesktopMode().height/1080.0)) ;
    }
    else if(type == TEXT && indiceArray < _texts.size())
    {
        _texts.at(indiceArray).setOrigin(position) ;
        _texts.at(indiceArray).setScale((float)(VideoMode::getDesktopMode().width/1920.0), (float)(VideoMode::getDesktopMode().height/1080.0)) ;
    }
}

void Display::ChangeFrame(const uint16 indiceArray,
                          const uint16 currentFrame)
{
    if(currentFrame <= _sprites.at(indiceArray).nbClips)
    {
        _sprites.at(indiceArray).currentFrame = currentFrame ;
        _sprites.at(indiceArray).clip.top = _sprites.at(indiceArray).clip.height * _sprites.at(indiceArray).currentFrame ;
        _sprites.at(indiceArray).sprite.setTextureRect(_sprites.at(indiceArray).clip) ;
    }
    else
    {
        cerr << "This clip (" << indiceArray << ") does not exist ; the sprite has just " << _sprites.at(indiceArray).nbClips << " clips." << endl ;
    }
}

void Display::Rotate(const Type type, const uint16 indiceArray, const float angle)
{
    if(type == SPRITE)
    {
        _sprites.at(indiceArray).sprite.rotate(angle) ;
    }
    else
    {
        _texts.at(indiceArray).rotate(angle) ;
    }
}

bool Display::IsContained(uint16 indiceArray, int x, int y)
{
    IntRect tmp(_sprites.at(indiceArray).sprite.getTextureRect()) ;
    tmp.left = -_sprites.at(indiceArray).sprite.getOrigin().x ;
    tmp.top = -_sprites.at(indiceArray).sprite.getOrigin().y ;

    //scale
    int tmpX = x * 1920 / VideoMode::getDesktopMode().width ;
    int tmpY = y * 1080 / VideoMode::getDesktopMode().height ;

    return tmp.contains(tmpX, tmpY) ;
}

void Display::Refresh()
{
    for(vector<Display::Sprite>::iterator i = _sprites.begin() ; i != _sprites.end() ; ++i)
    {
        i->sprite.setTexture(i->texture) ;
    }
    for(uint16 i = 0 ; i < _texts.size() ; i++)
    {
        _texts.at(i).setString(_strings.at(i)) ;
    }
}

void Display::DisplayOn(sf::RenderWindow* window) const
{
    for(vector<Display::Sprite>::const_iterator i = _sprites.begin() ; i != _sprites.end() ; ++i)
    {
        window->draw(i->sprite) ;
    }
    for(vector<Text>::const_iterator i = _texts.begin() ; i != _texts.end() ; ++i)
    {
        window->draw(*i) ;
    }
}
