#include "TextureDatabase.h"
#include "LTexture.h"
#include <algorithm>

std::map<TileType, LTexture*> TextureDatabase::*textures(nullptr);


void TextureDatabase::LoadTextures()
{
	TextureDatabase::textures = new std::map<TileType, LTexture*>();

	TextureDatabase::textures->emplace(TileType::TILETYPE_NONE, new LTexture("textures/T_empty_tile.png"));
	TextureDatabase::textures->emplace(TileType::TILETYPE_GRASS, new LTexture("textures/T_ground_1.png"));
	TextureDatabase::textures->emplace(TileType::TILETYPE_GROUND, new LTexture("textures/T_grass_1.png"));

	for (auto it = TextureDatabase::textures->begin(); it != TextureDatabase::textures->end(); it++)
	{
		it->second->LoadTextureFromFile();
	}
	// iteracja po mapie
	/*T_empty_tile.LoadTextureFromFile();
	T_ground_1.LoadTextureFromFile();
	T_grass_1.LoadTextureFromFile();*/

}

LTexture* TextureDatabase::Get(TileType type)
{
	return TextureDatabase::textures->at(type);
}