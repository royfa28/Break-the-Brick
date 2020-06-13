#pragma once

#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <string>

#include "assets.h"
#include "input.h"
#include "scene.h"

#include "vector_2D.h"
#include "box_2D.h"
#include "circle_2D.h"

class Game_Object {

public:
				Game_Object(std::string id, std::string texture_id);
				~Game_Object();

				std::string id();

				virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input) = 0;
				virtual void simulate_physics(Uint32 milliseconds_to_simulate, Assets* assets, Scene* scene);
				virtual void render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer);

				Vector_2D translation();
				Box_2D boxCollider();
				Circle_2D circleCollider();

				void set_translation(Vector_2D translation);
				void set_velocity(Vector_2D velocity);

				Box_2D _boxCollider;

protected:
				std::string _id;
				std::string _texture_id;

				Vector_2D _translation;
				Vector_2D _velocity;

				Circle_2D _circlecollider;
				

				int _x;
				int _y;

				int _width;
				int _height;

				SDL_RendererFlip _flip;
};