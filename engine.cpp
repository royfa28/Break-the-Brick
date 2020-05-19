#include "engine.h"

#include <iostream>
#include <algorithm>

#define SDL_MAIN_HANDLED
#include <SDL.h>


#include "texture.h"

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
				const int x = 100;
				const int y = 100;
				const int width = 900;
				const int height = 1200;

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

void Engine::simulate(Uint32 milliseconds_to_simulate, Assets* assets) {
				simulate_AI(milliseconds_to_simulate, assets);
				simulate_physics(milliseconds_to_simulate, assets);
				render(milliseconds_to_simulate, assets);
}

void Engine::simulate_AI(Uint32, Assets*) {
				
}

void Engine::simulate_physics(Uint32, Assets*) {
				
}

void Engine::render(Uint32, Assets* assets) {

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
				
				{
								Texture* paddle = assets->get_texture("Texture.paddle_normal");
								SDL_Rect destination;
								destination.x = 400;
								destination.y = 1170;
								destination.w = 100;
								destination.h = 15;
								paddle->render(_renderer, nullptr, &destination, SDL_FLIP_NONE);
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