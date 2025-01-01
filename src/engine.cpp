#include "engine/engine.hpp"

Engine::Engine(int argc, char** argv): window("MC Clone", 800, 600)
{
    this->argc = argc;
    this->argv = argv;
    running = true;
    this->init();

    // main loop
    while(this->running){
        this->processInput();
        this->update();
        this->render();
    }
}

void Engine::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init failed: " << SDL_GetError() << std::endl;
        exit(1);
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    glEnable(GL_DEPTH_TEST);  // Enable depth testing for 3D rendering
    glEnable(GL_BLEND);       // Enable transparency
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Set blending mode
    glEnable(GL_CULL_FACE);   // Enable face culling (improves performance)
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // Set the default background color

    // Print OpenGL version
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
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
