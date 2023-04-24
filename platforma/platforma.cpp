#include "platforma.h"
#include "stdio.h"
#include "GL/gl.h"

platforma::platforma(){
    printf("Инициализация платформы");
}

platforma::platforma(Vector2d coordinate, Vector2d size, int ID_Texture){
    SetInfo(coordinate, size, ID_Texture);
}

void platforma::SetInfo(Vector2d coordinate, Vector2d size, int ID_Texture)
{
    this->coordinate = coordinate;
    this->ID_Texture = ID_Texture;
    for(int i = 0; i < Size; i++)
        vec[i] *= size + coordinate;
}


void platforma::draw(){
    Init(ID_Texture);

//     рисование квадрата
    glEnableClientState(GL_VERTEX_ARRAY);
//     рисование текстуры
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//          Передам массив вершин для рисования как квадрата так и текстуры
            glVertexPointer(2, GL_FLOAT, 0, vec);
            glTexCoordPointer(2, GL_FLOAT, 0, TextureUV);
            glColor3f(0.3, 1, 0.3);
            // Нарисую
            glDrawArrays(GL_QUADS, 0, Size);

//     рисование квадрата
    glDisableClientState(GL_VERTEX_ARRAY);
//     рисование текстуры
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

}

// высвободим память если мы решим больше не использовать платформу
platforma::~platforma(){
    delete vec;
}

