#pragma once

#include "game_object.h"
#include <stack>
#include <string>



class Menu_Buttons : public Game_Object
{
public:
	Menu_Buttons(std::string id);
	~Menu_Buttons();

	

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input) = 0;
	//virtual void simulate_physics(Uint32 milliseconds_to_simulate, Assets* assets, Scene* scene);
	virtual void render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer);


	enum class State
	{
		Start,
		Settings,
		Exit
	};

	void push_state(State state, Assets* assets, Input* input);
	void pop_state(Assets* assets, Input* input);

private:
	void handle_enter_state(State state, Assets* assets, Input* input);
	void handle_exit_state(State state, Assets* assets);

	std::stack<State> _state;
};