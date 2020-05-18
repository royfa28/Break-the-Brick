#pragma once

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>

#include "assets.h"

class Engine
{
public:
				Engine();
				~Engine();

				void simulate(Uint32 milliseconds_to_simulate, Assets* assets);

				SDL_Renderer* renderer();
				SDL_Window* window();

private:
				void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets);
				void simulate_physics(Uint32 milliseconds_to_simulate, Assets* assets);
				void render(Uint32 milliseconds_to_simulate, Assets* assets);

				SDL_Window* _window;
				SDL_Renderer* _renderer;
};