#pragma once
#pragma once

#define SDL_MAIN_HANDLED
#include <SDL.h>

#include <string>

class Texture
{
public:
				Texture(std::string path, SDL_Renderer* renderer);
				~Texture();

				SDL_Texture* data();

				void render(SDL_Renderer* renderer, SDL_Rect* clip, SDL_Rect* destination, SDL_RendererFlip flip);

private:
				SDL_Texture* _data;
};