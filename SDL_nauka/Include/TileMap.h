#pragma once
#include "graphics.h"
#include "Tile.h"
#include <vector>

class TileMap
{
	
public:
	TileMap() : tiles_2Dvect(TileMap::Get_Row_amount(), std::vector<Tile>(TileMap::Get_Colums_amount())) {};
	
	TileMap(const TileMap&) = delete;

	static TileMap& GetTileMap() {
		static TileMap Tilemap;
		return Tilemap;
	}
	void SetTileIndexAndPosition();
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
	std::vector<std::vector<Tile>> tiles_2Dvect;
};

