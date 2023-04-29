#ifndef PLATFORM_ARRAY_H
#define PLATFORM_ARRAY_H

#include "../Textures/Textures.h"
#include "../Vectors/Vector2D.h"

class Platforma : public Textures{
public:
    Platforma();
    Platforma(float, float, float);

    void SetSpeed(float, float, float);
    void SetObject(Vector2d, Vector2d);
    void SetTexture(const char*);
    void SetBorder(float);

    void Move();
    void Show();

protected:
    float A, Speed, MaxSpeed;
    Vector2d Coordinate, Size;

    static uint TextureID;

    float Border = 0;

    Vector2d *vec = new Vector2d[]{ {1,1}, {-1,1}, {-1,-1}, {1,-1} };
};



#endif
