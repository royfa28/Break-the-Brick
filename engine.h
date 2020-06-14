#pragma once

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>

#include "assets.h"
#include "scene.h"
#include "input.h"

class Engine {

public:
				Engine();
				~Engine();

				void simulate(Uint32 milliseconds_to_simulate, Assets* assets, Scene* scene, Input* input);

				SDL_Renderer*			renderer();
				SDL_Window*					window();

private:
				void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Scene* scene, Input* input);
				void simulate_physics(Uint32 milliseconds_to_simulate, Assets* assets, Scene* scene);
				void render(Uint32 milliseconds_to_simulate, Assets* assets, Scene* scene);

				SDL_Window*					_window;
				SDL_Renderer*			_renderer;
};