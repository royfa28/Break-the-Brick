#pragma once

#include "ball.h"
#include "brick.h"
#include "text.h"

#include <iostream>
#include <random>
#include <time.h>

Ball::Ball(std::string id) : Game_Object(id, "Texture.paddle.move") {

				_width = 15;
				_height = 15;
				
				xSpeed = 0.3f;
				ySpeed = -0.3f;

				_hp = 3;
				set_hp(_hp);

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

				{
								SDL_Color text_color;
								text_color.r = 255;
								text_color.g = 255;
								text_color.b = 0;
								text_color.a = 255;

								Text lives(renderer, "Lives: " + this->hp(), text_color, "Lives.Text");

								//lives.render(renderer, _translation + Vector_2D(0,0));
				}
}

void Ball::simulate_physics(Uint32 milliseconds_to_simulate, Assets* assets, Scene* scene)
{
				Vector_2D velocity = _velocity;
				velocity.scale((float)milliseconds_to_simulate);

				_translation += velocity;

				//Game_Object* bricks = scene->get_game_object("brick");
				for (Game_Object* game_object : scene->get_game_objects()) {				// For loop to get all the IDs in the scene

								if (game_object->id() == _id)
								{
												continue;
								}

								Circle_2D circleCollider = Circle_2D(_circlecollider.radius(), _circlecollider.translation() + _translation);
								Box_2D boxCollider = Box_2D(game_object->_boxCollider.width(), game_object->_boxCollider.height(), game_object->translation());

								float intersection_depth = circleCollider.intersection_depth(boxCollider, circleCollider);
								float ballPaddleCollision = circleCollider.ballPaddleCollision(boxCollider, circleCollider);

								if (game_object->id() != "paddle.move") {
												if (intersection_depth != 0.1f)
												{
																//MATT override this function to get access to this function easier
																ballCollision(intersection_depth);
																Brick bricks = bricks;
																bricks.checkBricks(scene);																																		// Function to check for all the bricks object

																scene->remove_game_objects(game_object->id());														// Removing the brick that got hit base on the ID
																bricks.set_hp(bricks.hp() - 1);																													// Go to function to set the hp / total amount of bricks
																//std::cout << "Bricks after: " << bricks.hp() << std::endl;

																if (bricks.hp() <= 80) {
																				//std::cout << "You WIN!!!" << std::endl;
																}

												}
								}
								else if (game_object->id() == "paddle.move") {
												if (ballPaddleCollision != 0.1f) {
																ball_PaddleCollision(ballPaddleCollision);
												}
								}

				}
}

void Ball::simulate_AI(Uint32, Assets*, Input*) {

				// Making sure that the ball doesnt move beyond the game wall
				if (Game_Object::_translation.x() > (1200 - _width) && _velocity.x() > 0) {
								_velocity = Vector_2D(-_velocity.x(), _velocity.y());
				}
				else if (Game_Object::_translation.y() < 0 && _velocity.y() < 0) {
								_velocity = Vector_2D(_velocity.x(), -_velocity.y());
				}
				else if (Game_Object::_translation.y() > (900 - _height) && _velocity.y() > 0) {
								this->set_hp(this->hp() - 1);
								if (this->hp() == 0) {
												std::cout << "Game over" << std::endl;
								}
								else {
												std::cout << "Current life: " << this->hp() << std::endl;
												resetPosition();
								}
								
								
				}
				else if (Game_Object::_translation.x() < 0 && _velocity.x() < 0) {
								_velocity = Vector_2D(-_velocity.x(), _velocity.y());
				}
}

void Ball::ballCollision(int response) {

				if ((response == 3 && _velocity.y() < 0) || (response == 1 && _velocity.y() > 0))
								_velocity = Vector_2D(_velocity.x(), -_velocity.y());
				if (response == 2 || response == 0)
								_velocity = Vector_2D(-_velocity.x(), _velocity.y());

}

void Ball::ball_PaddleCollision(int response) {
				if (response == 1 || response == 4) {
								if (_velocity.x() > 0) {
												xSpeed = 0.45f;
												_velocity = Vector_2D(xSpeed, -_velocity.y());
								}
								if (_velocity.x() < 0) {
												xSpeed = -0.45f;
												_velocity = Vector_2D(xSpeed, -_velocity.y());
								}
				}
				else {
								if (_velocity.x() > 0) {
												xSpeed = 0.3f;
												_velocity = Vector_2D(xSpeed, -_velocity.y());
								}
								if (_velocity.x() < 0) {
												xSpeed = -0.3f;
												_velocity = Vector_2D(xSpeed, -_velocity.y());
								}
				}
}

void Ball::resetPosition() {
				xSpeed = 0.3f;
				ySpeed = -0.3f;

				int seed = (int)time(NULL);
				std::minstd_rand0 generator(seed);
				float random = (float)generator() / generator.min();

				std::minstd_rand0 randomXGenerator(random);
				float randomXPos = ((float)randomXGenerator() / randomXGenerator.max()) * 1100;

				std::cout << randomXPos << std::endl;

				Game_Object::_translation = Vector_2D(randomXPos, 800);
				Game_Object::_velocity = Vector_2D(xSpeed, ySpeed);
}

void Ball::set_hp(int hp) {
				_hp = hp;
}