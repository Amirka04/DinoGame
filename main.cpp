#include <SFML/Graphics.hpp>
#include <GL/gl.h>
#include <iostream>

#include "Platform/Platform.hpp"
#include "Dino/Dino.h"

#define WH 640
#define WW 1024
#define dW (float)WH / (float)WW



using namespace sf;



int main(){
    printf("\nВся графика написана на SFML 2.5, OpenGL, C++ \nGitHub: https://github.com/Amirka04/DinoGame\n\n");

    RenderWindow window(VideoMode(WW, WH), "Dino");
    
    Dino *dino = new Dino(Animate("../texture/DinoAnimate/", 0.003), Vector2d(-0.75, -0.5), Vector2d(0.25 * dW, 0.25));


    // пусть пока что будут 6 платформ
    int size_arr = 11;
    Platform *platforms = new Platform[size_arr];
    const char *namefile = "../texture/GroupSand/sand.png";

    printf("\n\nLet's play!!! :3\n\n");
    

    float y0 = 1.4;
    for(int i = 0; i < size_arr; i++){
        platforms[i].SetVolume(namefile, Vector2d(y0 - (0.25*2) * i, -0.85), Vector2d(0.25*dW, 0.15), 0.0001 * dW);
        platforms[i].SetMaxSpeed(0.0008);
    }

    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed){
                window.close();
            }
        }
        
        glClearColor(0.5, 0.5, 0.5, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        
        for(int i = 0; i < size_arr; i++)
            platforms[i].draw();

        dino->draw();

        window.display();
    }


    return 0;
}
