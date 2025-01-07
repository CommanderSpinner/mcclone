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
