#include "Tile.h"
#include "TextureDatabase.h"



Tile::Tile()
{
	screen_position.xpos = 0;
	screen_position.ypos = 0;
	index_x =0;
	index_y =0;
	tile_type = TileType::TILETYPE_NONE;

}

void Tile::SetPosition(int posx, int posy)
{
	screen_position.xpos = posx;
	screen_position.ypos = posy;

}

void Tile::RenderTile()
{ tile_texture->Render(screen_position.xpos, screen_position.ypos); }



void Tile::GetTileTexture()
{
	
	switch (tile_type)
	{
	case TileType::TILETYPE_NONE:
		tile_texture =  TextureDatabase::GetTileTexture(TileType::TILETYPE_NONE);
		break;
	case TileType::TILETYPE_GRASS:
		tile_texture = TextureDatabase::GetTileTexture(TileType::TILETYPE_GRASS);
		break;
	case TileType::TILETYPE_GROUND:
		tile_texture = TextureDatabase::GetTileTexture(TileType::TILETYPE_GROUND);
		break;
	case TileType::TILETYPE_FOREST:
		tile_texture = TextureDatabase::GetTileTexture(TileType::TILETYPE_FOREST);
		break;
	}
	return;
}
