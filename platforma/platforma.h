#ifndef PLATFORMA_H
#define PLATFORMA_H

#include "../Vectors/Vector2D.h"
#include "../Textures/Textures.h"

class platforma: protected Textures{
public:
    platforma();
    platforma(Vector2d, Vector2d, uint);
    platforma(platforma&);
    ~platforma();

    platforma &operator=(platforma &);


    void SetInfo(Vector2d, Vector2d, uint);
    void draw();
protected:
    uint ID_Texture;

    Vector2d coordinate;

    const int Size = 4;
    Vector2d *vec = new Vector2d[Size]{{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};

};



#endif
