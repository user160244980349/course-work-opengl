cmake_minimum_required(VERSION 3.9)
project(OpenGL)
set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lmingw32 -mwindows")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lmingw32 -mconsole")

# cmake modules path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake-modules)

# compiler path
set(COMPILER_PATH "D:/Program\ Files/mingw-w64/x86_64-7.2.0-posix-seh-rt_v5-rev1/mingw64/x86_64-w64-mingw32")

# sources
set(SOURCES

        # HEADERS
        include/graphics/UboBindIndexes.h
        include/graphics/OpenGl.h
        include/graphics/Graphics.h
        include/graphics/ABuffer.h
        include/graphics/Ebo.h
        include/graphics/Shader.h
        include/objects/Scene.h
        include/graphics/Ubo.h
        include/graphics/Vao.h
        include/graphics/Vbo.h
        include/graphics/Vertex3d.h
        include/graphics/IDrawable.h

        include/input/IControlable.h
        include/input/ClientInput.h

        include/objects/IObject.h
        include/objects/ICamera.h
        include/objects/Cube.h
        include/objects/AObject.h
        include/objects/DynamicCamera.h

        include/commands/MoveLeft.h
        include/commands/MoveRight.h
        include/commands/MoveBack.h
        include/commands/MoveForward.h
        include/commands/LookHorizontal.h
        include/commands/LookVertical.h
        include/commands/IInputCommand.h
        include/commands/QuitCommand.h
        include/commands/ICommand.h
        include/commands/AInputCommand.h

        include/Kernel.h

        # SOURCES
        source/main.cpp

        source/graphics/OpenGl.cpp
        source/graphics/Ebo.cpp
        source/graphics/Graphics.cpp
        source/objects/Scene.cpp
        source/graphics/Shader.cpp
        source/graphics/Ubo.cpp
        source/graphics/Vao.cpp
        source/graphics/Vbo.cpp

        source/input/ClientInput.cpp

        source/objects/Cube.cpp
        source/objects/DynamicCamera.cpp
        source/objects/AObject.cpp

        source/commands/QuitCommand.cpp
        source/commands/LookVertical.cpp
        source/commands/LookHorizontal.cpp
        source/commands/MoveForward.cpp
        source/commands/MoveBack.cpp
        source/commands/MoveRight.cpp
        source/commands/MoveLeft.cpp
        source/commands/AInputCommand.cpp

        source/Kernel.cpp
)

# executables
add_executable(OpenGL ${SOURCES})

# SDL2 paths
set(SDL2_PATH ${COMPILER_PATH})
set(SDL2_TTF_PATH ${COMPILER_PATH})
set(SDL2_IMAGE_PATH ${COMPILER_PATH})

# include directories
include_directories(
        include
)

# find section
find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED)
find_package(SDL2_TTF REQUIRED)
find_package(OpenGL REQUIRED)

# link libraries
target_link_libraries(
        OpenGL
        ${SDL2_LIBRARY}
        ${SDL2_TTF_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES}
        ${OPENGL_LIBRARIES}
)


