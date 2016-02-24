/**
 * @file     DisplayBackground.cpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Methods of class DisplayBackground.
 */

#include "DisplayBackground.hpp"
#include <iostream>

using namespace std ;
using namespace sf ;

DisplayBackground::DisplayBackground(const string backgroundPath) : Display(backgroundPath, Vector2f(0,0))
{
}

DisplayBackground::DisplayBackground(const string backgroundPath,
                                     const string foregroundPath,
                                     const Color layer,
                                     const uint16 nbClips,
                                     const IntRect clip) : Display(backgroundPath, Vector2f(0,0))
{
    Display::AddSprite(foregroundPath, layer, nbClips, Vector2f(0, 0), clip) ;
}

DisplayBackground::~DisplayBackground()
{
}
