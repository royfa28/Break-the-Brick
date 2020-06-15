#include "assets.h"
#include "animated_texture.h"
#include "sound.h"

#include <iostream>

Assets::Assets(SDL_Renderer* renderer) {

				// Create paddle moving texture.
				{
								const int frame_count = 10;
								const Uint32 frame_duration_milliseconds = 100;
								Asset* paddle_texture = new Animated_Texture("Texture.paddle", "Assets/paddle.png", 
												renderer, frame_count, frame_duration_milliseconds);
								_assets[paddle_texture->id()] = paddle_texture;
				}

				// Create purple brick texture
				{
								Asset* brick_texture = new Texture("Texture.purpleBrick", "Assets/purpleBrick.png", renderer);
								_assets[brick_texture->id()] = brick_texture;
				}

				// Create red brick texture
				{
								Asset* brick_texture = new Texture("Texture.redBrick", "Assets/redBrick.png", renderer);
								_assets[brick_texture->id()] = brick_texture;
				}

				// Blank texture
				{
								Asset* blank = new Texture("Texture.blank", "Assets/blank.png", renderer);
								_assets[blank->id()] = blank;
				}

				// Cache the ball texture
				{
								const int frame_count = 10;
								const Uint32 frame_duration_milliseconds = 100;
								Asset* ball_texture = new Animated_Texture("Texture.ball.move", "Assets/ball.png",
												renderer, frame_count, frame_duration_milliseconds);
								_assets[ball_texture->id()] = ball_texture;
				}

				// Create collider texture
				{
								Texture* texture = new Texture("Texture.Collider", "Assets/collider.png", renderer);
								_assets[texture->id()] = texture;
				}

				// Create collider texture
				{
								Texture* texture = new Texture("Texture.BoxCollider", "Assets/box_collider.png", renderer);
								_assets[texture->id()] = texture;
				}

				// Create music sound
				{
								Sound* sound = new Sound("Sound.Music", "Assets/RockTransition.wav");
								_assets[sound->id()] = sound;

								Mix_PlayChannel(0, sound->data(), -1);
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
