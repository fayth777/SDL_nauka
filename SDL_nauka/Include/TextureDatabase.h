#pragma once
#include "LTexture.h"

class TextureDatabase
{
public:
	
	static LTexture T_empty_tile;
	static LTexture T_ground_1;
	static LTexture T_grass_1;

	

	static void LoadTextures();
private:
	inline static LTexture tile_textures_arr[3]{
		 T_empty_tile, T_ground_1, T_grass_1
	};

};

