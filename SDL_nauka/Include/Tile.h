#pragma once
#include "graphics.h"
#include "Game_main.h"
#include "LTexture.h"

enum class TileType { TILETYPE_NONE, TILETYPE_GRASS, TILETYPE_GROUND, TILETYPE_FOREST };
extern LTexture T_empty_tile;


class Tile
{

public:

	Tile();
	void SetPosition(int posx, int posy);
	void RenderTile() ;
	inline void SetIndex(int x, int y) {index_x = x; index_y = y;}
	inline void SetTileType(enum class TileType type) {tile_type = type;};
	void GetTileTexture();


private:
	
	TileType tile_type;
	LTexture* tile_texture = NULL;
	Position screen_position;
	int index_x;
	int index_y;
	
};

