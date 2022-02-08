#include "TextureDatabase.h"




std::map<TileType, LTexture*> TextureDatabase::tile_textures;
LTexture* TextureDatabase::CursorTexture;
LTexture* TextureDatabase::TileOverlapTexture;

void TextureDatabase::LoadTextures()
{
	
	TextureDatabase::tile_textures.emplace(TileType::TILETYPE_NONE, new LTexture("textures/T_empty_tile.png"));
	TextureDatabase::tile_textures.emplace(TileType::TILETYPE_GRASS, new LTexture("textures/T_grass_1.png"));
	TextureDatabase::tile_textures.emplace(TileType::TILETYPE_GROUND, new LTexture("textures/T_ground_1.png"));
	TextureDatabase::tile_textures.emplace(TileType::TILETYPE_FOREST, new LTexture("textures/T_trees_1.png"));


	for (auto it = TextureDatabase::tile_textures.begin(); it != TextureDatabase::tile_textures.end(); it++)
	{
		it->second->LoadTextureFromFile();
	}


	TextureDatabase::CursorTexture = new LTexture("textures/mouse_pointer.png");
	TextureDatabase::CursorTexture->LoadTextureFromFile();

	TextureDatabase::TileOverlapTexture = new LTexture("textures/T_TileOverlap.png");
	TextureDatabase::TileOverlapTexture->setColorKeyValues(230, 218, 191);
	TextureDatabase::TileOverlapTexture->setShouldColorKey(true);
	TextureDatabase::TileOverlapTexture->LoadTextureFromFile();


}

LTexture* TextureDatabase::GetTileTexture(TileType type)
{
	return TextureDatabase::tile_textures.at(type);
}

LTexture* TextureDatabase::GetCursorTexture()
{
	if (TextureDatabase::CursorTexture==nullptr)
	{
		printf("No Cursor texture!\n");
	}
	return TextureDatabase::CursorTexture;
}

LTexture* TextureDatabase::GetTileOverlapTexture()
{
	return TextureDatabase::TileOverlapTexture;
}
