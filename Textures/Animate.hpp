#ifndef ANIMATE_H
#define ANIMATE_H

#include <string>

#include "Textures.h"

using string = std::string;


class Animate: protected Textures{
    public:
        Animate();
        Animate(char*, float);
        ~Animate();
        

        void RunAnimation();

    protected:
        float SpeedAnimate;
        float NowIndex = 0;

        int SizeTextureArray;
        uint *AnimateIndex;
        
};

#endif