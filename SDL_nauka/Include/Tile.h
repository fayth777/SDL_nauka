#pragma once
#include "graphics.h"
#include "GameMain.h"
#include "GameObject.h"
#include "LTexture.h"

enum class TileType { TILETYPE_NONE, TILETYPE_GRASS, TILETYPE_GROUND, TILETYPE_FOREST };
enum class TileState { IDLE, OVERLAP, PRESSED, RELEASED};

class Tile: public GameObject
{

public:

	Tile();
	void SetPosition(int posx, int posy);
	inline void SetIndex(int x, int y) {IndexX = x; IndexY = y;}
	inline void SetTileType(enum class TileType type) {TileType = type;};
	SDL_Point GetSizeFromTexture();

	void HandleEvent(SDL_Event* EventHandler);
	
	void GetTileTexture();

	void RenderTile();

	void OnPressed();
	void OnRelease();

	void OnOverlap();
	void OnOverlapEnd();

	void PrintState();

private:
	
	TileType TileType;
	TileState TileState;
	LTexture* TileTextureBase = nullptr;
	LTexture* TileTextureOverlap = nullptr;
	SDL_Point Position;
	SDL_Point Size;
	int IndexX;
	int IndexY;
	bool test=false;
	
};

