/*
 * Renderizable.h
 *
 *  Created on: 14/02/2014
 *      Author: Santi
 */

#ifndef RENDERIZABLE_H_
#define RENDERIZABLE_H_

class SDL_Texture;
class SDL_Renderer;
class GameRenderer;

#include <Box2D/Box2D.h>
#include <string>

class Renderizable {

public:
		b2Vec2 size;
		b2Vec2 position;
		std::string imagePath;
		SDL_Texture * sdlTexture;

		Renderizable(float x, float y,float w, float h);
		Renderizable();
		virtual ~Renderizable() {};
		virtual void onRender(GameRenderer& Renderer);
		void setImage(SDL_Renderer * sdlRenderer,  std::string filePath);
		void loadImage(SDL_Renderer * sdlRenderer);
		virtual void setPosition(float x, float y);
		virtual void setSize(float w, float h);

};

#endif /* RENDERIZABLE_H_ */
