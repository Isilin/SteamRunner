#include <cstdlib>
#include "Application.hpp"
#include "TypeEngine.hpp"
#include <iostream>

int main(){
    Application* app = new Application() ;

// Parcourir une enum :
//
//    TypeEngine i = TypeEngine::NONE ; i = TypeEngine(int(i)+1) ;
//    while(i != TypeEngine::NONE_END){
//        std::cout << int(i) << std::endl ;
//        i = TypeEngine(int(i)+1) ;
//    }
//
    app->Run() ;
    delete(app) ;

    return EXIT_SUCCESS;
}
