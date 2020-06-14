#pragma once

#include "game_object.h"

class Paddle : public Game_Object {

public:

    Paddle(std::string id);
    ~Paddle();

    virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input) override;
    virtual void render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer) override;

    float x, y, width, height;

    void set_hp(int hp);

private:
    int originalWidth;
    float _speed;
};