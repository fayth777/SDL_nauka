#include "TextureDatabase.h"
#include "LTexture.h"
#include <algorithm>






	LTexture TextureDatabase::T_empty_tile("textures/T_empty_tile.png");
	LTexture TextureDatabase::T_ground_1("textures/T_ground_1.png");
	LTexture TextureDatabase::T_grass_1("textures/T_grass_1.png");


void TextureDatabase::LoadTextures()
{
	T_empty_tile.LoadTextureFromFile();
	T_ground_1.LoadTextureFromFile();
	T_grass_1.LoadTextureFromFile();

}
