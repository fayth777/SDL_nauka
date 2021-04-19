#pragma once
#include "graphics.h"
#include "Game_main.h"

enum class TileType { TILETYPE_NONE, TILETYPE_GRASS, TILETYPE_GROUND };


class Tile
{

public:

	Tile(TileType Tiletype=(TileType::TILETYPE_NONE), int posx = 0, int posy = 0) {
		screen_position.xpos=posx;
		screen_position.ypos = posy;
		tile_type = Tiletype;
		SetPosition(posx, posy);
	};
	void SetTexture();
	void SetPosition(int posx, int posy);
	void RenderTile() ;
	void SetIndex(int x, int y) 
	{	index_x = x; index_y = y;}

private:
	
	std::string GetTileTexturePath(enum class TileType tiletype);
	TileType tile_type;
	LTexture tile_texture;
	Position screen_position;
	int index_x;
	int index_y;
};

