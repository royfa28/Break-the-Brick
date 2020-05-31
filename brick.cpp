#pragma once

#include "brick.h"

#include <iostream>

Brick::brick(std::string id) : Game_Object(id, "Texture.Bb.move") {

	//x = 400;
	//_y = 1170;
	_width = 100;
	_height = 15;
	_speed = 0.3f;

	_translation = Vector_2D(400, 500);
}

Brick::~brick() {

}

void Brick::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer)
{
	Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	Game_Object::render(milliseconds_to_simulate, assets, renderer);
}
