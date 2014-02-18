/*
 * test.h
 *
 *  Created on: 14/02/2014
 *      Author: Santi
 */

#ifndef IMAGE_MANAGER_H_
#define IMAGE_MANAGER_H_

class SDL_Renderer;
class SDL_Texture;

#include <string>

class ImageManager
{
	public:
		static SDL_Texture* loadImage(SDL_Renderer * renderer, std::string path);
};



#endif /* IMAGE_MANAGER_H_ */
