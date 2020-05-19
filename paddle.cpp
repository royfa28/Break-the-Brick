#pragma once

#include "paddle.h"

Paddle::Paddle(std::string id) : Game_Object(id, "Texture.paddle") {

				_x = 400;
				_y = 1170;
				_width = 100;
				_height = 15;
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
				}

				if (input->is_button_state(Input::Button::LEFT, Input::Button_State::DOWN))
				{
								_velocity += Vector_2D(-1.0f, 0);
				}

				_velocity.normalize();
				_velocity.scale(0.1f);
}