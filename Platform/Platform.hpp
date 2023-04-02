#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include "../Vectors/Vector2D.h"
#include "../Textures/Textures.h"


struct platformInfo{
  platformInfo();
  platformInfo(const char*, Vector2d, Vector2d, float);

  const char* name;
  float speed;
  Vector2d coord;
  Vector2d size;

};

class Platform: protected Textures{
    public:
        Platform();
        Platform(const char*, Vector2d, Vector2d, float);
        Platform(platformInfo);


        void draw();

    protected:
        Vector2d coord;
        Vector2d size;

        const int size_arr = 4;
        Vector2d *vertex = new Vector2d[size_arr]{ {1,1},{-1,1},{-1,-1},{1,-1} };

        static int NowTexture;
        static float SpeedPlatform;

};

#endif
