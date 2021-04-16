#pragma once
#include "graphics.h"

extern enum class TileType { TILETYPE_GRASS, TILETYPE_GROUND };


class Tile
{
	
public:
	Tile(TileType Tiletype, int posx, int posy) {
		TileType = Tiletype;
		xpos = posx;
		ypos = posy;
	};
	void set_texture(enum TileType tiletype);
	int xpos=0;
	int ypos=0;
	TileType TileType;
	LTexture TileTexture;


private:
	
	std::string TexturePath;
	std::string GetTileTexturePath(enum TileType tiletype);
};

