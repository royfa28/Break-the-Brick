#pragma once

#include "game_object.h"

Game_Object::Game_Object(std::string id, std::string texture_id) : _translation(0,0), 
_velocity(0,0), _collider(0.0f, Vector_2D(0.f, 0.f)) {

				_id = id;
				_texture_id = texture_id;

				_flip = SDL_FLIP_NONE;

}

Game_Object::~Game_Object() {

}

std::string Game_Object::id() {
				return _id;
}

void Game_Object::simulate_physics(Uint32 milliseconds_to_simulate, Assets*) {

				Vector_2D velocity = _velocity;
				velocity.scale((float)milliseconds_to_simulate);

				_translation += velocity;
}

void Game_Object::render(Uint32, Assets* assets, SDL_Renderer* renderer) {

				SDL_Rect destination;

				destination.x = (int)_translation.x(); 
				destination.y = (int)_translation.y();

				destination.w = _width;
				destination.h = _height;

				const float PI = 3.14159265f;
				if (_velocity.magnitude() > 0)
				{
								if (abs(_velocity.angle()) <= (PI / 2.f))
								{
												_flip = SDL_FLIP_NONE;
								}
								else
								{
												_flip = SDL_FLIP_HORIZONTAL;
								}
				}

				Texture* texture = (Texture*)assets->get_asset(_texture_id);
				texture->render(renderer, nullptr, &destination, _flip);

				// Check circle collider texture
				{
								Texture* collider_texture = (Texture*)assets->get_asset("Texture.Collider");

								SDL_Rect collider_destination;
								collider_destination.x = (int)(_translation.x() + _collider.translation().x() - _collider.radius());
								collider_destination.y = (int)(_translation.y() + _collider.translation().y() - _collider.radius());
								collider_destination.w = (int)(_collider.radius() * 2.0f);
								collider_destination.h = (int)(_collider.radius() * 2.0f);

								collider_texture->render(renderer, nullptr, &collider_destination, SDL_FLIP_NONE);
				}

				// Check box collider texture
				{
								Texture* collider_texture = (Texture*)assets->get_asset("Texture.BoxCollider");

								SDL_Rect collider_destination;
								collider_destination.x = (int)(_translation.x() + _collider.translation().x() - _collider.width() /2);
								collider_destination.y = (int)(_translation.y() + _collider.translation().y() - _collider.height() /2);
								collider_destination.w = (int)(_collider.width());
								collider_destination.h = (int)(_collider.height());

								collider_texture->render(renderer, nullptr, &collider_destination, SDL_FLIP_NONE);
				}
}

Collision_2D Game_Object::collider() {
				return _collider;
}

Vector_2D Game_Object::translation() {
				return _translation;
}

void Game_Object::set_translation(Vector_2D translation) {
	
				_translation = translation;
}