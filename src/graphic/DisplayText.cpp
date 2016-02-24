/**
 * @file     DisplayText.cpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Methods of class DisplayText.
 */

#include "DisplayText.hpp"

#include <iostream>
using namespace std ;
using namespace sf ;

DisplayText::DisplayText(const string text,
                         const Vector2f sizeBox,
                         const string pathFont,
                         const uint16 fontSize,
                         const bool splitted,
                         const bool moved,
                         const Vector2f position,
                         const sf::Color fontColor,
                         const string pathBox) : Display(position, text, pathFont, fontColor, fontSize)
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

    SetText(0, tmpString) ;
    Vector2f tmpPosition ;
    if(moved)
    {
        if(sizeBox.x > 1920-position.x)
        {
            if(sizeBox.y > 1080-position.y)
            {
                tmpPosition = Vector2f(-position.x + sizeBox.x, -position.y + sizeBox.y) ;
            }
            else
            {
                tmpPosition = Vector2f(-position.x + sizeBox.x, -position.y) ;
            }
        }
        else if(sizeBox.y > 1080-position.y)
        {
            tmpPosition = Vector2f(-position.x, -position.y + sizeBox.y) ;
        }
        else
        {
            tmpPosition = Vector2f(-position.x, -position.y) ;
        }
    }
    else
    {
        tmpPosition = Vector2f(-position.x, -position.y) ;
    }
    SetPosition(Display::TEXT, 0, tmpPosition) ;
    tmpPosition -= tmpPosition + tmpPosition + Vector2f(2*fontSize, 2*fontSize); /* équivaut à tmpPosition = Vector2f(-tmpPosition.x, -tmpPosition.y) ; */

    if(pathBox.size()!=0)
    {
        AddSprite(pathBox, Color::White, 1, tmpPosition, IntRect(0, 0, 512, 256)) ;
    }
}

DisplayText::~DisplayText()
{

}

void DisplayText::Refresh()
{
    Display::Refresh() ;
}
