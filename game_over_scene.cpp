#include "game_over_scene.h"

Game_Over_Scene::Game_Over_Scene() : Scene("game_over") {

				_bg_color.r = 255;
				_bg_color.g = 0;
				_bg_color.b = 0;
				_bg_color.a = 120;
}

Game_Over_Scene::~Game_Over_Scene() {

}

void Game_Over_Scene::update(SDL_Window*) {

}