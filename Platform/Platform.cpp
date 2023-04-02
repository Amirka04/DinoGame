#include "Platform.hpp"

#include <stdio.h>
#include <GL/gl.h>

// т.к. кол-во текстур платформы будет пока что одна, инициализируем статическую id переменную
uint Platform::NowTexture = 0;
float Platform::SpeedPlatform = 0;
int Platform::cntPlatform = 0;

// Конструктор без параметров
Platform::Platform(){
    if(cntPlatform > 0)
        printf("Платформа без параметров создана!\n");
    cntPlatform++;
}

// Конструктор с параметрами ( название файла текстуры/путь к текстуре, размер, координаты, скорость)
Platform::Platform(const char* namefile, Vector2d coord, Vector2d size, float speed)
:size(size), coord(coord)
{
    cntPlatform++;
 
    SpeedPlatform = speed;

    // если инициализация уже была
    if(NowTexture == 0){
        NowTexture = TexturesInit(namefile);
        printf("Платформа инициализарована!\nid текстуры:%d\n", NowTexture);
    }

    // устанавливаем кооринаты отрисовки нашей платформы
    for(int i = 0; i < size_arr; i++){
        vertex[i] *= this->size;
        vertex[i] += this->coord;
    }
}

// рисование платформы
void Platform::draw(){
    Init();

    RunPlatform();

    // включим активную текстуру
    glBindTexture(GL_TEXTURE_2D, NowTexture);

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

// установка всех значений
void Platform::SetVolume(const char* namefile, Vector2d coord, Vector2d size, float speed){

    if(NowTexture == 0)
        NowTexture = TexturesInit(namefile);

    this->coord += coord;
    this->size += size;
    SpeedPlatform = speed;

    for(int i = 0; i < size_arr; i++){
        vertex[i] *= this->size;
        vertex[i] += this->coord;        
    }

}

//если нам не нужна текстура, то перегрузим функцию
void Platform::SetVolume(Vector2d coord, Vector2d size, float speed){
    
    this->coord += coord;
    this->size += size;
    SpeedPlatform = speed;

    for(int i = 0; i < size_arr; i++){
        vertex[i] *= this->size;
        vertex[i] += this->coord;        
    }
}

// Установка текстур, метод статический потому что тектуры мы можем загрузить пока что 1 раз
void Platform::setTexture(const char* namefile){
    if(NowTexture == 0){
        NowTexture = TexturesInit(namefile);
    }
    else{
        printf("Инициализация текстура уже была проведена!");
    }
}

// Установка координат
void Platform::SetCoordinate(Vector2d coord){
    this->coord+=coord;
}

// установка размера
void Platform::SetSize(Vector2d size){
    this->size = size;
}

// установка скорости
void Platform::SetSpeed(float speed){
    SpeedPlatform = speed;
}

// Заставим платформу двигаться и телепортироваться при выхода из границы
void Platform::RunPlatform(){
    for(int i = 0; i < size_arr; i++)
        vertex[i] -= Vector2d(SpeedPlatform, 0);    
    coord -= Vector2d(SpeedPlatform, 0);

    if(coord.x < -1.4){
        for(int i = 0; i < size_arr; i++)
            vertex[i] += Vector2d(2.8, 0);
        coord+=Vector2d(2.8, 0);
    }
}