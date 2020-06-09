#pragma once

#include "brick.h"

#include <iostream>

Brick::Brick(std::string id) : Game_Object(id, "Texture.brick") {

				// Brick size
				_width = 70;
				_height = 30;

				_collider.setSize(_width, _height);
				_collider.set_translation(Vector_2D(_width / 2.0f, (float)_height / 2.0f));
}

Brick::~Brick() {

}

void Brick::simulate_AI(Uint32, Assets*, Input*)
{

}
