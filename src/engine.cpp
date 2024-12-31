#include "engine/engine.hpp"

Engine::Engine(int argc, char** argv): window("MC Clone", 800, 600)
{
    this->argc = argc;
    this->argv = argv;
    running = true;

    this->processInput();

    while(this->running){
        this->processInput();
        this->update();
        this->render();
    }
}

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

void Engine::update()
{

}

void Engine::render()
{

}

Engine::~Engine()
{
    SDL_Quit();
}
