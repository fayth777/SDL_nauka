#pragma once
#include "graphics.h"
#include "Game_main.h"

enum class TileType { TILETYPE_NONE, TILETYPE_GRASS, TILETYPE_GROUND };
extern LTexture test;


class Tile
{

public:

	Tile();
	void SetTexture();
	void SetTextures();
	void SetPosition(int posx, int posy);
	void RenderTile() ;
	inline void SetIndex(int x, int y) {index_x = x; index_y = y;}
	

private:
	
	std::string GetTileTexturePath(enum class TileType tiletype);
	TileType tile_type;
	LTexture* tile_texture = &test;
	Position screen_position;
	int index_x;
	int index_y;
	
};

