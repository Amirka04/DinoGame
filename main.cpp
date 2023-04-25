#include "SFML/Graphics.hpp"
#include "GL/gl.h"
#include "iostream"

#include "platforma/platformObject.hpp"
#include "BackGround/BackGround.hpp"
#include "Dino/Dino.h"


#define WH 640
#define WW 1024
#define dW (float)WH/WW

using namespace sf;


int main(){
    printf("\nВся графика написана на SFML 2.5, OpenGL, C++ \nGitHub: https://github.com/Amirka04/DinoGame\n\n");

//  Создаём окно
    RenderWindow window(VideoMode(WW, WH), "Dino Game");

//     перед тем как начать анимировать что либо, я сначала инициализирую анимацию (Ускорение, Максимальная скорость)
    Animate::SetGlobalInit(0.015, 0.0000001);

//     создаю персонажа "Динозаврик"
    Dino *dino = new Dino(Animate("../texture/DinoAnimate/", 0.003), Vector2d(-0.75, -0.55), Vector2d(0.25, 0.25), dW);

// Создам несколько фоновых элементов
    BackObject *Fon = new BackObject( Textures("../texture/background 0.png"), Vector2d(0,0), Vector2d(1,1) );
    BackObject *Sun = new BackObject( Textures("../texture/sun.png"), Vector2d(-.3,.7), Vector2d(0.1*dW,0.1) );

    /*
    Vector2d(0.25,0.10)
    Vector2d(0,0)
     */

    // Добавляю все эти текстры в общий массив одного данного объекта
    platform_array *plato = new platform_array(0.02, 0.000001, 0.2);
    plato->AddTexture("../texture/GroupSand/sand.png");
    plato->AddTexture("../texture/GroupSand/sand1.png");
    plato->AddTexture("../texture/GroupSand/sand2.png");
    plato->AddTexture("../texture/GroupSand/sand3.png");


    for(float i = 1.5; i > -1.5; i-=0.2)
        plato->AddPlatform(Vector2d(i,-1), Vector2d(0.2, 0.2));



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
                delete plato;
            }
        }

        // очищаю экран
        glClearColor(0.5, 0.5, 0.5, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        // Главный фон будет всегда рисоваться первым,
        Fon->show();

//      фон, но не главный, будет рисоваться после главного фона
        Sun->show();

//      нарисуем платформу так же, до рисования игрока, надо ж ему на чём-то стоять
        plato->show();

        // рисую нашего персонажа его буду рисовать всегда последним, т.к. его должно быть видно
        dino->draw();


        // отображаю всё что мы ранее рисовали
        window.display();
    }


    return 0;
}
