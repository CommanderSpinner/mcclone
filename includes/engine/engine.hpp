#ifndef ENGINE_HPP
#define ENGINE_HPP
#include "window.hpp"

class Engine{
    Engine();
    void processInput();
    void update();
    void render();

    bool running;
    Window window;
};

#endif
