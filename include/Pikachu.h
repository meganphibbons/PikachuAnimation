#ifndef PIKACHU_H
#define PIKACHU_H
#include <allegro.h>

struct pokemon
{
       int x;
       int y;
       bool left;
       bool jump;
       bool duck;
       BITMAP *imgRight[5];
       BITMAP *img;
       int currFrame;
       int maxFrame;
       int frameDelay;
       int frameCount;
       BITMAP *explosion[9];
       int currExplosionFrame;
       bool called;
};

class Pikachu
{
    public:
         Pikachu(int myX, int myY);
         void runRight(BITMAP *bmp);
         void runLeft(BITMAP *bmp);
         void stand(BITMAP *bmp);
         void explosion(BITMAP *bmp, bool c);
         BITMAP *grabframe(BITMAP *source, int width, int height, int startx, int starty, int columns, int frame);

    private:
        pokemon myPikachu;
};

#endif
