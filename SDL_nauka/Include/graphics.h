#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "TileMap.h"
#include "Tile.h"
#include <stdio.h>

//The window we'll be rendering to
extern SDL_Window* gWindow;

//The window renderer
extern SDL_Renderer* gRenderer;

const int kScreenWidth = 1920;
const int kScreenHeight = 1080;

const int kLevelSideSize = TileMap::GetTileMap().GetTileSize() * TileMap::GetTileMap().GetGridsVectorSideSize() * TileMap::GetTileMap().GetGridRowSize();

class GraphicsProfiler {

public:
	void PrintFPS();

private:
	int fps = 0;
	int fpsTimer = 0;
	

};


	

	


