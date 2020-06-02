#pragma once

#include "ball.h"
#include <iostream>

Ball::Ball(std::string id) : Game_Object(id, "Texture.paddle.move")
{
				// _x = 150;
				// _y = 50;
				_width = 15;
				_height = 15;
				_translation = Vector_2D(550, 800);
				xSpeed = 0.3f;
				ySpeed = -0.3f;
				_velocity = Vector_2D(xSpeed, ySpeed);
}
Ball::~Ball()
{
}

void Ball::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer)
{
				Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
				texture->update_frame(milliseconds_to_simulate);

				Game_Object::render(milliseconds_to_simulate, assets, renderer);
}

void Ball::simulate_AI(Uint32, Assets*, Input*) {

				// Making sure that the ball doesnt move beyond the game wall
				if (Game_Object::_translation.x() > (1200 - _width)) {
								xSpeed = -0.3f;
								if (ySpeed == 0.3f) {
												_velocity = Vector_2D(xSpeed, ySpeed);
												std::cout << "1" << std::endl;
								}
								else {
												_velocity = Vector_2D(xSpeed, ySpeed);
												std::cout << "2" << std::endl;
								}

				}
				else if (Game_Object::_translation.y() < 0) {
								ySpeed = 0.3f;
								if (xSpeed == 0.3f) {
												_velocity = Vector_2D( xSpeed, ySpeed);
												std::cout << "3" << std::endl;
								}
								else {
												_velocity = Vector_2D( xSpeed, ySpeed);
												std::cout << "4" << std::endl;
								}

				}
				else if (Game_Object::_translation.y() > (900 - _height)) {
								ySpeed = -0.3f;
								if (xSpeed == -0.3f) {
												_velocity = Vector_2D(xSpeed, ySpeed);
												std::cout << "5" << std::endl;
								}
								else {
												_velocity = Vector_2D(xSpeed, ySpeed);
												std::cout << "6" << std::endl;
								}
				}
				else if (Game_Object::_translation.x() < 0) {
								xSpeed = 0.3f;
								if (ySpeed == 0.3f) {
												_velocity = Vector_2D(xSpeed, ySpeed);
												std::cout << "7" << std::endl;
								}
								else {
												_velocity = Vector_2D(xSpeed, ySpeed);
												std::cout << "8" << std::endl;
								}

				}

}