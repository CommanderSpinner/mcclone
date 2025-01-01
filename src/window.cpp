#include "engine/window.hpp"

Window::Window(const char* title, int width, int height) : width(width), height(height)
{
    sdlwindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (!sdlwindow) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        exit(1);
    }

    sdlrenderer = SDL_CreateRenderer(sdlwindow, -1, SDL_RENDERER_ACCELERATED);
    if (!sdlrenderer) {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(sdlwindow);
        exit(1);
    }

}

SDL_Window* Window::getSDLWindow()
{
    return sdlwindow;
}

int Window::getHeight()
{
    return height;
}

int Window::getWidth()
{
    return width;
}


Window::~Window() {
    SDL_DestroyRenderer(sdlrenderer);
    SDL_DestroyWindow(sdlwindow);
}
