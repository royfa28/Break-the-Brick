#pragma once

#include "game_object.h"

class Ball : public Game_Object {

public:

    Ball(std::string id);
    ~Ball();

    virtual void simulate_physics(Uint32 milliseconds_to_simulate, Assets* assets, Scene* scene);
    virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input) override;
    virtual void render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer) override;
    virtual void set_hp(int hp) override;

    void ballCollision(int response);
    void ball_PaddleCollision(int response);

    void resetPosition();

    float xSpeed, ySpeed;

private:
    float _speed;
};