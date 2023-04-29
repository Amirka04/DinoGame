#ifndef DINO_H
#define DINO_H

#include "../Textures/Animate.hpp"
#include "../Vectors/Vector2D.h"

class Dino : public Animate
{
private:
    int arr_size = 4;
    Vector2d *VertexArray = new Vector2d[arr_size]{{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
    int isJump = 0;
    int CntJump = 20, reCntJump = -CntJump;
    float PowerJump = 0.003;

    int isJoystickConnect = 0;

protected:
    Vector2d coord;
    Vector2d size;

    Vector2d Coord_Reset;
    Vector2d size_Reset;


public:
    Dino();
    Dino(Animate, Vector2d, Vector2d);
    Dino(Animate, Vector2d, Vector2d, float);
    ~Dino();

    void add_Texture();
    void Jump();
    void draw();
};

#endif
