#ifndef GLRENDERER_HPP
#define GLRENDERER_HPP
#include "glad/glad.h"
#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_image.h>

class Renderer3d
{
private:
    SDL_GLContext context;
public:
    void render3d();
    Renderer3d(SDL_Window* window, int width, int height);
    ~Renderer3d();
    static GLuint loadTexture(const char* filePath);
};

#endif
