cmake_minimum_required(VERSION 3.8)

project(OpenGL)

set(CMAKE_CXX_STANDARD 17)

# sources
set(SOURCE_FILES
        src/main.cpp
        src/application/application.cpp
        src/include/application.hpp
        src/objects/cube.cpp
        src/include/cube.hpp)

# executables
add_executable(OpenGL   ${SOURCE_FILES})

# CMake modules path
set(CMAKE_MODULE_PATH   ${CMAKE_MODULE_PATH} ${OpenGL_SOURCE_DIR}/cmake-modules)

# SDL paths
set(SDL2_PATH           ${OpenGL_SOURCE_DIR}/lib/SDL2-2.0.5/x86_64-w64-mingw32)
set(SDL2_TTF_PATH       ${OpenGL_SOURCE_DIR}/lib/SDL2_ttf-2.0.14/x86_64-w64-mingw32)
set(SDL2_IMAGE_PATH     ${OpenGL_SOURCE_DIR}/lib/SDL2_image-2.0.1/x86_64-w64-mingw32)

# include paths
set(GLEW_INCLUDE_DIR    ${OpenGL_SOURCE_DIR}/lib/glew-2.1.0/include)
set(GLM_INCLUDE_DIR     ${OpenGL_SOURCE_DIR}/lib/glm-0.9.8.5/glm)

# libraries binaries
set(GLEW_LIBRARY    ${OpenGL_SOURCE_DIR}/lib/glew-2.1.0/bin/Release/x64/glew32.dll)

# find section
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_IMAGE REQUIRED)
find_package(OpenGL REQUIRED)

#include directories
include_directories(
        src/include
        ${SDL2_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${OPENGL_INCLUDE_DIRS}
        ${GLEW_INCLUDE_DIR}
        ${GLM_INCLUDE_DIR}
)

#link libraries
target_link_libraries(OpenGL
        ${SDL2_LIBRARY}
        ${SDL2_TTF_LIBRARY}
        ${SDL2_IMAGE_LIBRARY}
        ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARY}
)

