#pragma once

#include "game_object.h"


class Brick : public Game_Object {

public:

    Brick(std::string id);
    ~Brick();
    
    int bricks();
    void set_bricks(int brick);

    virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input) override;

    int _bricks;
};
