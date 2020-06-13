#include "engine.h"

#include <iostream>
#include <algorithm>

#define SDL_MAIN_HANDLED
#include <SDL.h>


#include "asset.h"
#include "game_object.h"
#include "paddle.h"

Engine::Engine() {

				// Initialize SDL
				const int init_result = SDL_Init(SDL_INIT_EVERYTHING);
				const int init_result_success = 0;
				if (init_result != init_result_success)
				{
								std::cout << "Failed to initialize SDL" << std::endl;
								std::cout << "SDL Error: " << SDL_GetError() << std::endl;
								exit(1);
				}

				// Size of the window
				const char* game_title = "Break the Brick";
				const int x = 400;
				const int y = 100;
				const int width = 1200; // screen width
				const int height = 900 ; // screen height

				// Caption of the window
				_window = SDL_CreateWindow(game_title, x, y, width, height, 0);
				if (_window == nullptr)
				{
								std::cout << "Failed to create SDL window" << std::endl;
								std::cout << "SDL Error: " << SDL_GetError() << std::endl;
								exit(1);
				}

				const int first_renderer = -1;
				_renderer = SDL_CreateRenderer(_window, first_renderer, 0);
				if (_renderer == nullptr)
				{
								std::cout << "Failed to create Renderer" << std::endl;
								std::cout << "SDL Error: " << SDL_GetError() << std::endl;
								exit(1);
				}

				const int image_init_result = IMG_Init(IMG_INIT_PNG);
				const int image_init_success = IMG_INIT_PNG;
				if (image_init_result != image_init_success)
				{
								std::cout << "Failed to initialize SDL Image" << std::endl;
								std::cout << "SDL Error: " << SDL_GetError() << std::endl;
								exit(1);
				}
}

Engine::~Engine() {

}

void Engine::simulate(Uint32 milliseconds_to_simulate, Assets* assets, Scene* scene, Input* input) {
				simulate_AI(milliseconds_to_simulate, assets, scene, input);
				simulate_physics(milliseconds_to_simulate, assets, scene);
				render(milliseconds_to_simulate, assets, scene);
}

void Engine::simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Scene* scene, Input* input) {
				std::vector<Game_Object*> game_objects = scene->get_game_objects();
				for (Game_Object* game_object : game_objects)
				{
								game_object->simulate_AI(milliseconds_to_simulate, assets, input);
				}
}

void Engine::simulate_physics(Uint32 milliseconds_to_simulate, Assets* assets, Scene* scene) {
				std::vector<Game_Object*> game_objects = scene->get_game_objects();
				for (Game_Object* game_object : game_objects)
				{
								game_object->simulate_physics(milliseconds_to_simulate, assets, scene);
				}
}

void Engine::render(Uint32 miliseconds_to_simulate, Assets* assets, Scene* scene) {

				const int render_clear_success = 0;
				const int render_clear_result = SDL_RenderClear(_renderer);
				if (render_clear_result != render_clear_success)
				{
								std::cout << "Failed to clear renderer" << std::endl;
								std::cout << "SDL Error: " << SDL_GetError() << std::endl;
								exit(1);
				}

				const Uint8 red = 0;
				const Uint8 green = 0;
				const Uint8 blue = 0;
				const Uint8 alpha = 255;
				const int render_color_success = 0;
				const int render_color_result = SDL_SetRenderDrawColor(_renderer, red, green, blue, alpha);
				if (render_color_result != render_color_success)
				{
								std::cout << "Failed to set render color" << std::endl;
								std::cout << "SDL Error: " << SDL_GetError() << std::endl;
								exit(1);
				}
				
				std::vector<Game_Object*> game_objects = scene->get_game_objects();
				for (Game_Object* game_object : game_objects)
				{
								game_object->render(miliseconds_to_simulate, assets, _renderer);
				}
				
				SDL_RenderPresent(_renderer);
}

SDL_Renderer* Engine::renderer() {
				return _renderer;
}

SDL_Window* Engine::window()
{
				return _window;
}