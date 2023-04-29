#include "Dino.h"
#include "SFML/Graphics.hpp"
#include "GL/gl.h"

#include "stdio.h"

using namespace sf;

// Конструктор без параметров
Dino::Dino(){
    printf("Динозавр инициализирован\n");
}

// Конструктор с параметрами: Класс анимации, Вектор(расположения), Вектор(Размера)
Dino::Dino(Animate AnimateDino, Vector2d coord, Vector2d size):Animate(AnimateDino){
    printf("Динозавр инициализирован\n");
    
    this->coord = coord;
    this->size = size;
    for(int i = 0; i < arr_size; i++){
        // устанавливаем размер
        VertexArray[i] *= this->size;
        // подвинем точку в нужное место
        VertexArray[i] += this->coord;
    }
}

// Конструктор с теми же параметрами, но уже с изменением окна
Dino::Dino(Animate AnimateDino, Vector2d coord, Vector2d size, float dWind):Animate(AnimateDino){
    printf("Динозавр инициализирован\n");
    
    this->coord = coord;
    
    this->size = size;
    this->size.x *= dWind;

    for(int i = 0; i < arr_size; i++){
        // устанавливаем размер
        VertexArray[i] *= this->size;
        // подвинем точку в нужное место
        VertexArray[i] += this->coord;
    }
}    

// Деструктор для удаления диномического массива
Dino::~Dino(){
    delete [] VertexArray;
    delete [] AnimateIndex;
}

//рисование и проигрывание анимации Динозаврика
void Dino::draw(){

    RunAnimation();

    glBindTexture(GL_TEXTURE_2D, AnimateIndex[ (int)NowIndex ]);

    Dino::Jump();
    //рисование
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        
        glVertexPointer(2, GL_FLOAT, 0, VertexArray);
        glTexCoordPointer(2, GL_FLOAT, 0, TextureUV);
        
        glDrawArrays(GL_QUADS, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    glBindTexture(GL_TEXTURE_2D, 0);
}


void Dino::Jump(){
    if(Joystick::isConnected(0))
        isJoystickConnect = 1;
    else
        isJoystickConnect = 0;

    if(isJump && CntJump > reCntJump - 1){
        for(int i = 0; i < arr_size; i++){
            VertexArray[i] += Vector2d(0, PowerJump * CntJump);
        }
        coord += Vector2d(0, PowerJump * CntJump);
        CntJump--;
    }
    else{
        isJump = 0;
        CntJump = -reCntJump;
    }

    bool isButtonPressedJoystick = Joystick::isButtonPressed(0, 0)||Joystick::isButtonPressed(0, 5)||Joystick::isButtonPressed(0, 4)||Joystick::getAxisPosition(0, sf::Joystick::Y) < -30;

    if( ( (isButtonPressedJoystick && isJoystickConnect) || Keyboard::isKeyPressed(Keyboard::Key::W)) && !isJump)
        isJump = 1;

}
