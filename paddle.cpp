#pragma once

#include "paddle.h"

#include <iostream>

Paddle::Paddle(std::string id) : Game_Object(id, "Texture.paddle.move") {

				_x = 400;
				_y = 1170;
				_width = 100;
				_height = 15;
				_speed = 0.1f;
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
								_velocity += Vector_2D(1.0f, 0);
								std::cout << "Move right" << std::endl;
				}

				if (input->is_button_state(Input::Button::LEFT, Input::Button_State::DOWN))
				{
								_velocity += Vector_2D(-1.0f, 0);
								std::cout << "Move left" << std::endl;
				}

				_velocity.normalize();
				_velocity.scale(_speed);
}

void Paddle::set_speed(float speed) {
				_speed = speed;
}

float Paddle::speed() {
				return _speed;
}