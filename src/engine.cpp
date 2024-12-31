#include "engine/engine.hpp"

void Engine::processInput()
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT) {
            running = false;
        }
    }
}

Engine::Engine()
{
    Window window;
}


void Engine::update();

void Engine::render();
