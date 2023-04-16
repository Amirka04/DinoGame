#include "Background.h"
#include <stdio.h>


BackObject::BackObject(){
    printf("\n\033[93mФон инициализирован, но без изображения\033[0m");
}

BackObject::BackObject(const char* namefile, Vector2d coordinate, Vector2d size){
    TexturesInit(namefile);
    BackObjectInit(coordinate, size);
    printf("\n\033[92mФон инициализирован, id изображения:%d \033[0m", textureID);
}

BackObject::BackObject(Textures FonObjectTexture, Vector2d coordinate, Vector2d size): Textures(FonObjectTexture){
    printf("\n\033[92mФон инициализирован, id изображения:%d \033[0m", textureID);
    BackObjectInit(coordinate, size);

}

BackObject::BackObject(Vector2d coordinate, Vector2d size){
    printf("\n\033[93mФон инициализирован без изображения :( \033[0m");
    BackObjectInit(coordinate, size);
}

void BackObject::BackObjectInit(Vector2d coordinate, Vector2d size){
    this->coordinate += coordinate;
    this->size += size;

    for(int i = 0; i < size_vec; i++){
        vec[i] *= this->size;
    }



}

BackObject::~BackObject(){
    delete [] TextureUV;
    delete [] vec;
}

void BackObject::show(){
    Init();

    glBindTexture(GL_TEXTURE_2D, textureID);

    // рисование фигуры
    glEnableClientState(GL_VERTEX_ARRAY);
    // рисование текстуры
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glVertexPointer(2, GL_FLOAT, 0, vec);
    glTexCoordPointer(2, GL_FLOAT, 0, TextureUV);

    glDrawArrays(GL_QUADS, 0, 4);

    // рисование фигуры
    glDisableClientState(GL_VERTEX_ARRAY);
    // рисование текстуры
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}


// Инициализируем
void BackObject::SetGlobalParallax(float maxH, float minH, float h, Vector2d MaxSpeed){

}
