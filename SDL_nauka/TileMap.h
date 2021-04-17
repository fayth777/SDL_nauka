#pragma once
#include "graphics.h"
#include "Tile.h"
class TileMap
{
	TileMap() {
		Tile starting_tile = tilesarray[xsize / 2][ysize / 2];
	}
public:
	void SetStartingTile();
private:
	int starting_tile = 0;

	static const int xsize = kSCREEN_WIDTH / 32;
	static const int ysize = kSCREEN_HEIGHT / 32;
	static Tile tilesarray[xsize][ysize];
};

