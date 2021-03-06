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
    virtual void set_scores(int score) override;

    void ballCollision(int response);
    void ball_PaddleCollision(int response);

    //void updateHealth(SDL_Renderer);

    void resetPosition();

    float xSpeed, ySpeed;

private:
    SDL_Color text_color;

    float _speed;
    std::string _health;
    std::string _score;
};