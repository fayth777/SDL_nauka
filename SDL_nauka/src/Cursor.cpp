#pragma once
#include "Cursor.h"
#include "TextureDatabase.h"

Cursor::Cursor()
{
    //Initialize the offsets
    mPosX = 0;
    mPosY = 0;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
}

void Cursor::handleEvent(SDL_Event& EventHandler)
{
    //If a key was pressed
    if (EventHandler.type == SDL_KEYDOWN && EventHandler.key.repeat == 0)
    {
        //Adjust the velocity
        switch (EventHandler.key.keysym.sym)
        {
        case SDLK_UP: mVelY -= DOT_VEL; break;
        case SDLK_DOWN: mVelY += DOT_VEL; break;
        case SDLK_LEFT: mVelX -= DOT_VEL; break;
        case SDLK_RIGHT: mVelX += DOT_VEL; break;
        }
    }
        //If a key was released
    else if (EventHandler.type == SDL_KEYUP && EventHandler.key.repeat == 0)
    {
        //Adjust the velocity
        switch (EventHandler.key.keysym.sym)
        {
        case SDLK_UP: mVelY += DOT_VEL; break;
        case SDLK_DOWN: mVelY -= DOT_VEL; break;
        case SDLK_LEFT: mVelX += DOT_VEL; break;
        case SDLK_RIGHT: mVelX -= DOT_VEL; break;
        }
    }
}

void Cursor::move()
{
    {
        //Move the dot left or right
        mPosX += mVelX;

        //If the dot went too far to the left or right
        if ((mPosX < 0) || (mPosX + DOT_WIDTH > kScreenWidth))
        {
            //Move back
            mPosX -= mVelX;
        }
        //Move the dot up or down
        mPosY += mVelY;

        //If the dot went too far up or down
        if ((mPosY < 0) || (mPosY + DOT_HEIGHT > kScreenHeight))
        {
            //Move back
            mPosY -= mVelY;
        }
    }
}

void Cursor::render()
{
    {
        //Show the cursor
        TextureDatabase::GetCursorTexture()->Render(mPosX, mPosY);
    }
}
