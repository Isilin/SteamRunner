/**
 * @file     DisplaySprite.cpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Methods of class DisplaySprite.
 */

#include "DisplaySprite.hpp"

using namespace std ;
using namespace sf ;
#include <iostream>


DisplaySprite::DisplaySprite(const string pathSprite,
                             const sf::Color layer,
                             const uint16 nbClips,
                             const IntRect sizeClip,
                             const Vector2f position) : Display(pathSprite, layer, position, nbClips, sizeClip)
{

}

DisplaySprite::~DisplaySprite()
{

}

void DisplaySprite::Refresh()
{
    Display::Refresh() ;
}
