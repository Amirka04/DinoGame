#include "SFML/Graphics.hpp"
#include "GL/gl.h"
#include "iostream"

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
    Dino *dino = new Dino(Animate("../texture/DinoAnimate/", 0.003), Vector2d(-0.75, -0.65), Vector2d(0.25, 0.25), dW);

// Создам несколько фоновых элементов
    BackObject *Fon = new BackObject( Textures("../texture/background 0.png"), Vector2d(0,0), Vector2d(1,1) );
    BackObject *Sun = new BackObject( Textures("../texture/sun.png"), Vector2d(-.3,.7), Vector2d(0.15*dW,0.15) );


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
            }
        }

        // очищаю экран
        glClearColor(0.5, 0.5, 0.5, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        // Главный фон будет всегда рисоваться первым,
        Fon->show();
//         фон, но не главный, будет рисоваться после главного фона
        Sun->show();

        // рисую нашего персонажа
        dino->draw();



        // отображаю всё что мы ранее рисовали
        window.display();
    }


    return 0;
}
