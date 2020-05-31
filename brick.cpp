#pragma once

#include "brick.h"

#include <iostream>

Brick::Brick(std::string id) : Game_Object(id, "Texture.brick") {


				// Brick size
				_width = 70;
				_height = 30;
}

Brick::~Brick() {

}

void Brick::simulate_AI(Uint32, Assets*, Input*)
{

}
