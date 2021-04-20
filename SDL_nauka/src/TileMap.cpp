#include "TileMap.h"

Tile tiles_2darray;

TileMap::TileMap()
{
		starting_tile = tiles_2darray[column_total_amount / 2][row_total_amount / 2];
}

void TileMap::SetTileIndexAndPosition()
{
	for (size_t y = 0; y < row_total_amount; y++)
	{
		for (size_t x = 0; x < column_total_amount; x++)
		{
			tiles_2darray[x][y].SetIndex(x, y);
			tiles_2darray[x][y].SetPosition(x*kTile_size, y*kTile_size);

		}
	}
}

void TileMap::SetAllTileType()
{

}

void TileMap::SetTileTexture()
{
	for (size_t y = 0; y < row_total_amount; y++)
	{
		for (size_t x = 0; x < column_total_amount; x++)
		{

			tiles_2darray[x][y].GetTileTexture();
		}
	}
}

//Fill screen with tiles
void TileMap::RenderTiles()
{
	for (size_t y = 0; y < row_total_amount; y++)
	{
		for (size_t x = 0; x < column_total_amount; x++)
		{

			tiles_2darray[x][y].RenderTile();
		}
	}

}
