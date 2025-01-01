#ifndef GLRENDERER_HPP
#define GLRENDERER_HPP
#include "glad/glad.h"
#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include <SDL2/SDL_opengl.h>

class Glrenderer
{
    SDL_GLContext context;

public:
    Glrenderer(SDL_Window* window);
    ~Glrenderer();
};

#endif
