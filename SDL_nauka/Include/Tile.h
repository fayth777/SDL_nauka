#pragma once
#include "graphics.h"
#include "Game_main.h"
#include "LTexture.h"

enum class TileType { TILETYPE_NONE, TILETYPE_GRASS, TILETYPE_GROUND, TILETYPE_FOREST };
enum class TileState { IDLE, OVERLAP, PRESSED, RELEASED};

class Tile
{

public:

	Tile();
	void SetPosition(int posx, int posy);
	inline void SetIndex(int x, int y) {IndexX = x; IndexY = y;}
	inline void SetTileType(enum class TileType type) {TileType = type;};
	void SetSizeFromTexture();

	void HandleEvent(SDL_Event* EventHandler);
	
	void GetTileTexture();

	void RenderTile();

	void OnPressed();
	void OnRelease();

	void OnOverlap();
	void OnOverlapEnd();

private:
	
	TileType TileType;
	TileState TileState;
	LTexture* TileTexture = nullptr;
	SDL_Point Position;
	SDL_Point Size;
	int IndexX;
	int IndexY;
	
};

