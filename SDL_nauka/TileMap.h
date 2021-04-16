#pragma once
#include "graphics.h"
#include "Tile.h"
class TileMap
{
	TileMap() {
		
	}
public:

private:
	static const int xsize = SCREEN_WIDTH / 32;
	static const int ysize = SCREEN_HEIGHT / 32;
	static Tile tilesarray[xsize][ysize];
};

