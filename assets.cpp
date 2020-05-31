#include "assets.h"
#include "animated_texture.h"

#include <iostream>

Assets::Assets(SDL_Renderer* renderer) {

				// Create paddle moving texture.
				{
								const int frame_count = 10;
								const Uint32 frame_duration_milliseconds = 100;
								Asset* paddle_texture = new Animated_Texture("Texture.paddle.move", "Assets/paddle_normal.png", 
												renderer, frame_count, frame_duration_milliseconds);
								_assets[paddle_texture->id()] = paddle_texture;
				}


				// Create brick  texture.
				{
								Asset* brick_texture = new Texture("Texture.brick", "Assets/brick.png", renderer);
								_assets[brick_texture->id()] = brick_texture;
				}

}

Assets::~Assets() {

}

Asset* Assets::get_asset(std::string id) {

				if (_assets.find(id) == _assets.end())
				{
								std::cout << "Attempted to find a texture that was not loaded. ID: " << id << std::endl;
								exit(1);
				}

				return _assets[id];
}
