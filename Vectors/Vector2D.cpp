#include "Vector2D.h"

#include <cmath>

#include <stdio.h>


Vector2d::Vector2d(){}

Vector2d::Vector2d(float uX, float uY){
    x = uX;
    y = uY;
}

Vector2d Vector2d::operator+(Vector2d vec2){
    return Vector2d(this->x + vec2.x, this->y + vec2.y);
}

void Vector2d::operator*(float kf){
    this->x *= kf;
    this->y *= kf;
}

Vector2d Vector2d::operator-(Vector2d vec2){
   return Vector2d(this->x - vec2.x, this->y - vec2.y);
}

void Vector2d::operator+=(Vector2d vec2){
    this->x += vec2.x;
    this->y += vec2.y;
}

void Vector2d::operator-=(Vector2d vec2){
    this->x -= vec2.x;
    this->y -= vec2.y;
}

void Vector2d::operator*=(Vector2d vec2){
    this->x *= vec2.x;
    this->y *= vec2.y;
}




void PrintVector(Vector2d vec2){
    printf("vector x: %f\nvector y: %f\n", vec2.x, vec2.y);
}
