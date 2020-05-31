#include "game_scene.h"
#include "paddle.h"
#include "brick.h"
#include <iostream>

Game_Scene::Game_Scene() : Scene("Game") {

				Game_Object* paddle = new Paddle("paddle.move");
				_game_objects[paddle->id()] = paddle;

				


				int bricks_x = 11;
				int bricks_y = 6;
				//int bricks_scale = 10;

				for (int y = 0; y < bricks_y; y++) {
					 
					for (int x = 0; x < bricks_x; x++) {

						std::string id = "brick.y" + std::to_string(y) + ".x." + std::to_string(x);
						std::cout << id << std::endl;

						Brick* brick = new Brick(id);
						//Game_Object* brick = new Brick("brick");
						_game_objects[brick->id()] = brick;

						float y_position = (float)50 + (y * 35);
						float x_position = (float)50 + (x * 75);

						brick-> set_translation(Vector_2D(x_position, y_position));

					}
				}


}

Game_Scene::~Game_Scene() {
}

void Game_Scene::update(SDL_Window*) {
}