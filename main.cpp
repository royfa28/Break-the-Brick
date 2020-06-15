#include <iostream>
#include <chrono>
#include <thread>

#include "engine.h"
#include "assets.h"
#include "game_scene.h"
#include "menu_scene.h"
#include "menu_buttons.h"
#include "input.h"
#include <SDL_mixer.h>
#include <SDL_assert.h>


int main(void)
{
				Engine* engine = new Engine();
				Assets* assets = new Assets(engine->renderer());
				Scene* menu_scene = new Menu_Scene();
				//Scene* game_scene = new Game_Scene();
				Input* input = new Input();
				Editor* editor = new Editor(L"Game"); //object

				
				



				const Uint32 milliseconds_per_seconds = 1000;
				const Uint32 frames_per_second = 60;
				const Uint32 frame_time_ms = milliseconds_per_seconds / frames_per_second;

				Uint32 frame_start_time_ms = 0;
				Uint32 frame_end_time_ms = frame_time_ms;

				//-------------------------------------------------
				std::stack<Scene*> scenes;
				scenes.push(new Menu_Scene());


				bool isRunning = true;
				bool gameScene = false;

				// For handling with event
				SDL_Event event;

				while (!input->is_button_state(Input::Button::QUIT, Input::Button_State::PRESSED))
				{

					if (/*(menu_buttons->texture_id() == "Texture.Menu.Start") &&*/ input->is_button_state(Input::Button::SPACE, Input::Button_State::PRESSED))
					{
						//go to game scene
						scenes.push(new Game_Scene());
						Sound* sound = (Sound*)assets->get_asset("Sound.Music");
						Mix_PlayChannel(0, sound->data(), -1);
						Mix_Volume(0, MIX_MAX_VOLUME / 8);
						//gameScene = true;
						isRunning = false;
					}
					else if (/*(menu_buttons->texture_id() == "Texture.Menu.Settings") &&*/ input->is_button_state(Input::Button::SPACE, Input::Button_State::PRESSED))
					{
						//go to settings scene
					}
					else if (/*(menu_buttons->texture_id() == "Texture.Menu.Exit") &&*/ input->is_button_state(Input::Button::SPACE, Input::Button_State::PRESSED))
					{
						//exit game
					}
								/*Uint32 previous_frame_duration = frame_end_time_ms - frame_start_time_ms;
								frame_start_time_ms = SDL_GetTicks();


								

								input->get_input();
								engine->simulate(previous_frame_duration, assets, game_scene, input);

								const Uint32 current_time_ms = SDL_GetTicks();
								const Uint32 frame_duration_ms = current_time_ms - frame_start_time_ms;
								if (frame_duration_ms < frame_time_ms)
								{
												const Uint32 time_to_sleep_for = frame_time_ms - frame_duration_ms;
												std::this_thread::sleep_for(std::chrono::milliseconds(time_to_sleep_for));
								}

								frame_end_time_ms = SDL_GetTicks();*/
				}

				return 0;
}