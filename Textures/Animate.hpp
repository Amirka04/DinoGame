#ifndef ANIMATE_H
#define ANIMATE_H

#include "string"

#include "Textures.h"


using string = std::string;


class Animate: protected Textures{
    public:
        Animate();
        Animate(const char*, float);
        
        void LocalInit(float, float);
        static void SetGlobalInit(float, float);

        void RunAnimation();

    protected:
        float SpeedAnimate;
        float NowIndex = 0;

        int SizeTextureArray;
        uint *AnimateIndex;

    private:
        int isLocallInit = 0;

        float LocalMaxSpeedAnimate;
        float LocalA;

        static float MaxSpeedAnimate;
        static float A;
};

#endif
