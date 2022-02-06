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
	Size.x = 32;
	Size.y = 32;
}

void Tile::SetPosition(int posx, int posy)
{
	Position.x = posx;
	Position.y = posy;
}

void Tile::RenderTile()
{ TileTexture->Render(Position.x, Position.y); }

void Tile::OnPressed()
{
	TileTexture->setAlpha(120);

}

void Tile::OnRelease()
{
	TileTexture->setAlpha(255);

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
		TileTexture =  TextureDatabase::GetTileTexture(TileType::TILETYPE_NONE);
		break;
	case TileType::TILETYPE_GRASS:
		TileTexture = TextureDatabase::GetTileTexture(TileType::TILETYPE_GRASS);
		break;
	case TileType::TILETYPE_GROUND:
		TileTexture = TextureDatabase::GetTileTexture(TileType::TILETYPE_GROUND);
		break;
	case TileType::TILETYPE_FOREST:
		TileTexture = TextureDatabase::GetTileTexture(TileType::TILETYPE_FOREST);
		break;
	}
	return;
}

void Tile::SetSizeFromTexture()
{
	Size.x = (TileTexture != nullptr) ?	TileTexture->getWidth() : 0;
	Size.y = (TileTexture != nullptr) ? TileTexture->getHeight() : 0;
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
