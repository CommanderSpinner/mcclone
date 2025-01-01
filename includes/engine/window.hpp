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
    SDL_Window* sdlwindow;
    SDL_Renderer* sdlrenderer;
    const int width, height;
public:
    SDL_Window* getSDLWindow();
    int getWidth();
    int getHeight();
    Window(const char* title, int width, int height);
    ~Window();
};

#endif
