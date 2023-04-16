#include "SFML/Graphics.hpp"
#include "GL/gl.h"
#include "iostream"

// #include "Platform/Platform.hpp"
// #include "Kaktus/Kaktus.h"
#include "BackGround/Background.h"
#include "Dino/Dino.h"

#define WH 640
#define WW 1024
#define dW (float)WH/WW

using namespace sf;


int main(){
    printf("\nВся графика написана на SFML 2.5, OpenGL, C++ \nGitHub: https://github.com/Amirka04/DinoGame\n\n");

    RenderWindow window(VideoMode(WW, WH), "Dino Game");
    

//     перед тем как начать анимировать что либо, я сначала инициализирую анимацию (Ускорение, Максимальная скорость)
    Animate::SetGlobalInit(0.015, 0.0000001);

//     создаю персонажа "Динозаврик"
    Dino *dino = new Dino(Animate("../texture/DinoAnimate/", 0.003), Vector2d(-0.75, -0.65), Vector2d(0.25, 0.25), dW);

//  Добавим фон в игру
    BackObject *Fon = new BackObject(Textures("../texture/background 0.png"), Vector2d(0, 0),  Vector2d(1, 1));




    printf("\n\nLet's play!!! :3\n\n");
    

    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed){
                window.close();
                // после закрытия окна подчистим за собой :)
                delete dino;
                delete Fon;
            }
        }
        
        glClearColor(0.5, 0.5, 0.5, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        Fon->show();


        dino->draw();

        window.display();
    }


    return 0;
}
