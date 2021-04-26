#pragma once
#include "LTexture.h"
#include "Tile.h"
#include <map>


class TextureDatabase
{
public:

	static void LoadTextures();
	static LTexture* Get(TileType type);

private:
	static std::map<TileType, LTexture*> tile_textures;

};

