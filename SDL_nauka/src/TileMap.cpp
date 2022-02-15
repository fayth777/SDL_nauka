#pragma once
#include "TileMap.h"
#include "GeneralFunctions.h"




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
				if (gridx < 3)
				{
					SetGridType(TileGridOfSmallGrids[gridx][gridy],0.3, TileType::TILETYPE_GRASS, TileType::TILETYPE_GROUND);
				}
				if (gridx == 3 )
				{
					SetGridType(TileGridOfSmallGrids[gridx][gridy],0.7, TileType::TILETYPE_GROUND, TileType::TILETYPE_FOREST);
				}
				if (gridx > 3 )
				{
					SetGridType(TileGridOfSmallGrids[gridx][gridy],0.5, TileType::TILETYPE_FOREST, TileType::TILETYPE_GROUND);
				}
			}
		}
	}
}


/*
*@param[out] Type1Density: Value between 0 and 1. The higher the value the higher chances for Tile of type 1 to appear.
*/
void TileMap::SetGridType(TileGrid& grid, const float& Type1Density, enum class TileType type1, enum class TileType type2)
{
	float TileTypeA = static_cast<float>(SmallGridSideSize) / 2.f;
	float TileTypeB = 0.f;

	for (size_t y = 0; y < SmallGridSideSize; y++)
	{
		for (size_t x = 0; x < SmallGridSideSize; x++)
		{
			float chance = GetRandom(0, 1);
			printf(" % f", chance);
			if (chance<=Type1Density)
			{
				grid.TileSmallGrid[x][y]->SetTileType(type1);

			}
			else
			{
				grid.TileSmallGrid[x][y]->SetTileType(type2);

			}
		}
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