#include "Tile.h"
#include "TextureDatabase.h"



Tile::Tile()
{
	Position.x = 0;
	Position.y = 0;
	IndexX =0;
	IndexY =0;
	TileType = TileType::TILETYPE_NONE;
	TileState = TileState::IDLE;
	GetTileTexture();
	Size = GetSizeFromTexture();
}

void Tile::SetPosition(int posx, int posy)
{
	Position.x = posx;
	Position.y = posy;
}

void Tile::RenderTile()
{ TileTextureBase->Render(Position.x, Position.y); 
switch (TileState)
{
case TileState::IDLE:
	break;
case TileState::OVERLAP:
	TileTextureOverlap->Render(Position.x, Position.y);
	break;
case TileState::PRESSED:
	break;
case TileState::RELEASED:
	break;
default:
	break;
}
}


void Tile::OnPressed()
{


}

void Tile::OnRelease()
{


}

void Tile::OnOverlap()
{
}

void Tile::OnOverlapEnd()
{
}

void Tile::PrintState()
{
	printf("Tile Parameters: ");
	printf("Position: %i, %i ", Position.x, Position.y);
	printf("Size: %i, %i ", Size.x, Size.y);
}



void Tile::GetTileTexture()
{
	
	switch (TileType)
	{
	case TileType::TILETYPE_NONE:
		TileTextureBase =  TextureDatabase::GetTileTexture(TileType::TILETYPE_NONE);
		break;
	case TileType::TILETYPE_GRASS:
		TileTextureBase = TextureDatabase::GetTileTexture(TileType::TILETYPE_GRASS);
		break;
	case TileType::TILETYPE_GROUND:
		TileTextureBase = TextureDatabase::GetTileTexture(TileType::TILETYPE_GROUND);
		break;
	case TileType::TILETYPE_FOREST:
		TileTextureBase = TextureDatabase::GetTileTexture(TileType::TILETYPE_FOREST);
		break;
	}
	TileTextureOverlap = TextureDatabase::GetTileOverlapTexture();

	return;
}

SDL_Point Tile::GetSizeFromTexture()
{
	SDL_Point Point;
	Point.x = (TileTextureBase != nullptr) ? TileTextureBase->getWidth() : 0;
	Point.y = (TileTextureBase != nullptr) ? TileTextureBase->getHeight() : 0;

	return Point;
}

void Tile::HandleEvent(SDL_Event* EventHandler)
{

	//If mouse event happened
	if (EventHandler->type == SDL_MOUSEMOTION || EventHandler->type == SDL_MOUSEBUTTONDOWN || EventHandler->type == SDL_MOUSEBUTTONUP)
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState(&x, &y);


		//Check if mouse is in button
		bool inside = true;

		//Mouse is left of the button
		if (x < Position.x)
		{
			inside = false;
		}
		//Mouse is right of the button
		else if (x > Position.x + Size.x)
		{
			inside = false;
		}
		//Mouse above the button
		else if (y < Position.y)
		{
			inside = false;
		}
		//Mouse below the button
		else if (y > Position.y + Size.y)
		{
			inside = false;
		}

		//Mouse is outside button
		if (!inside)
		{
			TileState = TileState::IDLE;
			OnOverlapEnd();
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch (EventHandler->type)
			{
			case SDL_MOUSEMOTION:
				TileState = TileState::OVERLAP;
				OnOverlap();
				break;

			case SDL_MOUSEBUTTONDOWN:
				TileState = TileState::PRESSED;
				OnPressed();
				break;

			case SDL_MOUSEBUTTONUP:
				TileState = TileState::RELEASED;
				OnRelease();
				break;
			}

		}
	}
}
