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

Engine::Engine(): window("MC Clone", 800, 600)
{
}

Engine::~Engine()
{
    SDL_Quit();
}



void Engine::update()
{

}

void Engine::render()
{

}
