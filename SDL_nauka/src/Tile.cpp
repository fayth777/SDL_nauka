#include "Tile.h"

void Tile::SetTexture(enum TileType tiletype)
{
	tile_texture.LoadTextureFromFile(GetTileTexturePath(tiletype));
}

void Tile::SetPosition(int posx, int posy)
{
	position.xpos = posx;
	position.ypos = posy;

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
