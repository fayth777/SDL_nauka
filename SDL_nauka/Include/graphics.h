#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

//The window we'll be rendering to
extern SDL_Window* gWindow;

//The window renderer
extern SDL_Renderer* gRenderer;

const int kScreenWidth = 1280;
const int kScreenHeight = 720;

class GraphicsProfiler {

public:
	void PrintFPS();

private:
	int fps = 0;
	int fpsTimer = 0;
	

};


	

	


