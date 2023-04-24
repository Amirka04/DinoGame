#include "BackObject.hpp"


BackObject::BackObject(){}


BackObject::BackObject(Vector2d coordinate, Vector2d size){
    BGInit(coordinate, size);
}

BackObject::BackObject(Textures GTexture, Vector2d coordinate, Vector2d size):Textures(GTexture){
    BGInit(coordinate, size);
}


// что бы много раз не писать один и тот же код инициализации, создам для этого отдельный метод
void BackObject::BGInit(Vector2d coordinate, Vector2d size){
    this->coordinate = coordinate;
    this->size = size;
    for(int i = 0; i < size_arr; i++){
        vec[i] *= size;
        vec[i] += coordinate;
    }
}


void BackObject::show(){

    Init(textureID);

    glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);

        glVertexPointer(2, GL_FLOAT, 0, vec);
        glTexCoordPointer(2, GL_FLOAT, 0, TextureUV);

        glDrawArrays(GL_QUADS, 0, size_arr);

        glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

}

