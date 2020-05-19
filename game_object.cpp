#pragma once

#include "game_object.h"

Game_Object::Game_Object(std::string id, std::string texture_id) : _translation(0,0), _velocity(0,0) {
				_id = id;
				_texture_id = texture_id;

				_x = 0;
				_y = 0;

				_width = 100;
				_height = 100;

				_flip = SDL_FLIP_NONE;
}

Game_Object::~Game_Object() {

}

std::string Game_Object::id() {
				return _id;
}

void Game_Object::simulate_physics(Uint32, Assets*) {

}

void Game_Object::render(Uint32, Assets* assets, SDL_Renderer* renderer) {
				SDL_Rect destination;
				destination.x = _x;
				destination.y = _y;
				destination.w = _width;
				destination.h = _height;

				Texture* texture = (Texture*)assets->get_asset(_texture_id);
				texture->render(renderer, nullptr, &destination, _flip);
}