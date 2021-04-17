
#include "Game_main.h"
#include "graphics.h"
#include "stdio.h"
#include "string"
#include "SDL.h"


SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

LTexture TileTexture;



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
	if (!Init())
	{
		printf("Failed to initialize!\n");
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

				RenderTiles();

				//Update screen
				SDL_RenderPresent(gRenderer);
			}
		
	}

	//Free resources and close SDL
	close();

	return 0;
}