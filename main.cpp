#include <SFML/Graphics.hpp>
#include <GL/gl.h>
#include <iostream>

#include "Platform/Platform.hpp"
#include "Dino/Dino.h"

using namespace sf;



int main(){

    RenderWindow window(VideoMode(640, 640), "Dino");
    
    Dino dino(Animate((char*)"../texture/DinoAnimate/", 0.004), Vector2d(-0.65,-0.2), Vector2d(0.2,0.2));

    printf("\n\nLet's play!!! :3\n\n");


    Platform pl("../texture/GroupSand/sand.png", Vector2d(-0.65,-0.5), Vector2d(0.2,0.1), 0.004);


    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed){
                window.close();
            }
        }
        
        glClearColor(0.5, 0.5, 0.5, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        
        dino.draw();
        pl.draw();

        window.display();
    }


    return 0;
}
