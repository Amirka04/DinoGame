#ifndef KAKTUS_H
#define KAKTUS_H

#include "GL/gl.h"
#include "../Textures/Textures.h"
#include "../Vectors/Vector2D.h"


class Kaktus{
public:
	Kaktus();
	Kaktus(Textures, Vector2d, Vector2d);


	void show();
protected:
	Vector2d Coordinate{0,0};
	Vector2d Size{0,0};

};



#endif
