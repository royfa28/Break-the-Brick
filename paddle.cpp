#pragma once

#include "paddle.h"

#include <iostream>

Paddle::Paddle(std::string id) : Game_Object(id, "Texture.paddle.move") {

				_width = 120;
				_height = 15;
				_speed = 0.3f;

				_boxCollider.setSize(_width, _height);
				_boxCollider.set_translation(Vector_2D((float)_width / 2.0f, (float)_height / 2.0f));

				// Spawn the paddle on the bottom middle part of the game
				_translation = Vector_2D(550, 870);
}

Paddle::~Paddle() {

}

void Paddle::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer)
{
				Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
				texture->update_frame(milliseconds_to_simulate);

				Game_Object::render(milliseconds_to_simulate, assets, renderer);
}


void Paddle::simulate_AI(Uint32, Assets*, Input* input)
{
				_velocity = Vector_2D(0, 0);

				if (input->is_button_state(Input::Button::RIGHT, Input::Button_State::DOWN))
				{

								// Making sure that the paddle doesnt move beyond the game wall
								if (Game_Object::_translation.x() > (1200 - _width)) {
												_velocity = Vector_2D(0, 0);
												std::cout << "Wall right" << std::endl;
								}
								else {
												_velocity += Vector_2D(1.0f, 0);
												std::cout << "Move right" << std::endl;
								}
								
				}

				if (input->is_button_state(Input::Button::LEFT, Input::Button_State::DOWN))
				{
								if (Game_Object::_translation.x() < 0) {
												_velocity = Vector_2D(0, 0);
												std::cout << "Wall left" << std::endl;
								}
								else {
												_velocity += Vector_2D(-1.0f, 0);
												std::cout << "Move left" << std::endl;
								}

				}

				_velocity.normalize();
				_velocity.scale(_speed);
}