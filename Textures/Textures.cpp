#include "Textures.h"
#include <GL/gl.h>

#define STB_IMAGE_IMPLEMENTATION
#include "../stb_image.h"

#include <stdio.h>

Textures::Textures(){}

Textures::Textures(const char* image){
    Textures::TexturesInit(image);
    printf("Texture Initializate\n   texture name:%s\n   texture id:%d", image, textureID);
}

uint Textures::TexturesInit(const char* image){
    int width, height, cnt;

    unsigned char *data = stbi_load(image, &width, &height, &cnt, 0);

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

    glBindTexture(GL_TEXTURE_2D, 0);

    stbi_image_free(data);

    return textureID;
}

void Textures::Init(){
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.99);
}
