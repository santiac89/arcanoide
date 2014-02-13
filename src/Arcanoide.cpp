
#include <Box2D/Box2D.h>

#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>



// This is a simple example of building and running a simulation
// using Box2D. Here we create a large ground box and a small dynamic
// box.
// There are no graphics for this example. Box2D is meant to be used
// with your rendering engine in your game engine.
int main(int argc, char** argv)
{
        B2_NOT_USED(argc);
        B2_NOT_USED(argv);
        bool quit = false;
         SDL_Event event;
         SDL_Init(SDL_INIT_VIDEO);

        SDL_Window * window = SDL_CreateWindow("SDL2 Keyboard/Mouse events",
              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
          SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);


        // Define the gravity vector.
        b2Vec2 gravity(0.0f, 10.0f);

        // Construct a world object, which will hold and simulate the rigid bodies.
        b2World world(gravity);

        // Define the ground body.
        b2BodyDef groundBodyDef;
        groundBodyDef.position.Set(5.0f, 480.0f);

        // Call the body factory which allocates memory for the ground body
        // from a pool and creates the ground box shape (also from a pool).
        // The body is also added to the world.
        b2Body* groundBody = world.CreateBody(&groundBodyDef);

        // Define the ground box shape.
        b2PolygonShape groundBox;

        // The extents are the half-widths of the box.
        groundBox.SetAsBox(50.0f, 10.0f);

        // Add the ground fixture to the ground body.
        groundBody->CreateFixture(&groundBox, 0.0f);

        // Define the dynamic body. We set its position and call the body factory.
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(320.0f, 0.0f);
        b2Body* body = world.CreateBody(&bodyDef);

        // Define another box shape for our dynamic body.
        b2PolygonShape dynamicBox;
        dynamicBox.SetAsBox(1.0f, 1.0f);

        // Define the dynamic body fixture.
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &dynamicBox;

        // Set the box density to be non-zero, so it will be dynamic.
        fixtureDef.density = 1.0f;

        // Override the default friction.
        fixtureDef.friction = 0.3f;

        // Add the shape to the body.
        body->CreateFixture(&fixtureDef);

        // Prepare for simulation. Typically we use a time step of 1/60 of a
        // second (60Hz) and 10 iterations. This provides a high quality simulation
        // in most game scenarios.
        float32 timeStep = 1.0f / 60.0f;
        int32 velocityIterations = 6;
        int32 positionIterations = 2;

        SDL_Surface * image = IMG_Load("spaceship.png");

        if (image == NULL) return 0;

        SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
        SDL_FreeSurface(image);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        // This is our little game loop.
        b2Vec2 position = body->GetPosition();
        SDL_Rect dstrect = { position.x,position.y, 64, 64 };
        while (!quit)
            {
                SDL_PollEvent(&event);

                switch (event.type)
                {
                case SDL_QUIT:
                    quit = true;
                    break;
                }
                // Instruct the world to perform a single step of simulation.
                // It is generally best to keep the time step and iterations fixed.
                world.Step(timeStep, velocityIterations, positionIterations);

                // Now print the position and angle of the body.

              position = body->GetPosition();
              dstrect.x = position.x;
              dstrect.y = position.y;

              float32 angle = body->GetAngle();

              printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
			  SDL_RenderClear(renderer);
			  SDL_RenderCopy(renderer, texture, NULL, &dstrect);
			  SDL_RenderPresent(renderer);
        }

        // When the world destructor is called, all bodies and joints are freed. This can
        // create orphaned pointers, so be careful about your world management.
        SDL_DestroyTexture(texture);
          SDL_DestroyRenderer(renderer);
          SDL_DestroyWindow(window);
          SDL_Quit();
        return 0;
}
