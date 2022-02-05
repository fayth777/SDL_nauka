#pragma once
#include "SDL.h"



class Cursor
{
public:
    //The dimensions of the cursor
    static const int DOT_WIDTH = 20;
    static const int DOT_HEIGHT = 20;

    //Maximum axis velocity of the cursor
    static const int DOT_VEL = 10;

    //Initializes the variables
    Cursor();

    //Takes key presses and adjusts the dot's velocity
    void handleEvent(SDL_Event& event_handler);

    //Moves the dot
    void move();

    //Shows the dot on the screen
    void render();

private:
    //The X and Y offsets of the dot
    int mPosX, mPosY;

    //The velocity of the dot
    int mVelX, mVelY;
};

