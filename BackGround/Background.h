#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "../Textures/Textures.h"
#include "../Vectors/Vector2D.h"
#include "GL/gl.h"


// BackObject - описывает объекты фона
class BackObject: public Textures{
public:
    BackObject();
    BackObject(Vector2d, Vector2d);
    BackObject(const char*, Vector2d, Vector2d);
    BackObject(Textures, Vector2d, Vector2d);
    ~BackObject();

    void BackObjectInit(Vector2d, Vector2d);

    // ф-я рисования фонового объекта
    void show();

    // эффект параллакса
    void SetGlobalParallax(float, float, float, Vector2d);


protected:
    Vector2d coordinate = {0,0};
    Vector2d size = {0,0};

private:
    const int size_vec = 4;
    Vector2d* vec = new Vector2d[size_vec]{ {1, 1}, {-1, 1}, {-1, -1}, {1, -1} };

    static float GlobalMaxH;
    static float GlobalMinH;
    static float GlobalMaxSpeed;
    static Vector2d MaxSpeed;

    float H;



};


#endif
