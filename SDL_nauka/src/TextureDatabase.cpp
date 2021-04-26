#include "TextureDatabase.h"
#include "LTexture.h"
#include <algorithm>

std::map<TileType, LTexture*> TextureDatabase::tile_textures;

void TextureDatabase::LoadTextures()
{
	
	TextureDatabase::tile_textures.emplace(TileType::TILETYPE_NONE, new LTexture("textures/T_empty_tile.png"));
	TextureDatabase::tile_textures.emplace(TileType::TILETYPE_GRASS, new LTexture("textures/T_ground_1.png"));
	TextureDatabase::tile_textures.emplace(TileType::TILETYPE_GROUND, new LTexture("textures/T_grass_1.png"));
	TextureDatabase::tile_textures.emplace(TileType::TILETYPE_FOREST, new LTexture("textures/T_trees_1.pngg"));


	for (auto it = TextureDatabase::tile_textures.begin(); it != TextureDatabase::tile_textures.end(); it++)
	{
		it->second->LoadTextureFromFile();
	}

}

LTexture* TextureDatabase::Get(TileType type)
{
	return TextureDatabase::tile_textures.at(type);
}