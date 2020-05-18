#include "assets.h"

#include <iostream>

Assets::Assets(SDL_Renderer* renderer)
{
				Texture* dino_texture = new Texture("Assets/paddle_normal.png", renderer);
				_textures["Texture.paddle_normal"] = dino_texture;

				const int frame_count = 10;
				const Uint32 frame_duration_milliseconds = 100;
}

Assets::~Assets()
{

}

Texture* Assets::get_texture(std::string id)
{
				if (_textures.find(id) == _textures.end())
				{
								std::cout << "Attempted to find a texture that was not loaded. ID: " << id << std::endl;
								exit(1);
				}

				return _textures[id];
}

/*
Animated_Texture* Assets::get_animated_texture(std::string id)
{
				if (_animated_textures.find(id) == _animated_textures.end())
				{
								std::cout << "Attempted to find an animated texture that was not loaded. ID: " << id << std::endl;
								exit(1);
				}

				return _animated_textures[id];
}
*/