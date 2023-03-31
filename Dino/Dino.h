#ifndef DINO_H
#define DINO_H

#include "../Textures/Animate.hpp"
#include "../Vectors/Vector2D.h"


class Dino: protected Animate{
        protected:
            Vector2d coord;
            Vector2d size;

            int arr_size = 4;
            Vector2d *VertexArray = new Vector2d[arr_size]{ {1,1}, {-1,1}, {-1,-1}, {1,-1}};

        public:
            Dino();
            Dino(Animate, Vector2d, Vector2d);
            
            void draw();
};



#endif