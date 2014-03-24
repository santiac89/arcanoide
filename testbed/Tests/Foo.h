#ifndef FOOTEST_H
#define FOOTEST_H

#include <Box2D/Box2D.h>
#include "base/GameEngine.h"
#include <SDL2/SDL.h>
#include "base/GameRenderer.h"
class FooTest : public Test
    {
        public:
		GameEngine engine;
		GameRenderer gameRenderer;

		FooTest() :  engine(m_world), gameRenderer(b2Vec2(10.0f,30.0f),b2Vec2(800.0f,600.0f)) {

		m_world->SetGravity(b2Vec2(0.0f,0.0f));
		engine.init();

		} //do nothing, no scene yet

        void Step(Settings* settings)
        {
            //run the default physics and rendering
            Test::Step(settings);

            //show some text in the main screen
            m_debugDraw.DrawString(5, m_textLine, "Now we have a foo test");
            m_textLine += 15;

			SDL_Event sdlEvent;

			while (SDL_PollEvent(&sdlEvent))
			{
				engine.manageUserEvent(sdlEvent);
			}

			engine.loop();

			gameRenderer.render(engine);

        }

        static Test* Create()
        {
            return new FooTest;
        }
    };

  #endif
