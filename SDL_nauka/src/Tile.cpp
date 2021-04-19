#include "Tile.h"

void Tile::SetTexture()
{
	tile_texture.LoadTextureFromFile(GetTileTexturePath(tile_type));
}

void Tile::SetPosition(int posx, int posy)
{
	screen_position.xpos = posx;
	screen_position.ypos = posy;

}

void Tile::RenderTile()
{ tile_texture.Render(screen_position.xpos, screen_position.ypos); }

std::string Tile::GetTileTexturePath(enum class TileType tiletype)
{
	std::string path;
	switch (tiletype)
	{
	case TileType::TILETYPE_NONE:
		path = "textures/T_empty_tile.png";
		break;
	case TileType::TILETYPE_GRASS:
		path = "textures/T_grass_1.png";
		break;
	case TileType::TILETYPE_GROUND:
		path = "textures/T_ground_1.png";
		break;
	}
	return path;
}
