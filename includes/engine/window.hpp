#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <SDL2/SDL.h>
#include <string>

class Window{
    SDL_Window* window;
    Window(const std::string& title, int width, int height);
    ~Window();
};

#endif
