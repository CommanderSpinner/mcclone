#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <SDL2/SDL.h>
#include <string>
#include <iostream>

class Window{
    SDL_Window* window;
    SDL_Renderer* renderer;
public:
    Window(const char* title, int width, int height);
    ~Window();
};

#endif
