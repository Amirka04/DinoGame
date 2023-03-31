#ifndef TEXTURES_H
#define TEXTURES_H

using uint = unsigned int;

class Textures{
    protected:
        uint textureID = 0;
        float *TextureUV = new float[8]{1,0, 0,0, 0,1, 1,1};

    public:
        Textures();
        Textures(const char*);

        void Init();
        uint TexturesInit(const char*);
};


#endif