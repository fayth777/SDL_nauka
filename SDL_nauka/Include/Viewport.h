#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "graphics.h"





class Viewport
{
public:

    //Maximum axis velocity of the Camera
    static const int CameraVelocity = 5;

    //Initializes the variables
    Viewport();

    static Viewport& GetViewport() {
        static Viewport Viewport;
        return Viewport;
    };
    //Takes key presses and adjusts the Viewport's velocity
    void handleEvent(SDL_Event& event_handler);

    //Moves the Viewport
    void move();

    SDL_Rect ViewportRectangle;

    void SetViewportValues();
    //The X and Y offsets of the Viewport
    int mPosX, mPosY;

    //The velocity of the Viewport
    int mVelX, mVelY;
private:
   

};

