#pragma once
#include "graphics.h"
#include "Tile.h"

class TileMap
{
	
public:
	TileMap();
	void SetTileIndexAndPosition();
	void SetAllTileType();
	void SetTileTexture();
	void RenderTiles();

	inline int Get_Colums_amount() { return column_total_amount; };
	inline int Get_Row_amount() { return row_total_amount; };

private:

	Tile starting_tile;
	static const int column_total_amount = kScreen_width / kTile_size;
	static const int row_total_amount = kScreen_height / kTile_size;
	Tile tiles_2darray[column_total_amount][row_total_amount];
};

