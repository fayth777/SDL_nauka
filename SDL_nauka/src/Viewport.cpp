#pragma once
#include "Viewport.h"
#include "TextureDatabase.h"

Viewport::Viewport()
{
    //Initialize the offsets
    mPosX = 0;
    mPosY = 0;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;

    ViewportRectangle = { 0, 0, kScreenWidth, kScreenHeight };
}

void Viewport::handleEvent(SDL_Event& EventHandler)
{
    //If a key was pressed
    if (EventHandler.type == SDL_KEYDOWN && EventHandler.key.repeat == 0)
    {
        //Adjust the velocity
        switch (EventHandler.key.keysym.sym)
        {
        case SDLK_UP: mVelY -= CameraVelocity; break;
        case SDLK_DOWN: mVelY += CameraVelocity; break;
        case SDLK_LEFT: mVelX -= CameraVelocity; break;
        case SDLK_RIGHT: mVelX += CameraVelocity; break;
        }
    }
        //If a key was released
    else if (EventHandler.type == SDL_KEYUP && EventHandler.key.repeat == 0)
    {
        //Adjust the velocity
        switch (EventHandler.key.keysym.sym)
        {
        case SDLK_UP: mVelY += CameraVelocity; break;
        case SDLK_DOWN: mVelY -= CameraVelocity; break;
        case SDLK_LEFT: mVelX += CameraVelocity; break;
        case SDLK_RIGHT: mVelX -= CameraVelocity; break;
        }
    }
}

void Viewport::move()
{
    {
        //Move the dot left or right
        mPosX += mVelX;

        //If the dot went too far to the left or right
        if ((mPosX < 0) || (mPosX  > kScreenWidth))
        {
            //Move back
            mPosX -= mVelX;
        }
        //Move the dot up or down
        mPosY += mVelY;

        //If the dot went too far up or down
        if ((mPosY < 0) || (mPosY  > kScreenHeight))
        {
            //Move back
            mPosY -= mVelY;
        }
    }
}

