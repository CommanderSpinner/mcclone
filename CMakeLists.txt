cmake_minimum_required(VERSION 3.10)

# Set project name
project(mcclone)

# Enable C++11 or newer
set(CMAKE_CXX_STANDARD 11)

# Find the pkg-config package
find_package(PkgConfig REQUIRED)

# Check for SDL2 using pkg-config (main library only)
pkg_check_modules(SDL2 REQUIRED sdl2)

# Find other SDL2-related libraries via their respective find modules
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Bullet REQUIRED)

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
file(GLOB SOURCES
    "src/*.cpp"
    "src/*.c"
    "src/imgui/imgui_impl_sdl2.cpp"
    "src/imgui/imgui_impl_opengl3.cpp"
    "src/imgui/imgui.cpp"
    #"src/imgui/imgui_demo.cpp"
    "src/imgui/imgui_tables.cpp"
    "src/imgui/imgui_draw.cpp"
    "src/imgui/imgui_widgets.cpp"
)

# Add the executable and the source files
add_executable(mcclone ${SOURCES})

# Link the libraries
target_link_libraries(mcclone
    ${SDL2_LIBRARIES}             # Link the main SDL2 library from pkg-config
    ${SDL2_MIXER_LIBRARIES}       # Link SDL2_mixer (found via CMake find_package)
    ${SDL2_IMAGE_LIBRARIES}       # Link SDL2_image (found via CMake find_package)
    ${SDL2_TTF_LIBRARIES}         # Link SDL2_ttf (found via CMake find_package)
    ${OPENGL_LIBRARIES}           # Link OpenGL
    ${BULLET_LIBRARIES}           # Link Bullet physics library
)

# To include SDL2 in your runtime (optional), ensure the SDL2 binaries are found
link_directories(${SDL2_LIBRARY_DIRS})

file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})
