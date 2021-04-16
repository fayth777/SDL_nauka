#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

class LTexture
{
public:
	//Initializes variables
	LTexture();

	//Deallocates memory
	~LTexture();

	//Loads image at specified path
	bool LoadTextureFromFile(std::string path);

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

	const int SCREEN_WIDTH = 1024;
	const int SCREEN_HEIGHT = 768;

	bool init(); 

	//Loads media
	bool LoadTileTexture();
	//Fill screen with tiles
	void RenderTiles();
	


