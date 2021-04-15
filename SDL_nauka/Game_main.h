#pragma once
#include "SDL.h"
#include "graphics.h"

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

SDL_Rect gSpriteClips[4];
LTexture TileTexture;