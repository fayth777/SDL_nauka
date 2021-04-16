#include "Tile.h"

void Tile::set_texture(enum TileType tiletype)
{
	TileTexture.LoadTextureFromFile(GetTileTexturePath(tiletype));
}

std::string Tile::GetTileTexturePath(enum class TileType tiletype)
{
	std::string path;
	switch (tiletype)
	{
	case TileType::TILETYPE_GRASS:
			path = "textures/T_grass_1.png";
			break;
		case TileType::TILETYPE_GROUND:
			path = "textures/T_ground_1.png";
			break;
		}
	return path;
}
