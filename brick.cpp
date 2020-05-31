#pragma once

#include "brick.h"

#include <iostream>

Brick::Brick(std::string id) : Game_Object(id, "Texture.brick") {

	//x = 400;
	//_y = 1170;
	_width = 70;
	_height = 30;
	

	_translation = Vector_2D(50, 50);
}

Brick::~Brick() {

}

void Brick::simulate_AI(Uint32, Assets*, Input*)
{

}

/*void Brick::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer)
{
	
}*/
