#include "Dino.h"
#include <SFML/Graphics.hpp>
#include <GL/gl.h>

#include <stdio.h>


Dino::Dino(){
    printf("Динозавр инициализирован\n");
}


Dino::Dino(Animate AnimateDino, Vector2d coord, Vector2d size):Animate(AnimateDino){
    printf("Динозавр инициализирован\n");
    
    this->coord = coord;
    y0 = this->coord.y;

    this->size = size;

    for(int i = 0; i < arr_size; i++){
        // устанавливаем размер
        VertexArray[i] *= this->size;
        // подвинем точку в нужное место
        VertexArray[i] += this->coord;
    }
}

Dino::~Dino(){
    delete [] VertexArray;
}


void Dino::draw(){

    RunAnimation();
    glBindTexture(GL_TEXTURE_2D, AnimateIndex[ (int)NowIndex ]);

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
    if(Keyboard::isKeyPressed(Keyboard::Key::W) && !isJump)
        isJump = 1;

    if(isJump && CntJump != reCntJump){
        for(int i = 0; i < arr_size; i++)
            VertexArray[i] += Vector2d(0, PowerJump * CntJump);
        coord += Vector2d(0, PowerJump * CntJump);

        CntJump--;
    }
    else{
        isJump = 0;
        CntJump = -reCntJump;
    }


}