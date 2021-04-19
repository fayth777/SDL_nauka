#include "TileMap.h"

Tile tiles_2darray;

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

			tiles_2darray[x][y].SetTexture();
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
