#pragma once

#include "brick.h"

#include <iostream>

Brick::Brick(std::string id) : Game_Object(id, "Texture.brick") {

				// Brick size
				_width = 70;
				_height = 30;

				_boxCollider.setSize(_width, _height);
				_boxCollider.set_translation(Vector_2D(_width / 2.0f, (float)_height / 2.0f));
}

Brick::~Brick() {

}

void Brick::checkBricks(Scene* scene) {
				int brick_Count = 0;
				for (Game_Object* game_object : scene->get_game_objects()) {				// For loop to get all the IDs in the scene

								if (game_object->id() == _id)
								{
												continue;
								}

								if (game_object->id() != "paddle.move" && game_object->id() != "ball.move") {
												brick_Count++;
												std::cout << "Bricks before: " << brick_Count << std::endl;
												set_hp(brick_Count);
								}
				}
}

void Brick::simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input) {

}

void Brick::set_hp(int hp){
				_hp = hp;
}