#include "game_scene.h"
#include "paddle.h"
#include "brick.h"
#include "ball.h"
#include "text.h"

#include <iostream>

Game_Scene::Game_Scene() : Scene("Game") {

				Game_Object* paddle = new Paddle("paddle");
				_game_objects[paddle->id()] = paddle;

				// Number of rows and columns for the bricks
				int bricks_x = 14;
				int bricks_y = 6;

				int brick_count = bricks_x * bricks_y;
				Brick bricks = bricks;
				bricks.set_hp(brick_count);
				
				std::string texture_id = "";
				// Populate the bricks depending on the number of rows and columns
				for (int y = 0; y < bricks_y; y++) {
								for (int x = 0; x < bricks_x; x++) {

												// Move the next brick position based on the width and height of the brick + 5
												float y_position = (float)80 + (y * 40);
												float x_position = (float)40 + (x * 80);

												std::string id = "brick.y" + std::to_string(y_position) + ".x." + std::to_string(x_position);
												if (y == 0 || y == 1 || y == 2) {
																texture_id = "Texture.purpleBrick";
												}
												else if (y == 3 || y == 4 || y == 5) {
																texture_id = "Texture.redBrick";
												}

												Brick* brick = new Brick(id, texture_id);			
												_game_objects[brick->id()] = brick;
												
												// Set the position fo each bricks
												brick-> set_translation(Vector_2D(x_position, y_position));
								}
				}

				// Ball object
				Game_Object* ball = new Ball("ball.move");
				_game_objects[ball->id()] = ball;
}

Game_Scene::~Game_Scene() {
}

void Game_Scene::update(SDL_Window*) {
}