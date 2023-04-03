#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include "../Vectors/Vector2D.h"
#include "../Textures/Textures.h"


class Platform: protected Textures{
    public:
        static int cntPlatform;

        Platform();
        Platform(const char*, Vector2d, Vector2d, float);
        
        void draw();
        void RunPlatform();

        void SetVolume(const char*, Vector2d, Vector2d, float);
        void SetVolume(Vector2d, Vector2d, float);
        
        void setTexture(const char*);
        void SetCoordinate(Vector2d);
        void SetSize(Vector2d);
        void SetSpeed(float);
        void SetMaxSpeed(float);

    protected:
        float a = 0.000001;
        float MaxSpeed;


        Vector2d coord = {0,0};
        Vector2d size = {0,0};

        const int size_arr = 4;
        Vector2d *vertex = new Vector2d[size_arr]{ {1,1},{-1,1},{-1,-1},{1,-1} };
        
        static uint NowTexture;
        static float SpeedPlatform;
};

#endif
