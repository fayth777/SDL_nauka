#pragma once
#include "graphics.h"
#include "Tile.h"
class TileMap
{
	TileMap() {
		Tile starting_tile = tilesarray[xsize / 2][ysize / 2];
	}
public:
	int starting_tile =0;
private:
	static const int xsize = SCREEN_WIDTH / 32;
	static const int ysize = SCREEN_HEIGHT / 32;
	static Tile tilesarray[xsize][ysize];
};

