#include "Platform.hpp"

#include <stdio.h>
#include <GL/gl.h>

// т.к. кол-во текстур платформы будет пока что одна, инициализируем статическую id переменную
int Platform::NowTexture = 0;
float Platform::SpeedPlatform = 0;


// Конструктор без параметров
Platform::Platform(){
    printf("Platform initializated!\n");
}

// Конструктор с параметрами ( название файла текстуры/путь к текстуре, размер, координаты, скорость)
Platform::Platform(const char* namefile, Vector2d coord, Vector2d size, float speed)
:size(size), coord(coord)
{
    SpeedPlatform = speed;

    for(int i = 0; i < size_arr; i++){
        vertex[i] *= this->size;
        vertex[i] += this->coord;
    }
    // если инициализация уже была
    if(textureID <= 0){
        TexturesInit(namefile);
    }

    printf("Platform initializated!\nId Texture:%d\n", textureID);
}


// рисование платформы
void Platform::draw(){
//    Init();
    // включим активную текстуру
    glBindTexture(GL_TEXTURE_2D, textureID);

    // рисование
    glEnableClientState(GL_VERTEX_ARRAY);
    // текстура
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

        glVertexPointer(2, GL_FLOAT, 0, vertex);
        glTexCoordPointer(2, GL_FLOAT, 0, TextureUV);

        // Нарисуем квадрат
        glDrawArrays(GL_QUADS, 0, 4);

        // рисование
        glDisableClientState(GL_VERTEX_ARRAY);
    // текстура
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);


    // отключим текстуру
    glBindTexture(GL_TEXTURE_2D, 0);
}
