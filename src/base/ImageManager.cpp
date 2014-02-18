/*
 * ImageManager.cpp
 *
 *  Created on: 14/02/2014
 *      Author: Santi
 */


#include "base/ImageManager.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

SDL_Texture* ImageManager::loadImage( SDL_Renderer * renderer,std::string path){

	SDL_Surface * image = IMG_Load(path.c_str());

	if (image == NULL)
		{
	printf("IMG_LOAD: %s\n", IMG_GetError());
		throw "Image not loaded";
		}
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);

	return texture;

}





