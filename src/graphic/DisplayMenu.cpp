/**
 * @file     DisplayMenu.cpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Methods of class DisplayMenu.
 */

#include "DisplayMenu.hpp"

using namespace std ;
using namespace sf ;
#include <iostream>
#include "../core/Data.hpp"

DisplayMenu::DisplayMenu(const Color filter,
                         const string path,
                         const string text,
                         const IntRect sizeSprite,
                         const IntRect position,
                         const uint16 nbButtons) : Display(path, filter, Vector2f(position.left, position.top), (uint16)3, sizeSprite)
{
    vector<string> tmp(Data::SplitString(text, " ")) ;
    uint16 tmpX = position.left + _sprites.front().sprite.getLocalBounds().width/2 ;
    uint16 tmpY = position.top + _sprites.front().sprite.getLocalBounds().height/2 ;
    Display::AddText(Vector2f(tmpX, tmpY), tmp.at(0), "./data/fonts/steampunk.ttf") ;

    for(uint16 i = 1 ; i < nbButtons ; i++)
    {
        Display::AddSprite(path, filter, (uint16)3, Vector2f(position.left + i*position.width, position.top+ i*position.height), sizeSprite) ;
        Display::AddText(Vector2f(tmpX + i*position.width, tmpY + i*position.height), tmp.at(i), "./data/fonts/steampunk.ttf") ;
        _texts.back().setString(tmp.at(i));
    }
}

DisplayMenu::~DisplayMenu()
{
}

void DisplayMenu::Refresh()
{
    Display::Refresh() ;
}
