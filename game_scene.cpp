#include "game_scene.h"
#include "paddle.h"
#include "dino.h"

Game_Scene::Game_Scene() : Scene("Game") {

				Game_Object* paddle = new Paddle("paddle.move");
				_game_objects[paddle->id()] = paddle;

				Game_Object* dino = new Dino("Dino");
				_game_objects[dino->id()] = dino;
}

Game_Scene::~Game_Scene() {
}

void Game_Scene::update(SDL_Window*) {
}