#include "hud.h"
#include "text.h"
#include "ball.h"

HUD::HUD(std::string id) : Game_Object(id, "Texture.blank")
{
				_hud_text_color.r = 16;
				_hud_text_color.g = 16;
				_hud_text_color.b = 16;
				_hud_text_color.a = 255;
}

void HUD::render(Uint32, Assets*, Scene* scene, SDL_Renderer* renderer) {

				Game_Object* ball = scene->get_game_object("ball.move");

				_health = "Lives: " + std::to_string(ball->hp());

				Text lives(renderer, _health.c_str(), _hud_text_color, "HUD.Lives");
				lives.render(renderer, Vector_2D(25.0f, 25.0f));
}