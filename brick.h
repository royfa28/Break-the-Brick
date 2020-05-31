#pragma once

#include "game_object.h"


class Brick : public Game_Object {

public:

    Brick(std::string id);
    ~Brick();

    virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input) override;
};
