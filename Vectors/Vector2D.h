#ifndef VECTOR2D_H
#define VECTOR2D_H

struct Vector2d{
    Vector2d();
    Vector2d(float, float);
    // сложение
    Vector2d operator+(Vector2d);
    // вычитание
    Vector2d operator-(Vector2d);
    // умножение вектора на число
    void operator*(float);
    // сложение 2
    void operator+=(Vector2d);
    // вычитание 2
    void operator-=(Vector2d);
    // умножение вектора на вектор ( это действие вводиться для удобства умножения и уменьшения строчек кода в других файлах )
    void operator*=(Vector2d);


    float x, y;
};



#endif
