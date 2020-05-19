#pragma once

#include "dino.h"

Dino::Dino(std::string id)
				: Game_Object(id, "Texture.Dino")
{
				// _x = 50;
				// _y = 50;
				_translation = Vector_2D(50, 50);
}
Dino::~Dino()
{
}
void Dino::simulate_AI(Uint32, Assets*, Input*)
{
}
