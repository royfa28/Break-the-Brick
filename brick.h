
#pragma once

#include "game_object.h"


class Brick : public Game_Object {

public:

    Brick(std::string id);
    ~Brick();

    virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input) override;
    //virtual void render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer) override;

    float x, y, width, height;

    void shrink();
    void update(float dt);


private:
    int originalWidth;
  

};
