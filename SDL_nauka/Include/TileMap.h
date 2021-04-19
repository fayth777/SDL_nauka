#pragma once
#include "graphics.h"
#include "Tile.h"

class TileMap
{
	
public:
	TileMap() {
		starting_tile = tiles_2darray[column_total_amount / 2][row_total_amount / 2];
	};
	void SetTileIndexAndPosition();
	void SetTileTexture();
	void RenderTiles();

	int Get_Colums_amount() { return column_total_amount; };
	int Get_Row_amount() { return row_total_amount; };

private:

	Tile starting_tile;

	 static const int column_total_amount = kScreen_width / kTile_size;
	 static const int row_total_amount = kScreen_height / kTile_size;
	 Tile tiles_2darray[column_total_amount][row_total_amount];
};

