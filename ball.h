#pragma once

#include "game_object.h"

class Ball : public Game_Object {

public:

    Ball(std::string id);
    ~Ball();

    virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input) override;
    virtual void render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer) override;

    void ballCollision(int response);
    //float x, y, width, height;

    float xSpeed, ySpeed;

private:
    float _speed;
};