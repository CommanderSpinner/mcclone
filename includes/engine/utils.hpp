#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

namespace prefixes{
    const std::string assetsD = "assets/";
    const std::string gfxD = assetsD + "gfx/";
    const std::string shaderD = assetsD + "shaders/";
    const std::string soundD = assetsD + "sound/";
}

namespace utils{
    std::string getFileContents(std::string fileName);
    std::string getShaderCode(std::string fileName);
	void print_OGL_error();
}

#endif
