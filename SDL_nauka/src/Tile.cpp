#include "Tile.h"

void Tile::set_texture(enum TileType tiletype)
{
	TileTexture.LoadTextureFromFile(GetTileTexturePath(tiletype));
}

std::string Tile::GetTileTexturePath(enum TileType tiletype)
{
	std::string path;
		switch (tiletype)
		{
		case TileType::TILETYPE_GRASS:
			path = "textures/T_grass_1.png";
		case TileType::TILETYPE_GROUND:
			path = "textures/T_ground_1.png";
		}
	return path;
}
