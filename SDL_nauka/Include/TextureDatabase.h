#pragma once
#include "LTexture.h"
#include "LTexture.h"
#include "Tile.h"
#include <map>
#include <algorithm>


class TextureDatabase
{
public:

	static void LoadTextures();
	static LTexture* GetTileTexture(TileType type);
	static LTexture* GetCursorTexture();

private:
	static std::map<TileType, LTexture*> tile_textures;
	static LTexture* CursorTexture;
};

