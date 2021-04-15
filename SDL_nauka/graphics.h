#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>



	const int SCREEN_WIDTH = 1024;
	const int SCREEN_HEIGHT = 768;

	bool init(SDL_Window* gWindow, SDL_Renderer* gRenderer);

	//Loads media
	bool loadMedia();

	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;

	//The window renderer
	SDL_Renderer* gRenderer = NULL;

	LTexture gSpriteSheetTexture;

class LTexture
{
public:
	//Initializes variables
	LTexture();

	//Deallocates memory
	~LTexture();

	//Loads image at specified path
	bool loadFromFile(std::string path);

	//Deallocates texture
	void free();

	//Renders texture at given point
	void render(int x, int y, SDL_Rect* clip = NULL);

	//Gets image dimensions
	int getWidth();
	int getHeight();

private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;
};
