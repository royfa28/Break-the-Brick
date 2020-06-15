#pragma once

#include "game_object.h"


class Brick : public Game_Object {

public:

    Brick(std::string id);
    ~Brick();
    
    virtual void set_hp(int hp) override;
    virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input) override;
    virtual void checkBricks(Scene* scene) override;

};
