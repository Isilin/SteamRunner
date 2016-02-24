/**
 * @file     main.cpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    The main function.
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "./core/Data.hpp"
#include <iostream>

#include "Game.hpp"

int main(int argc, char** argv)
{
    Data::InitData() ;
    srand(time(NULL)) ;
    Game* game ;
    game = new Game ;

    game->Run() ;

    if(!game->IsRunning())
    {
        delete game ;
    }

    Data::CloseData() ;
    return EXIT_SUCCESS;
}
