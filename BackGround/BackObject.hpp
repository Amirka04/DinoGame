#ifndef BACKOBJECT_HPP
#define BACKOBJECT_HPP

#include "../Vectors/Vector2D.h"
#include "../Textures/Textures.h"
#include "GL/gl.h"


class BackObject: public Textures{
public:
    BackObject();
    BackObject(Vector2d, Vector2d);
    BackObject(Textures,Vector2d,Vector2d);

    void BGInit(Vector2d, Vector2d);

    void show();

protected:
    Vector2d coordinate = {0,0};
    Vector2d size = {0,0};

    const int size_arr = 4;
    Vector2d *vec = new Vector2d[]{ {1,1}, {-1,1}, {-1,-1}, {1,-1} };

};

#endif
