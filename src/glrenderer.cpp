#include "engine/glrenderer.hpp"
#include "engine/window.hpp"

Renderer3d::Renderer3d(SDL_Window* sdlwindow, int width, int height)
{
    // Create OpenGL context
    this->sdlwindow = sdlwindow;
    context = SDL_GL_CreateContext(sdlwindow);
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

    // for test triangle ------
    using namespace prefixes;
    std::string vertexShaderSource = utils::getShaderCode("vertex_shader.glsl");


    std::string fragmentShaderSource = utils::getShaderCode("fragment_shader.glsl");
    createShaderProgram(vertexShaderSource.c_str(), fragmentShaderSource.c_str());

    // Triangle vertices
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // Bottom left
         0.5f, -0.5f, 0.0f, // Bottom right
         0.0f,  0.5f, 0.0f  // Top
    };

    // Create and bind VAO
    createMesh(vertices, sizeof(vertices), false);
	// end of test traingle code in constructor ----
}

//rendering happens here
void Renderer3d::render3d()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    //test triangle ----
    // Use the shader program
    glUseProgram(shaderProgram);

    // Bind VAO and draw the triangle
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glBindVertexArray(0); // Unbind VAO
    glUseProgram(0);      // Unbind shader program
    // end of test triangle code ---

    // Swap buffers
    SDL_GL_SwapWindow(this->sdlwindow);
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

GLuint Renderer3d::loadShader(const char* shaderCode, GLenum shaderType) {
    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &shaderCode, nullptr);
    glCompileShader(shader);

    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "Shader compilation failed: " << infoLog << std::endl;
    }
    return shader;
}

void Renderer3d::createShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource) {
    GLuint vertexShader = loadShader(vertexShaderSource, GL_VERTEX_SHADER);
    GLuint fragmentShader = loadShader(fragmentShaderSource, GL_FRAGMENT_SHADER);

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    GLint success;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        std::cerr << "Shader program linking failed: " << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    this->shaderProgram = shaderProgram;
}

void Renderer3d::createMesh(float* vertices, size_t size, bool includeTexCoords) {
    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO); // Generate a Vertex Array Object
    glGenBuffers(1, &VBO);      // Generate a Vertex Buffer Object

    glBindVertexArray(VAO);     // Bind the VAO

    glBindBuffer(GL_ARRAY_BUFFER, VBO); // Bind the VBO
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW); // Upload vertex data

    // Position attribute: layout (location = 0)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
                          includeTexCoords ? 5 * sizeof(float) : 3 * sizeof(float),
                          (void*)0);
    glEnableVertexAttribArray(0);

    // Texture coordinate attribute: layout (location = 1)
    if (includeTexCoords) {
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE,
                              5 * sizeof(float),
                              (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
    }

    glBindBuffer(GL_ARRAY_BUFFER, 0); // Unbind the VBO
    glBindVertexArray(0);             // Unbind the VAO

    this->VAO = VAO; // Store the VAO handle for rendering
}


void Renderer3d::setClearColor(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
}

glm::mat4 Renderer3d::createProjectionMatrix(float fov, float aspectRatio, float near, float far) {
    return glm::perspective(glm::radians(fov), aspectRatio, near, far);
}

glm::mat4 Renderer3d::createViewMatrix(glm::vec3 cameraPosition, glm::vec3 cameraTarget, glm::vec3 upDirection) {
    return glm::lookAt(cameraPosition, cameraTarget, upDirection);
}

void Renderer3d::handleInput(SDL_Event &event) {
    const float cameraSpeed = 0.05f; // Adjust as needed

    if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_w) {
            cameraPosition.z -= cameraSpeed;
        }
        if (event.key.keysym.sym == SDLK_s) {
            cameraPosition.z += cameraSpeed;
        }
        if (event.key.keysym.sym == SDLK_a) {
            cameraPosition.x -= cameraSpeed;
        }
        if (event.key.keysym.sym == SDLK_d) {
            cameraPosition.x += cameraSpeed;
        }
    }
}

void Renderer3d::setUniformMat4(GLuint program, const char* name, glm::mat4 matrix) {
    GLint location = glGetUniformLocation(program, name);
    if (location == -1) {
        std::cerr << "Uniform not found: " << name << std::endl;
    }
    glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]);
}

void Renderer3d::setLightUniforms(GLuint program, Light &light) {
    GLint posLoc = glGetUniformLocation(program, "light.position");
    GLint colorLoc = glGetUniformLocation(program, "light.color");

    glUniform3fv(posLoc, 1, &light.position[0]);
    glUniform3fv(colorLoc, 1, &light.color[0]);
}

Renderer3d::~Renderer3d()
{
    // Delete OpenGL context
    SDL_GL_DeleteContext(context);
}
