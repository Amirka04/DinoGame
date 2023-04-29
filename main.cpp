#include "SFML/Graphics.hpp"
#include "GL/gl.h"
#include "iostream"

#include "Kaktus/Kaktus.h"
#include "platforma/platformObject.hpp"
#include "BackGround/BackGround.hpp"
#include "Dino/Dino.h"

#include "random"

#define WH 640
#define WW 1024
#define dW (float)WH/WW

using namespace sf;


int main(){
    printf("\nВся графика написана на SFML 2.5, OpenGL, C++ \nGitHub: https://github.com/Amirka04/DinoGame\n\n");

//  Создаём окно
    RenderWindow window(VideoMode(WW, WH), "Dino Game");
    window.setFramerateLimit(120);

//     перед тем как начать анимировать что либо, я сначала инициализирую анимацию (Ускорение, Максимальная скорость)
    Animate::SetGlobalInit(0.04, 0.000009);

//     создаю персонажа "Динозаврик"
    Dino *dino = new Dino(Animate("../texture/DinoAnimate/", 0.01), Vector2d(-0.75, -0.55), Vector2d(0.22, 0.22), dW);

// Создам несколько фоновых элементов
    BackObject *Fon = new BackObject( Textures("../texture/background 0.png"), Vector2d(0,0), Vector2d(1,1) );
    BackObject *Sun = new BackObject( Textures("../texture/sun.png"), Vector2d(-.3,.7), Vector2d(0.1*dW,0.1) );

    // создаю несколько платформ
    int SizePlatform = 8;
    Platforma a[SizePlatform];
    a[0].SetTexture("texture/sand.png");

    for(int i = 0; i < SizePlatform; i++){
        a[i].SetSpeed(-0.001, -0.000001, -0.02);
        a[i].SetBorder(1.3);
        a[i].SetObject( Vector2d(1.3 - (0.15*2 * i), -.85), Vector2d(0.25, 0.15) );
    }


//  Весёлая надпись
    printf("\n\nLet's play!!! :3\n\n");
    

    // главный цикл игры
    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed){
                window.close();
                // после закрытия окна подчистим за собой :)
                delete dino;
                delete Fon;
                delete Sun;
            }
        }

        // очищаю экран
        glClearColor(0.5, 0.5, 0.5, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        // Главный фон будет всегда рисоваться первым,
        Fon->show();

//      фон, но не главный, будет рисоваться после главного фона
        Sun->show();

        // рисование платформы
        for(int i = 0; i < SizePlatform; i++)
            a[i].Show();

        // рисую нашего персонажа его буду рисовать всегда последним, т.к. его должно быть видно
        dino->draw();

        // отображаю всё что мы ранее рисовали
        window.display();
    }


    std::cout << "\033[92mGoodbuy!!!\033[0m" << std::endl;

    return 0;
}



