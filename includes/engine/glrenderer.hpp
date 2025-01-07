#ifndef GLRENDERER_HPP
#define GLRENDERER_HPP

#include "glad/glad.h"
#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "utils.hpp"
#include <fstream>

class Renderer3d
{
private:
    SDL_GLContext context;
    SDL_Window* sdlwindow;
    glm::vec3 cameraPosition;  // Camera position for view matrix
    glm::vec3 cameraTarget;    // Camera target for view matrix
    glm::vec3 upDirection;     // Camera up direction (usually (0, 1, 0))
    GLuint shaderProgram;
    GLuint VAO;

public:
    Renderer3d(SDL_Window* sdlwindow, int width, int height);
    ~Renderer3d();

    // Rendering Functions
    void render3d();
    static GLuint loadTexture(const char* filePath);

    // Shader Functions
    GLuint loadShader(const char* shaderCode, GLenum shaderType);
    void createShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource);

    // Vertex Buffer / Vertex Array Objects
    void createMesh(float* vertices, size_t size, bool includeTexCoords);

    // Projection & View Matrices
    glm::mat4 createProjectionMatrix(float fov, float aspectRatio, float near, float far);
    glm::mat4 createViewMatrix(glm::vec3 cameraPosition, glm::vec3 cameraTarget, glm::vec3 upDirection);

    // Clear Color
    void setClearColor(float r, float g, float b, float a);

    // Handle Input (e.g., for Camera control)
    void handleInput(SDL_Event &event);

    // Uniform handling (e.g., MVP matrix)
    void setUniformMat4(GLuint program, const char* name, glm::mat4 matrix);

    // Lighting
    struct Light {
        glm::vec3 position;
        glm::vec3 color;
    };
    Light pointLight = {{1.0f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f}};
    void setLightUniforms(GLuint program, Light &light);

    // Set camera position (to update view matrix based on user input)
    void setCameraPosition(glm::vec3 position);
    glm::vec3 getCameraPosition() const;
};

#endif
