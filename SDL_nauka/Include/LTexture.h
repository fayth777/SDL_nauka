#pragma once
#include "SDL.h"
#include "string"

class LTexture
{
public:
	//Initializes variables
	LTexture();

	LTexture(std::string path);


	//Deallocates memory
	~LTexture();

	//Loads image at specified path
	bool LoadTextureFromFile();

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

	std::string path;
};