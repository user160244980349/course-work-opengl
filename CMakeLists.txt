cmake_minimum_required(VERSION 3.8)

project(OpenGL)

set(CMAKE_CXX_STANDARD 17)

# sources
set(SOURCES

        # HEADERS
        include/glcorearb.h

        include/graphics/UboBindIndexes.h
        include/graphics/OpenGl.h
        include/graphics/Graphics.h
        include/graphics/ABuffer.h
        include/graphics/Ebo.h
        include/graphics/Shader.h
        include/graphics/Scene.h
        include/graphics/Ubo.h
        include/graphics/Vao.h
        include/graphics/Vbo.h
        include/graphics/Vertex3d.h
        include/graphics/IOutput.h

        include/interfaces/IScene.h
        include/interfaces/IInput.h
        include/interfaces/ICamera.h
        include/interfaces/IControlable.h
        include/interfaces/IDrawable.h
        include/interfaces/IObject.h

        include/input/ClientInput.h

        include/objects/Cube.h
        include/objects/AObject.h
        include/objects/DynamicCamera.h

        include/Kernel.h

        # SOURCES
        src/main.cpp

        src/graphics/OpenGl.cpp
        src/graphics/Ebo.cpp
        src/graphics/Graphics.cpp
        src/objects/Scene.cpp
        src/graphics/Shader.cpp
        src/graphics/Ubo.cpp
        src/graphics/Vao.cpp
        src/graphics/Vbo.cpp

        src/input/ClientInput.cpp

        src/objects/Cube.cpp
        src/objects/DynamicCamera.cpp
        src/objects/AObject.cpp

        src/Kernel.cpp
        )

# executables
add_executable(OpenGL ${SOURCES})

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../cmake-modules)

# find section
find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED)
find_package(SDL2_TTF REQUIRED)
find_package(OpenGL REQUIRED)

# include directories
include_directories(
        include
)

# link libraries
target_link_libraries(OpenGL
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
        ${OPENGL_LIBRARIES}
)

