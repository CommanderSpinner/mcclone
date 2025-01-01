#ifndef ENGINE_HPP
#define ENGINE_HPP
#include "window.hpp"

class Engine{
public:
    Engine(int argc, char** argv);
    ~Engine();
private:
    void init();
    void processInput();
    void update();
    void render();
    bool running;

    int argc;
    char** argv;
    Window window;
};

#endif
