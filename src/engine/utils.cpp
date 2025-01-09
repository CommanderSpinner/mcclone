#include "engine/utils.hpp"

std::string utils::getFileContents(std::string fileName){
    std::ifstream file(fileName);

    if (!file) {
        std::cerr << "Error: Unable to open file " << fileName << std::endl;
    }

    std::stringstream buffer;
    buffer << file.rdbuf(); // Read the file into the buffer

    std::string fileContents = buffer.str(); // Get the contents as a string

    file.close();

    return fileContents;
}

std::string utils::getShaderCode(std::string fileName){
    return utils::getFileContents(prefixes::shaderD + fileName);
}

void utils::print_OGL_error()
{
	GLenum err;
    while ((err = glGetError()) != GL_NO_ERROR) {
        switch (err) {
            case GL_INVALID_ENUM:
                std::cerr << "OpenGL Error: GL_INVALID_ENUM" << std::endl;
                break;
            case GL_INVALID_VALUE:
                std::cerr << "OpenGL Error: GL_INVALID_VALUE" << std::endl;
                break;
            case GL_INVALID_OPERATION:
                std::cerr << "OpenGL Error: GL_INVALID_OPERATION" << std::endl;
                break;
            case GL_STACK_OVERFLOW:
                std::cerr << "OpenGL Error: GL_STACK_OVERFLOW" << std::endl;
                break;
            case GL_STACK_UNDERFLOW:
                std::cerr << "OpenGL Error: GL_STACK_UNDERFLOW" << std::endl;
                break;
            case GL_OUT_OF_MEMORY:
                std::cerr << "OpenGL Error: GL_OUT_OF_MEMORY" << std::endl;
                break;
            case GL_INVALID_FRAMEBUFFER_OPERATION:
                std::cerr << "OpenGL Error: GL_INVALID_FRAMEBUFFER_OPERATION" << std::endl;
                break;
            default:
                std::cerr << "OpenGL Error: Unknown error code " << err << std::endl;
                break;
        }
    }
}
