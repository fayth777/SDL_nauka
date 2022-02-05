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
	TileGrid tiles_grid(TileMap::GetTileMap().grid_row_size, TileMap::GetTileMap().grid_column_size);
	
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
				if (gridx < 2)
				{
					SetGridType(tiles_grids[gridx][gridy],67, TileType::TILETYPE_GRASS, TileType::TILETYPE_GROUND);
				}
				if (gridx == 2 )
				{
					SetGridType(tiles_grids[gridx][gridy],78, TileType::TILETYPE_GROUND, TileType::TILETYPE_FOREST);
				}
				if (gridx > 2 )
				{
					SetGridType(tiles_grids[gridx][gridy],35, TileType::TILETYPE_FOREST, TileType::TILETYPE_GROUND);
				}
			}
		}
	}
}

void TileMap::SetGridType(TileGrid& grid, int density, enum class TileType type1, enum class TileType type2)
{
	int type1_tile_amount = floor(grid.tiles_amount * (density / 100.0));
	int type2_tile_amount = floor(grid.tiles_amount - type1_tile_amount);
	int x = 0; // current position; x
	int y = 0; // current position; y
	int d = 0; // current direction; 0=RIGHT, 1=DOWN, 2=LEFT, 3=UP
	int c = 0; // counter
	int s = 1; // chain size

	// starting point
	x = ((int)floor(grids_vector_side_size / 2.0-1));
	y = ((int)floor(grids_vector_side_size / 2.0-1));

	for (int k = 1; k <= (grids_vector_side_size)-1; k++)
	{
		for (int j = 0; j <= (k < (grids_vector_side_size-1 ) ? 2 : 3); j++)
		{
			for (int i = 0; i < s; i++)
			{
				if (type1_tile_amount>0)
				{
					grid.tiles_single_grid[x][y]->SetTileType(type1);

					grid.tiles_single_grid[x][y]->GetTileTexture();
					grid.tiles_single_grid[x][y]->RenderTile();
					type1_tile_amount--;
				}
				else
				{
					grid.tiles_single_grid[x][y]->SetTileType(type2);

					grid.tiles_single_grid[x][y]->GetTileTexture();
					grid.tiles_single_grid[x][y]->RenderTile();
				}

				c++;
				switch (d)
				{
				case 0: y = y + 1; break;
				case 1: x = x + 1; break;
				case 2: y = y - 1; break;
				case 3: x = x - 1; break;
				}
			}
			d = (d + 1) % 4;
		}
		s = s + 1;
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

void TileMap::CheckForTileEvents(SDL_Event* EventHandler)
{
	for (size_t y = 0; y < row_total_amount; y++)
	{
		for (size_t x = 0; x < column_total_amount; x++)
		{
			tiles_all[x][y].HandleEvent(EventHandler);
		}
	}

}
