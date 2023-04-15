#include <SFML/Graphics.hpp>
#include <GL/gl.h>
#include <iostream>

// #include "Platform/Platform.hpp"
#include "Dino/Dino.h"
// #include "Kaktus/Kaktus.h"

#define WH 640
#define WW 1024
#define dW (WH < WW) ? (float)WH/WW : (float)WW/WH

using namespace sf;


int main(){
    printf("\nВся графика написана на SFML 2.5, OpenGL, C++ \nGitHub: https://github.com/Amirka04/DinoGame\n\n");

    RenderWindow window(VideoMode(WW, WH), "Dino Game");
    
    // создаю персонажа "Динозаврик"
    Dino *dino = new Dino(Animate("../texture/DinoAnimate/", 0.003), Vector2d(-0.75, -0.5), Vector2d(0.25, 0.25), dW);


    printf("\n\nLet's play!!! :3\n\n");
    

    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed){
                window.close();
                // после закрытия окна подчистим за собой :)
                delete dino;
            }
        }
        
        glClearColor(0.5, 0.5, 0.5, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        
        


        dino->draw();

        window.display();
    }


    return 0;
}
