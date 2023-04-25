#include "platform_array.h"
#include "random"


platform_array::platform_array(){}

// инициализируем наши массивы данных
platform_array::platform_array(float speed, float a, float max_speed): MaxSpeed(max_speed), A(a), Speed(speed)
{
    PlatoArr = new platforma[sizePl];
    TextureArr = new uint[sizeTex]{0};
}

// Добавление платформ с рандомной текстурой из массива текстур, само собой добавлю условие на добавление
void platform_array::AddPlatform(Vector2d coordinate, Vector2d size){
    platforma *tmp = new platforma[sizePl];
    platforma added{coordinate, size, TextureArr[ 1 + (rand() % (sizeTex - 1)) ]};

    for(int i = 0; i < sizePl; i++)
        tmp[i] = PlatoArr[i];

    delete [] PlatoArr;
    PlatoArr = new platforma[sizePl + 1];

    for(int i = 0; i < sizePl; i++)
        PlatoArr[i] = tmp[i];
    delete [] tmp;

    PlatoArr[sizePl] = added;
    sizePl++;
}

// Добавление текстур в массив с индексами
void platform_array::AddTexture(const char* namefile){
    uint *tmp = new uint[sizeTex];

    for(int i = 0; i < sizeTex; i++)
        tmp[i] = TextureArr[i];
    delete [] TextureArr;
    TextureArr = new uint[sizeTex + 1];

    for(int i = 0; i < sizeTex; i++)
        TextureArr[i] = tmp[i];

    TextureArr[sizeTex] = TexturesInit(namefile);
    sizeTex++;

    delete [] tmp;
}

// покажем всё что мы "накопили" в массивах
void platform_array::show(){
    for(int i = 1; i < sizePl; i++)
        PlatoArr[i].draw();
}

// При удалении буду очищать всё что содержиться в массивах
platform_array::~platform_array(){
        delete [] PlatoArr;
        delete [] TextureArr;

}



// вывод информации о массиве из платформ
std::ostream &operator<<(std::ostream &out, platform_array plato){
    printf("Output info platform_array:");

    for(int i = 1; i < plato.sizeTex; i++)
        out << "\n\tId Texture in array:" << plato.TextureArr[i];
    printf("\n\tsize array platform: %d", plato.sizePl - 1);

    return out;
}






