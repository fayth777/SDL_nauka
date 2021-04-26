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
	for (size_t gridx = 0; gridx < grids_vector_side_size; gridx++)
	{
		for (size_t gridy = 0; gridy < grids_vector_side_size; gridy++)
		{
			tiles_grids[gridx][gridy] = FillSingleGrid(gridx,gridy);
		}
	}
}

TileGrid TileMap::FillSingleGrid(int gridx, int gridy)
{
	TileGrid tiles_grid;
	
	for (size_t x = 0; x < grid_row_size; x++)
	{
		for (size_t y = 0; y < grid_column_size; y++)
		{
			tiles_grid.tiles_single_grid[x][y] = &tiles_all[x + grid_column_size * gridx][y + grid_row_size * gridy];
			
		}
	}
	return tiles_grid;
}



void TileMap::SetAllTileType()
{
	{
		for (size_t gridx = 0; gridx < grids_vector_side_size; gridx++)
		{
			for (size_t gridy = 0; gridy < grids_vector_side_size; gridy++)
			{
				SetGridType(tiles_grids[gridx][gridy], TileType::TILETYPE_GRASS);
			}
		}
	}
}

void TileMap::SetGridType(TileGrid& grid, enum class TileType type)
{

	for (size_t x = 0; x < grid_row_size; x++)
	{
		for (size_t y = 0; y < grid_column_size; y++)
		{

			grid.tiles_single_grid[x][y]->SetTileType(type);
		}
	}

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
