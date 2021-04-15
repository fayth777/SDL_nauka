
#include "Game_main.h"
#include "graphics.h"
#include "stdio.h"
#include "string"
#include "SDL.h"






void close()
{
	//Free loaded images
	TileTexture.free();

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
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load tiles
		if (!LoadTiles())
		{
			printf("Failed to load tile texture!\n");
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event event_handler;

			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&event_handler) != 0)
				{
					//User requests quit
					if (event_handler.type == SDL_QUIT)
					{
						quit = true;
					}
				}

				//Clear screen
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				//Render top left sprite
				TileTexture.render(0, 0 );

				//Render top right sprite
				TileTexture.render(16, 0 );

				//Render bottom left sprite
				TileTexture.render(32, 32 );

				//Render bottom right sprite
				TileTexture.render(128, 32);

				//Update screen
				SDL_RenderPresent(gRenderer);
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}