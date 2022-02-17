#pragma once
#include "Viewport.h"
#include "TextureDatabase.h"
#include "TileMap.h"


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
        //Move the Viewport left or right
        mPosX += mVelX;

        //If the Viewport went too far to the left or right
        if ((mPosX < 0) || (mPosX  > TileMap::GetTileMap().GetLevelSideSize() - kScreenWidth))
        {
            //Move back
            mPosX -= mVelX;
        }
        //Move the Viewport up or down*/
        mPosY += mVelY;

        //If the Viewport went too far up or down
        if ((mPosY < 0) || (mPosY  > TileMap::GetTileMap().GetLevelSideSize() - kScreenHeight))
        {
            //Move back
            mPosY -= mVelY;
        }
    }
}

void Viewport::SetViewportValues()
{
    ViewportRectangle.x = mPosX;
    ViewportRectangle.y = mPosY;
    ViewportRectangle.w = kScreenWidth;
    ViewportRectangle.h = kScreenHeight;
}

