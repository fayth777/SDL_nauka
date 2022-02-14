#pragma once
#include "GameMain.h"
#include "SDL.h"
#include "graphics.h"
#include "stdio.h"
#include "string"
#include "LTexture.h"
#include "TileMap.h"
#include "TextureDatabase.h"
//#include "Cursor.h"


void close()
{
	//Free loaded images


	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
 
int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!Init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		
		
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event EventHandler;

			// Init Graphics
			GraphicsProfiler GraphicsProfiler;
			TextureDatabase::LoadTextures();

			TileMap::GetTileMap().FillAllTilesGrids();
			TileMap::GetTileMap().SetTileIndexAndPosition();
			TileMap::GetTileMap().SetAllTileType();

			

			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&EventHandler) != 0)
				{
					//User requests quit
					if (EventHandler.type == SDL_QUIT)
					{
						quit = true;
					}
					// Handle Input for the cursor
					else
					{
						TileMap::GetTileMap().CheckForTileEvents(&EventHandler);
					}
					
				}

				//Clear screen
				GraphicsProfiler.PrintFPS();
				
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				TileMap::GetTileMap().ForEachTile(&Tile::GetTileTexture);
				TileMap::GetTileMap().ForEachTile(&Tile::RenderTile);
				
				
				SDL_RenderPresent(gRenderer);
				
			}
		

	}

	//Free resources and close SDL
	close();

	return 0;
}