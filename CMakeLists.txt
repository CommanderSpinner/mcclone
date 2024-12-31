cmake_minimum_required(VERSION 3.10)

# Set project name
project(mcclone)

# Enable C++11 or newer
set(CMAKE_CXX_STANDARD 11)

# Find the libraries using pkg-config
find_package(PkgConfig REQUIRED)

# Check for the SDL2, SDL2_mixer, SDL2_image, OpenGL, and Bullet libraries
pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_MIXER REQUIRED sdl2-mixer)
pkg_check_modules(SDL2_IMAGE REQUIRED sdl2-image)
pkg_check_modules(SDL2_TTF REQUIRED sdl2_ttf)
pkg_check_modules(SDL2_ REQUIRED sdl2-image)
pkg_check_modules(OPENGL REQUIRED opengl)
pkg_check_modules(BULLET REQUIRED bullet)

# Include the directories
include_directories(
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_MIXER_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
    ${SDL2_TTF_INCLUDE_DIRS}
    ${OPENGL_INCLUDE_DIRS}
    ${BULLET_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/includes
)

# Collect all .cpp and .c files in the src directory
file(GLOB_RECURSE SOURCES
    "src/*.cpp"
    "src/*.c"
    "src/imgui/imgui_impl_sdl2.cpp"
    "src/imgui/imgui_impl_opengl3.cpp"
    "src/imgui/imgui.cpp"
    "src/imgui/imgui_demo.cpp"
    "src/imgui/imgui_draw.cpp"
    "src/imgui/imgui_widgets.cpp"
)

# Add the executable and the source files
add_executable(mcclone ${SOURCES})

# Link the libraries
target_link_libraries(mcclone
    ${SDL2_LIBRARIES}
    ${SDL2_MIXER_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${BULLET_LIBRARIES}
)

# To include SDL2 in your runtime (optional), ensure the SDL2 binaries are found
link_directories(${SDL2_LIBRARY_DIRS})
