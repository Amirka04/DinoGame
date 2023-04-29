#include "platforma.h"
#include "GL/gl.h"
#include "cmath"

// текстура будет на всех одна!
uint Platforma::TextureID = 0;


Platforma::Platforma(){}

Platforma::Platforma(float Speed, float A, float Max):A(A), Speed(Speed), MaxSpeed(Max){}

void Platforma::SetSpeed(float Speed, float A, float Max){
	this->Speed = Speed;
	this->MaxSpeed = Max;
	this->A = A;
}

void Platforma::SetBorder(float Border){
	this->Border = Border;
}

void Platforma::SetObject(Vector2d coordinate, Vector2d size){
	Coordinate = coordinate;
	Size = size;
	for(int i = 0; i < 4; i++){
		vec[i] *= Size;
		vec[i] += Coordinate;
	}
}

void Platforma::Move(){
	Coordinate += Vector2d(Speed, 0);

	if( fabs(Speed) < fabs(MaxSpeed)){
		Speed += A;
	}

	if( Coordinate.x < -Border ){
		Coordinate += Vector2d(Border * 2, 0);

		for(int i = 0; i < 4; i++)
			vec[i] += Vector2d(Border * 2, 0);
	}

	for(int i = 0; i < 4; i++)
		vec[i] += Vector2d(Speed, 0);
}

void Platforma::SetTexture(const char* namefile){
	TextureID = TexturesInit(namefile);
}

void Platforma::Show(){

	Init(TextureID);

	Move();

	glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

			glVertexPointer(2, GL_FLOAT, 0, vec);
			glTexCoordPointer(2, GL_FLOAT, 0, TextureUV);

			glDrawArrays(GL_QUADS, 0, 4);

	glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}
