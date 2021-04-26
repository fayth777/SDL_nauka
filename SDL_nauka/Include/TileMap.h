#pragma once
#include "graphics.h"
#include "Tile.h"
#include <vector>

struct TilesGrid { std::vector<std::vector<Tile*>> tiles_single_grid; };


class TileMap
{
	
public:
	TileMap() : tiles_all(TileMap::Get_Row_amount(), std::vector<Tile>(TileMap::Get_Colums_amount())) {};
	
	TileMap(const TileMap&) = delete;

	static TileMap& GetTileMap() {
		static TileMap Tilemap;
		return Tilemap;
	}
	void SetTileIndexAndPosition();
	void FillAllTilesGrids();
	TilesGrid FillSingleGrid(int gridx, int gridy);
	void SetAllTileType();
	void SetTileTexture();
	void RenderTiles();
	Tile GetStartingTile();
	inline static int Get_Colums_amount() { return column_total_amount; };
	inline static int Get_Row_amount() { return row_total_amount; };

private:
	
	const int kTile_size = 32;
	Tile starting_tile;
	inline static int column_total_amount = 300;
	inline static int row_total_amount = 300;
	int grids_vector_side_size = 10;
	int tile_single_grid_row_size = row_total_amount / grids_vector_side_size;
	int tile_single_grid_column_size = column_total_amount / grids_vector_side_size;

	//2d vector of all tiles
	std::vector<std::vector<Tile>> tiles_all;
	//2d vector comprised of grids of tiles which are parts of the whole grid
	std::vector<std::vector<TilesGrid>> tiles_grids;
	

};

