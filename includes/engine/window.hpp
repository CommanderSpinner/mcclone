#ifndef WINDOW_HPP
#define WINDOW_HPP
#include "glad/glad.h"
#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include <SDL2/SDL_opengl.h>
#include "engine/glrenderer.hpp"
#include <memory>

class Window{
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::shared_ptr<Glrenderer> glrenderer;
public:
    Window(const char* title, int width, int height);
    ~Window();
};

#endif
