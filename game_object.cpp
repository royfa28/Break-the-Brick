#pragma once

#include "game_object.h"

Game_Object::Game_Object(std::string id, std::string texture_id) : _translation(0,0), 
_velocity(0,0), _circlecollider(0.0f , Vector_2D(0.f, 0.f)), _boxCollider(0.0f, 0.0f, Vector_2D(0.f, 0.f)) {

				_id = id;
				_texture_id = texture_id;

				_flip = SDL_FLIP_NONE;

}

Game_Object::~Game_Object() {

}

std::string Game_Object::id() {
				return _id;
}

void Game_Object::simulate_physics(Uint32 milliseconds_to_simulate, Assets*, Scene* scene) {

				Vector_2D velocity = _velocity;
				velocity.scale((float)milliseconds_to_simulate);

				_translation += velocity;


				for (Game_Object* game_object : scene->get_game_objects()) {				// For loop to get all the IDs in the scene

								if (game_object->id() == _id)
								{
												continue;
								}

								if (game_object->id() != "paddle.move") {

								}

								/*
												Can I put if statement for game_object id?

												if id == paddle 
																do not destroy game_object
												else
																destroy game_object
								*/

								Circle_2D circleCollider = Circle_2D(_circlecollider.radius(), _circlecollider.translation() + _translation);
								Box_2D boxCollider = Box_2D(game_object->_boxCollider.width(), game_object->_boxCollider.height(), game_object->translation());

								float intersection_depth = circleCollider.intersection_depth(boxCollider, circleCollider);
								
								if (intersection_depth == 0.0f) {
												scene->remove_game_objects(game_object->id());
								}
								/*
								Are they the same? Or is one way easier than the other?

												float intersection_depth = circleCollider.intersection_depth(boxCollider);
												float intersection_depth = boxCollider.intersection_depth(circleCollider);
								*/

								/*
												Not sure on how to do the code for box -> circle collision
								*/
				}


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
								collider_destination.x = (int)(_translation.x() + _circlecollider.translation().x() - _circlecollider.radius());
								collider_destination.y = (int)(_translation.y() + _circlecollider.translation().y() - _circlecollider.radius());
								collider_destination.w = (int)(_circlecollider.radius() * 2.0f);
								collider_destination.h = (int)(_circlecollider.radius() * 2.0f);

								collider_texture->render(renderer, nullptr, &collider_destination, SDL_FLIP_NONE);
				}

				// Check box collider texture
				{
								/*Texture* collider_texture = (Texture*)assets->get_asset("Texture.BoxCollider");

								SDL_Rect collider_destination;
								collider_destination.x = (int)(_translation.x() + _boxCollider.translation().x() - _boxCollider.width() /2);
								collider_destination.y = (int)(_translation.y() + _boxCollider.translation().y() - _boxCollider.height() /2);
								collider_destination.w = (int)(_boxCollider.width());
								collider_destination.h = (int)(_boxCollider.height());

								collider_texture->render(renderer, nullptr, &collider_destination, SDL_FLIP_NONE);*/
				}
}

Circle_2D Game_Object::circleCollider() {
				return _circlecollider;
}

Box_2D Game_Object::boxCollider() {
				return _boxCollider;
}

Vector_2D Game_Object::translation() {
				return _translation;
}

void Game_Object::set_translation(Vector_2D translation) {
	
				_translation = translation;
}