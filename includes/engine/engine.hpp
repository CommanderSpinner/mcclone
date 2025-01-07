#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "window.hpp"
#include "glrenderer.hpp"

class Engine{
public:
    Engine(int argc, char** argv);
    ~Engine();
private:
    SDL_Event e;
    void init();
    void processInput();
    void update();
    void render();
    bool running;

    int argc;
    char** argv;
    Window window;
    std::shared_ptr<Renderer3d> renderer3d;
};

#endif
