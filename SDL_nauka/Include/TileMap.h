#pragma once
#include "graphics.h"
#include "Tile.h"
#include <vector>



struct TileGrid
{
public: 
	TileGrid() : TileSmallGrid(0, std::vector < Tile*>(0)), TileAmount(0){};
	TileGrid(int xsize, int ysize) : TileSmallGrid(xsize, std::vector < Tile*>(ysize)), TileAmount(xsize*ysize) {}
	std::vector<std::vector<Tile*>> TileSmallGrid;
	int TileAmount;
};

class TileMap
{
	
public:
	TileMap() : TileAll(TileMap::GetTileAllAmountOnOneSide(), std::vector<Tile>(TileMap::GetTileAllAmountOnOneSide())),
		TileGridOfSmallGrids(TileMap::GridOfSmallGridsSideSize, std::vector<TileGrid>(TileMap::GridOfSmallGridsSideSize))
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
	

	void SetGridType(TileGrid &grid,const float& density, enum class TileType type1, enum class TileType type2);


	inline int GetGridsVectorSideSize() { return GridOfSmallGridsSideSize; };
	inline int GetGridRowSize() { return SmallGridSideSize; };
	inline static int GetTileAllAmountOnOneSide() { return TileAllAmountOnOneSide; };
	inline int GetTileSize() { return kTile_size; };

	
	Tile GetStartingTile();
	
	void CheckForTileEvents(SDL_Event* EventHandler);

	void ForEachTile(void (Tile::* function)());

private:
	
	const int kTile_size = 64;
	Tile TileStarting;
	const static int GridOfSmallGridsSideSize = 10;
	const static int  SmallGridSideSize = 5;
	inline static int TileAllAmountOnOneSide = GridOfSmallGridsSideSize * SmallGridSideSize;
	
	
	

	//2d vector of all tiles
	std::vector<std::vector<Tile>> TileAll;
	//2d vector comprised of grids of references to tiles which are parts of the whole grid
	std::vector<std::vector<TileGrid>> TileGridOfSmallGrids;

	

};

