#pragma once

#define SDL_MAIN_HANDLED
#include <SDL.h>

#include <string>

class Paddle {

public:
    float x, y, width, height;

    void shrink();
    void expand();
    void reset();
    void update(float dt);

private:
    int originalWidth;
};