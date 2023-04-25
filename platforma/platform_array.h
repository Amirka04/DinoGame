#ifndef PLATFORM_ARRAY_H
#define PLATFORM_ARRAY_H

#include "../Textures/Textures.h"
#include "platforma.h"
#include "iostream"

class platform_array: protected Textures{
public:
    platform_array();
    platform_array(float speed, float a, float max_speed);
    ~platform_array();

    void AddPlatform(Vector2d, Vector2d);
    void AddTexture(const char*);

    void show();

    friend std::ostream &operator<<(std::ostream &out, platform_array plato);

protected:
    float MaxSpeed, A, Speed;

    int sizePl = 1;
    int sizeTex = 1;

    uint *TextureArr;
    platforma *PlatoArr;
};


std::ostream &operator<<(std::ostream &out, platform_array plato);



#endif
