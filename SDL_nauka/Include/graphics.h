#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

//The window we'll be rendering to
extern SDL_Window* gWindow;

//The window renderer
extern SDL_Renderer* gRenderer;

	const int kSCREEN_WIDTH = 1024;
	const int kSCREEN_HEIGHT = 768;

	//Engine initialization function
	bool Init(); 
	
	//Fill screen with tiles
	void RenderTiles();
	
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
	void Render(int x, int y, SDL_Rect* clip = NULL);

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

