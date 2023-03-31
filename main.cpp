#include <SFML/Graphics.hpp>
#include <GL/gl.h>
#include <iostream>


#include "Dino/Dino.h"

using namespace sf;

int main(){

    RenderWindow window(VideoMode(640, 640), "Dino");
    
    Dino dino(Animate((char*)"../texture/DinoAnimate/", 0.003), Vector2d(-0.65,-0.2), Vector2d(0.2,0.2));
    

    
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
        

        window.display();
    }


    return 0;
}