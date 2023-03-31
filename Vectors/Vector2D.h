#ifndef VECTOR2D_H
#define VECTOR2D_H

struct Vector2d{
    Vector2d();
    Vector2d(float, float);

    Vector2d operator+(Vector2d);
    Vector2d operator-(Vector2d);
    void operator*(float);
    void operator+=(Vector2d);
    void operator-=(Vector2d);
    
    float x, y;
};





/*
    Прототип ф-ции для работы с векторами
*/

// вывод
void PrintVector(Vector2d);



#endif