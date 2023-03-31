#include "Dino.h"
#include <SFML/Graphics.hpp>
#include <GL/gl.h>

#include <stdio.h>


Dino::Dino(){
    printf("Animate initializate!\n");
}

Dino::Dino(Animate AnimateDino, Vector2d coord, Vector2d size):Animate(AnimateDino){
    this->coord = coord;
    this->size = size;

    for(int i = 0; i < arr_size; i++){
        // устанавливаем размер
        VertexArray[i].x *= this->size.x;
        VertexArray[i].y *= this->size.y;
        // подвинем точку в нужное место
        VertexArray[i] += this->coord;
    }
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