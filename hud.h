#include <SDL.h>
#include <string>

#include "scene.h"
#include "game_object.h"

class HUD : public Game_Object
{
public:

				HUD(std::string id);
				~HUD();

				void updateHealth(Scene* scene, SDL_Renderer);
				virtual void render(Uint32 milliseconds_to_simulate, Assets* assets, Scene* scene, SDL_Renderer* renderer);

private:
				SDL_Color _hud_text_color;

				std::string _health;

};