#include "engine/glrenderer.hpp"
#include "engine/window.hpp"

Renderer3d::Renderer3d(SDL_Window* window, int width, int height)
{
    // Create OpenGL context
    context = SDL_GL_CreateContext(window);
    if (!context) {
        std::cerr << "Failed to create OpenGL context: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    // Load OpenGL functions with GLAD
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        SDL_GL_DeleteContext(context);
        exit(-1);
    }

    glViewport(0, 0, width, height);
}

void Renderer3d::render3d()
{

}

GLuint Renderer3d::loadTexture(const char* filePath)
{
    // Load image using SDL_image
    SDL_Surface* surface = IMG_Load(filePath);
    if (!surface) {
        std::cerr << "Failed to load texture: " << IMG_GetError() << std::endl;
        return 0;
    }

    // Generate and bind OpenGL texture
    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Determine image format
    GLenum format;
    if (surface->format->BytesPerPixel == 4) { // RGBA
        format = GL_RGBA;
    } else if (surface->format->BytesPerPixel == 3) { // RGB
        format = GL_RGB;
    } else {
        std::cerr << "Unsupported image format" << std::endl;
        SDL_FreeSurface(surface);
        glDeleteTextures(1, &textureID);
        return 0;
    }

    // Upload texture data to GPU
    glTexImage2D(GL_TEXTURE_2D, 0, format, surface->w, surface->h, 0, format, GL_UNSIGNED_BYTE, surface->pixels);
    glGenerateMipmap(GL_TEXTURE_2D);

    // Unbind texture and free surface
    glBindTexture(GL_TEXTURE_2D, 0);
    SDL_FreeSurface(surface);

    return textureID;
}

Renderer3d::~Renderer3d()
{
    // Delete OpenGL context
    SDL_GL_DeleteContext(context);
}
