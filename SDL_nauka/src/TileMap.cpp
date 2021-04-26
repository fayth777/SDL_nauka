#include "TileMap.h"




void TileMap::SetTileIndexAndPosition()
{
	for (size_t y = 0; y < row_total_amount; y++)
	{
		for (size_t x = 0; x < column_total_amount; x++)
		{
			tiles_all[x][y].SetIndex(x, y);
			tiles_all[x][y].SetPosition(x*kTile_size, y*kTile_size);

		}
	}
}

void TileMap::FillAllTilesGrids()
{
	for (size_t gridx = 0; gridx < tile_single_grid_row_size; gridx++)
	{
		for (size_t gridy = 0; gridy < tile_single_grid_column_size; gridy++)
		{
			tiles_grids[gridx][gridy] = FillSingleGrid(gridx,gridy);
		}
	}
}

TilesGrid TileMap::FillSingleGrid(int gridx, int gridy)
{
	TilesGrid tiles_grid;
	
	for (size_t x = 0; x < tile_single_grid_row_size; x++)
	{
		for (size_t y = 0; y < tile_single_grid_column_size; y++)
		{
			tiles_grid.tiles_single_grid[x][y] = &tiles_all[0 + tile_single_grid_column_size * gridx][0 + tile_single_grid_row_size * gridy];
			
		}
	}
	return TilesGrid();
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

			tiles_all[x][y].GetTileTexture();
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

			tiles_all[x][y].RenderTile();
		}
	}

}

Tile TileMap::GetStartingTile()
{
		return tiles_all[row_total_amount / 2][column_total_amount / 2];
}
