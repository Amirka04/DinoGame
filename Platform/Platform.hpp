#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include "../Vectors/Vector2D.h"
#include "../Textures/Textures.h"


class Platform: protected Textures{
    public:
        Platform();
        Platform(const char*, Vector2d, Vector2d, float);

        void draw();

    protected:
        Vector2d coord;
        Vector2d size;
        Vector2d *vertex = new Vector2d[4]{ {1,1},{-1,1},{-1,-1},{1,-1} };

        static int NowTexture;
        static float SpeedPlatform;

        const int size_arr = 4;
};

#endif
