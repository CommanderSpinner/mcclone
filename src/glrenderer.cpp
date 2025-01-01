#include "engine/glrenderer.hpp"

Glrenderer::Glrenderer(SDL_Window* window)
{
    // Create OpenGL context
    context = SDL_GL_CreateContext(window);
    if (!context) {
        std::cerr << "Failed to create OpenGL context: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        exit(-1);
    }

    // Load OpenGL functions with GLAD
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        SDL_GL_DeleteContext(context);
        SDL_DestroyWindow(window);
        exit(-1);
    }
}

Glrenderer::~Glrenderer()
{
    SDL_GL_DeleteContext(context);
}
