#pragma once
#include "TileMap.h"




void TileMap::SetTileIndexAndPosition()
{
	for (size_t y = 0; y < TileAllAmountOnOneSide; y++)
	{
		for (size_t x = 0; x < TileAllAmountOnOneSide; x++)
		{
			TileAll[x][y].SetIndex(x, y);
			TileAll[x][y].SetPosition(x*kTile_size, y*kTile_size);
			// tiles_all[x][y].PrintState();


		}
	}
}

void TileMap::FillAllTilesGrids()
{
	for (size_t gridx = 0; gridx < GridOfSmallGridsSideSize; gridx++)
	{
		for (size_t gridy = 0; gridy < GridOfSmallGridsSideSize; gridy++)
		{
			TileGridOfSmallGrids[gridx][gridy] = FillSingleGrid(gridx,gridy);
		}
	}
}

TileGrid TileMap::FillSingleGrid(int gridx, int gridy)
{
	TileGrid tiles_grid(TileMap::GetTileMap().SmallGridSideSize, TileMap::GetTileMap().SmallGridSideSize);
	
	for (size_t x = 0; x < SmallGridSideSize; x++)
	{
		for (size_t y = 0; y < SmallGridSideSize; y++)
		{
			tiles_grid.TileSmallGrid[x][y] = &TileAll[x + SmallGridSideSize * gridx][y + SmallGridSideSize * gridy];
			
		}
	}
	return tiles_grid;
}



void TileMap::SetAllTileType()
{
	{
		for (size_t gridx = 0; gridx < GridOfSmallGridsSideSize; gridx++)
		{
			for (size_t gridy = 0; gridy < GridOfSmallGridsSideSize; gridy++)
			{
				if (gridx < 2)
				{
					SetGridType(TileGridOfSmallGrids[gridx][gridy],67, TileType::TILETYPE_GRASS, TileType::TILETYPE_GROUND);
				}
				if (gridx == 2 )
				{
					SetGridType(TileGridOfSmallGrids[gridx][gridy],78, TileType::TILETYPE_GROUND, TileType::TILETYPE_FOREST);
				}
				if (gridx > 2 )
				{
					SetGridType(TileGridOfSmallGrids[gridx][gridy],35, TileType::TILETYPE_FOREST, TileType::TILETYPE_GROUND);
				}
			}
		}
	}
}

void TileMap::SetGridType(TileGrid& grid, const int& density, enum class TileType type1, enum class TileType type2)
{
	/*
	for (size_t y = 0; y < TileAllAmountOnOneSide; y++)
	{
		for (size_t x = 0; x < TileAllAmountOnOneSide; x++)
		{
			TileAll[x][y].SetTileType(type2);
		}
	}
	*/
	
	int type1_tile_amount = floor(grid.TileAmount * (density / 100.0));
	int type2_tile_amount = floor(grid.TileAmount - type1_tile_amount);
	int x = 0; // current position; x
	int y = 0; // current position; y
	int d = 0; // current direction; 0=RIGHT, 1=DOWN, 2=LEFT, 3=UP
	int c = 0; // counter
	int s = 1; // chain size

	// starting point
	x = ((int)floor((GridOfSmallGridsSideSize / 2.0)-1));
	y = ((int)floor((GridOfSmallGridsSideSize / 2.0)-1));

	for (int k = 1; k <= (GridOfSmallGridsSideSize)-1; k++)
	{
		for (int j = 0; j <= (k < (GridOfSmallGridsSideSize-1 ) ? 2 : 3); j++)
		{
			for (int i = 0; i < s; i++)
			{
				if (type1_tile_amount>0)
				{
					grid.TileSmallGrid[x][y]->SetTileType(type1);
					type1_tile_amount--;
				}
				else
				{
					grid.TileSmallGrid[x][y]->SetTileType(type2);

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



Tile TileMap::GetStartingTile()
{
		return TileAll[floor(TileAllAmountOnOneSide / 2)][floor(TileAllAmountOnOneSide / 2)];
}

void TileMap::CheckForTileEvents(SDL_Event* EventHandler)
{
	for (size_t y = 0; y < TileAllAmountOnOneSide; y++)
	{
		for (size_t x = 0; x < TileAllAmountOnOneSide; x++)
		{
			TileAll[x][y].HandleEvent(EventHandler);
		}
	}

}

void TileMap::ForEachTile(void (Tile::*function)()) {
	for (size_t y = 0; y < TileAllAmountOnOneSide; y++)
	{
		for (size_t x = 0; x < TileAllAmountOnOneSide; x++)
		{
			(TileAll[x][y].*function)();
		}
	}

}