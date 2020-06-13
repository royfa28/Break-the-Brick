#pragma once

#include "ball.h"
#include <iostream>
#include <random>
#include <time.h>

Ball::Ball(std::string id) : Game_Object(id, "Texture.paddle.move") {

				_width = 15;
				_height = 15;
				
				xSpeed = 0.1f;
				ySpeed = -0.1f;

				// Randomly generate a number for the X position.
				int seed = (int)time(NULL);
				std::minstd_rand0 generator(seed);
				float random = (float)generator() / generator.min();
				
				std::minstd_rand0 randomXGenerator(random);
				float randomXPos = ((float)randomXGenerator() / randomXGenerator.max()) * 1100;

				std::cout << randomXPos << std::endl;

				_translation = Vector_2D(randomXPos, 800);
				_velocity = Vector_2D(xSpeed, ySpeed);


				_circlecollider.set_radius(_width / 2.0f);
				_circlecollider.set_translation(Vector_2D(_width / 2.0f, (float)_height / 2.0f));
}

Ball::~Ball() {
}


void Ball::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer) {
				Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
				texture->update_frame(milliseconds_to_simulate);

				Game_Object::render(milliseconds_to_simulate, assets, renderer);
}

void Ball::simulate_AI(Uint32, Assets*, Input*) {

				// Making sure that the ball doesnt move beyond the game wall
				if (Game_Object::_translation.x() > (1200 - _width)) {
								xSpeed = -0.1f;																																	// Moving with x Negative
								if (ySpeed == 0.1f) {																											// If the ball is moving down then bounce up
												_velocity = Vector_2D(xSpeed, ySpeed);
												std::cout << "1" << std::endl;
								}
								else {																																										// If the ball is moving up then bounce down
												_velocity = Vector_2D(xSpeed, ySpeed);
												std::cout << "2" << std::endl;
								}

				}
				else if (Game_Object::_translation.y() < 0) {
								ySpeed = 0.1f;
								if (xSpeed == 0.1f) {
												_velocity = Vector_2D( xSpeed, ySpeed);
												std::cout << "3" << std::endl;
								}
								else {
												_velocity = Vector_2D( xSpeed, ySpeed);
												std::cout << "4" << std::endl;
								}

				}
				else if (Game_Object::_translation.y() > (900 - _height)) {
								ySpeed = -0.1f;
								if (xSpeed == -0.1f) {
												_velocity = Vector_2D(xSpeed, ySpeed);
												std::cout << "5" << std::endl;
								}
								else {
												_velocity = Vector_2D(xSpeed, ySpeed);
												std::cout << "6" << std::endl;
								}
				}
				else if (Game_Object::_translation.x() < 0) {
								xSpeed = 0.1f;
								if (ySpeed == 0.1f) {
												_velocity = Vector_2D(xSpeed, ySpeed);
												std::cout << "7" << std::endl;
								}
								else {
												_velocity = Vector_2D(xSpeed, ySpeed);
												std::cout << "8" << std::endl;
								}

				}
}

void Ball::ballCollision(int response) {

				std::cout << "It works" << std::endl;
				xSpeed = 0.3f;
				ySpeed = -0.3f;
				// Response 0: left, 1: Top, 2: Right, 3: Bottom
				if (xSpeed == 0.3f) {
								// Ball is moving in the positive X direction >> Right
								if (ySpeed == 0.3f) {
												// Ball is moving in the positive Y direction >> Bottom
												if (response == 0 || response == 1) {
																_velocity = Vector_2D(-xSpeed, ySpeed);
																std::cout << "Left or Top" << std::endl;
												}
												else {
																_velocity = Vector_2D(xSpeed, -ySpeed);
																std::cout << "Right or Bot" << std::endl;
												}
								}
								else if (ySpeed == -0.3f) {
												// Ball is moving in the negative Y direction >> Top
												if (response == 0 || response == 3) {
																_velocity = Vector_2D(-xSpeed, ySpeed);
																std::cout << "Left or Bot" << std::endl;
												}
												else {
																_velocity = Vector_2D(xSpeed, -ySpeed);
																std::cout << "Right or Top" << std::endl;
												}
								}
				}
				else if (xSpeed == -0.3f) {
								// Ball is moving on negative X direction >> Left
								if (ySpeed == 0.3f) {
												// Ball is moving in the positive Y direction >> Bottom
												if (response == 1 || response == 2) {
																_velocity = Vector_2D(-xSpeed, ySpeed);
																std::cout << "Right or Top" << std::endl;
												}
												else {
																_velocity = Vector_2D(xSpeed, -ySpeed);
																std::cout << "Left or Bottom" << std::endl;
												}
								}
								else if (ySpeed == -0.3f) {
												// Ball is moving in the negative Y direction >> Top
												if (response == 2 || response == 3) {
																_velocity = Vector_2D(-xSpeed, ySpeed);
																std::cout << "Right or Bottom" << std::endl;
												}
												else {
																_velocity = Vector_2D(xSpeed, -ySpeed);
																std::cout << "Left or Top" << std::endl;
												}
								}
				}


}