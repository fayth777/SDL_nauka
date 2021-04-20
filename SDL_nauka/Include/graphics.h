#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "LTexture.h"

//The window we'll be rendering to
extern SDL_Window* gWindow;

//The window renderer
extern SDL_Renderer* gRenderer;

const int kScreen_width = 1920;
const int kScreen_height = 1200;
const int kTile_size = 32;



//Engine initialization function
bool Init(); 
	

	


