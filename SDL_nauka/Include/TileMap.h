#pragma once
#include "graphics.h"
#include "Tile.h"
#include <vector>



struct TileGrid
{
public: 
	TileGrid() : tiles_single_grid(0, std::vector < Tile*>(0)), tiles_amount(0){};
	TileGrid(int xsize, int ysize) : tiles_single_grid(xsize, std::vector < Tile*>(ysize)),tiles_amount(xsize*ysize) {}
	std::vector<std::vector<Tile*>> tiles_single_grid;
	int tiles_amount;
};

class TileMap
{
	
public:
	TileMap() : tiles_all(TileMap::Get_Row_amount(), std::vector<Tile>(TileMap::Get_Colums_amount())),
		tiles_grids(TileMap::grids_vector_side_size, std::vector<TileGrid>(TileMap::grids_vector_side_size))
		 {}
	
	TileMap(const TileMap&) = delete;

	static TileMap& GetTileMap() {
		static TileMap Tilemap;
		return Tilemap;
	};
	void SetTileIndexAndPosition();
	void FillAllTilesGrids();
	TileGrid FillSingleGrid(int gridx, int gridy);
	void SetAllTileType();
	void SetTileTexture();
	void SetGridType(TileGrid &grid,int density, enum class TileType type1, enum class TileType type2);

	inline int GetGridsVectorSideSize() { return grids_vector_side_size; };
	inline int GetGridRowSize() { return grid_row_size; };
	inline int GetGridColumnSize() { return grid_column_size; };

	void RenderTiles();
	Tile GetStartingTile();
	inline static int Get_Colums_amount() { return column_total_amount; };
	inline static int Get_Row_amount() { return row_total_amount; };

private:
	
	const int kTile_size = 32;
	Tile starting_tile;
	inline static int column_total_amount = 100;
	inline static int row_total_amount = 100;
	int grids_vector_side_size = 10;
	int grid_row_size = row_total_amount / grids_vector_side_size;
	int grid_column_size = column_total_amount / grids_vector_side_size;

	//2d vector of all tiles
	std::vector<std::vector<Tile>> tiles_all;
	//2d vector comprised of grids of references to tiles which are parts of the whole grid
	std::vector<std::vector<TileGrid>> tiles_grids;

	TileGrid tile_grid;
	

};

