#include "Pikachu.h"

#include <cstdlib>
#include <iostream>

 Pikachu::Pikachu(int myX, int myY)
 {
    myPikachu.duck = false;
    myPikachu.currFrame = 0;
    myPikachu.frameCount = 0;
    myPikachu.frameDelay = 10;
    myPikachu.maxFrame = 3;
    myPikachu.jump = false;
    myPikachu.left = true;
    myPikachu.x = myX;
    myPikachu.y = myY;
    myPikachu.currExplosionFrame = 0;
    myPikachu.imgRight[0] = load_bitmap("standingPikachu.bmp", NULL);
    myPikachu.called = false;
    BITMAP *temp = load_bitmap("pikachuRunning.bmp", NULL);
    for (int i = 1; i < 4; i++)
    {
        myPikachu.imgRight[i] = grabframe(temp, 40, 35, 0, 0, 5, i);
    }
    destroy_bitmap(temp);
    temp = load_bitmap("explosion.bmp", NULL);
    for (int i = 0; i < 9; i++)
    {
        myPikachu.explosion[i] = grabframe(temp, 110, 130, 0, 0, 9, i);
    }
    destroy_bitmap(temp);
 }

 void Pikachu::runRight(BITMAP *bmp)
 {
      myPikachu.left = false;
      myPikachu.x += 2;
      if (++myPikachu.frameCount > myPikachu.frameDelay)
      {
         myPikachu.frameCount=0;
         if (++myPikachu.currFrame > myPikachu.maxFrame)
         myPikachu.currFrame=1;
      }
      draw_sprite(bmp, myPikachu.imgRight[myPikachu.currFrame], (myPikachu.x), (myPikachu.y));

 }

 void Pikachu::runLeft(BITMAP *bmp)
 {
      myPikachu.left = true;
      myPikachu.x-= 2;
      if (++myPikachu.frameCount > myPikachu.frameDelay)
      {
         myPikachu.frameCount=0;
         if (++myPikachu.currFrame > myPikachu.maxFrame)
         myPikachu.currFrame=1;
      }
      draw_sprite_h_flip(bmp, myPikachu.imgRight[myPikachu.currFrame],
    (myPikachu.x), (myPikachu.y));

 }

 void Pikachu::stand(BITMAP *bmp)
 {
      myPikachu.currFrame = 0;
      if (!myPikachu.left)
        draw_sprite(bmp, myPikachu.imgRight[myPikachu.currFrame], (myPikachu.x), (myPikachu.y));

      else
        draw_sprite_h_flip(bmp, myPikachu.imgRight[myPikachu.currFrame], (myPikachu.x), (myPikachu.y));
 }

 void Pikachu::explosion(BITMAP *bmp, bool c)
 {
     if(c)
        myPikachu.called = true;
     if(myPikachu.called)
    {
        draw_sprite(bmp, myPikachu.explosion[myPikachu.currExplosionFrame % 9], 0, 0);
        myPikachu.currExplosionFrame++;
    }
    rest(50);
 }

 BITMAP *Pikachu::grabframe(BITMAP *source, int width, int height, int startx, int starty, int columns, int frame)
    {
        BITMAP *temp = create_bitmap(width,height);
        int x = startx + (frame % columns) * width;
        int y = starty + (frame / columns) * height;
        blit(source,temp,x,y,0,0,width,height);
        return temp;
    }
