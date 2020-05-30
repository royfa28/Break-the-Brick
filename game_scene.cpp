#include "game_scene.h"
#include "paddle.h"

Game_Scene::Game_Scene() : Scene("Game") {

				Game_Object* paddle = new Paddle("paddle.move");
				_game_objects[paddle->id()] = paddle;

}

Game_Scene::~Game_Scene() {
}

void Game_Scene::update(SDL_Window*) {
}