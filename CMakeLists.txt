cmake_minimum_required(VERSION 3.8)

project(OpenGL)

set(CMAKE_CXX_STANDARD 17)

# sources
set(SOURCE_FILES
        src/main.cpp

        src/application/application.cpp
        src/include/application.hpp

        src/application/shader.cpp
        src/include/shader.hpp

        src/application/timer.cpp
        src/include/timer.hpp

        src/objects/base_object.cpp
        src/include/base_object.hpp

        src/include/vertex.hpp

        src/application/vao_vbo.cpp
        src/include/vao_vbo.hpp

        src/objects/triangles.cpp
        src/include/triangles.hpp src/objects/lines.cpp src/include/lines.hpp src/objects/isosceles_triangle.cpp src/include/isosceles_triangle.hpp src/objects/trapeze.cpp src/include/trapeze.hpp src/objects/nangle.cpp src/include/nangle.hpp src/objects/parallelogram.cpp src/include/parallelogram.hpp src/objects/rectangle.cpp src/include/rectangle.hpp src/objects/deltoid.cpp src/include/deltoid.hpp src/objects/rhombus.cpp src/include/rhombus.hpp src/objects/random_dots.cpp src/include/random_dots.hpp)

# executables
add_executable(OpenGL   ${SOURCE_FILES})

# CMake modules path
set(CMAKE_MODULE_PATH   ${CMAKE_MODULE_PATH} ${OpenGL_SOURCE_DIR}/cmake-modules)

# SDL paths
set(SDL2_PATH           ${OpenGL_SOURCE_DIR}/lib/SDL2-2.0.5/x86_64-w64-mingw32)

# include paths
set(GLEW_INCLUDE_DIR    ${OpenGL_SOURCE_DIR}/lib/glew-2.1.0/include)
set(GLM_INCLUDE_DIR     ${OpenGL_SOURCE_DIR}/lib/glm-0.9.8.5/glm)

# libraries binaries
set(GLEW_LIBRARY    ${OpenGL_SOURCE_DIR}/lib/glew-2.1.0/bin/Release/x64/glew32.dll)

# find section
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

#include directories
include_directories(
        src/include
        ${SDL2_INCLUDE_DIR}
        ${OPENGL_INCLUDE_DIRS}
        ${GLEW_INCLUDE_DIR}
        ${GLM_INCLUDE_DIR}
)

#link libraries
target_link_libraries(OpenGL
        ${SDL2_LIBRARY}
        ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARY}
)

