#include "TextureDatabase.h"
#include "LTexture.h"
#include <algorithm>

std::map<TileType, LTexture*> TextureDatabase::textures;

void TextureDatabase::LoadTextures()
{
	
	TextureDatabase::textures.emplace(TileType::TILETYPE_NONE, new LTexture("textures/T_empty_tile.png"));
	TextureDatabase::textures.emplace(TileType::TILETYPE_GRASS, new LTexture("textures/T_ground_1.png"));
	TextureDatabase::textures.emplace(TileType::TILETYPE_GROUND, new LTexture("textures/T_grass_1.png"));

	for (auto it = TextureDatabase::textures.begin(); it != TextureDatabase::textures.end(); it++)
	{
		it->second->LoadTextureFromFile();
	}

}

LTexture* TextureDatabase::Get(TileType type)
{
	return TextureDatabase::textures.at(type);
}