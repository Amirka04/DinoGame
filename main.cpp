#include <SFML/Graphics.hpp>
#include <GL/gl.h>
#include <iostream>

#include "Platform/Platform.hpp"
#include "Dino/Dino.h"

using namespace sf;



int main(){
    printf("\nВся графика написана на SFML 2.5, OpenGL, C++ \nGitHub: https://github.com/Amirka04/DinoGame\n\n");

    RenderWindow window(VideoMode(640, 640), "Dino");
    
    Dino dino(Animate((char*)"../texture/DinoAnimate/", 0.004), Vector2d(-0.65,-0.2), Vector2d(0.2,0.2));


    // пусть пока что будут 6 платформ
    int size_arr = 10;
    Platform platforms[size_arr];
    const char *namefile = "../texture/GroupSand/sand.png";

    printf("\n\nLet's play!!! :3\n\n");
    

    float y0 = 1.4;
    for(int i = 0; i < size_arr; i++)
        platforms[i].SetVolume(namefile, Vector2d(y0 - (0.2*2) * i, -0.5), Vector2d(0.2, 0.1), 0.00015);
    

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

        for(int i = 0; i < size_arr; i++)
            platforms[i].draw();

        window.display();
    }


    return 0;
}
