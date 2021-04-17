#pragma once
#include "graphics.h"
#include "Game_main.h"

extern enum class TileType { TILETYPE_GRASS, TILETYPE_GROUND };


class Tile
{
	
public:
	Tile(TileType Tiletype, int posx, int posy) {
		position.xpos=posx;
		position.ypos = posy;
		tile_type = Tiletype;
		SetPosition(posx, posy);
		SetTexture(Tiletype);
	};
	void SetTexture(enum TileType tiletype);
	void SetPosition(int posx, int posy);
	inline void RenderTile() { tile_texture.Render(position.xpos, position.ypos); };


private:
	
	std::string GetTileTexturePath(enum class TileType tiletype);
	TileType tile_type;
	LTexture tile_texture;
	Position position;
};

