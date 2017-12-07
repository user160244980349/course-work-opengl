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
        include/graphics/OpenGl.h
        include/graphics/Graphics.h
        include/graphics/BaseBuffer.h
        include/graphics/Ebo.h
        include/objects/Scene.h
        include/graphics/Vao.h
        include/graphics/Vbo.h
        include/interfaces/IDrawable.h

        include/interfaces/IControlable.h
        include/input/UserInput.h

        include/interfaces/IObject.h
        include/interfaces/ICamera.h
        include/objects/Cube.h
        include/objects/BaseObject.h
        include/objects/DynamicCamera.h

        include/commands/MoveLeft.h
        include/commands/MoveRight.h
        include/commands/MoveBack.h
        include/commands/MoveForward.h
        include/commands/LookHorizontal.h
        include/commands/LookVertical.h
        include/interfaces/IInputCommand.h
        include/commands/QuitCommand.h
        include/interfaces/ICommand.h
        include/commands/BaseInputCommand.h

        include/Kernel.h

        # SOURCES
        source/main.cpp

        source/graphics/OpenGl.cpp
        source/graphics/Ebo.cpp
        source/graphics/Graphics.cpp
        source/objects/Scene.cpp
        source/graphics/Vao.cpp
        source/graphics/Vbo.cpp

        source/input/UserInput.cpp

        source/objects/Cube.cpp
        source/objects/DynamicCamera.cpp
        source/objects/BaseObject.cpp

        source/commands/QuitCommand.cpp
        source/commands/LookVertical.cpp
        source/commands/LookHorizontal.cpp
        source/commands/MoveForward.cpp
        source/commands/MoveBack.cpp
        source/commands/MoveRight.cpp
        source/commands/MoveLeft.cpp
        source/commands/BaseInputCommand.cpp

        source/Kernel.cpp
        source/commands/MoveUp.cpp
        include/commands/MoveUp.h
        source/commands/MoveDown.cpp
        include/commands/MoveDown.h
        source/graphics/ShaderProgram.cpp
        include/graphics/ShaderTypes.h
        include/graphics/ShaderProgram.h
        source/commands/Accelerate.cpp
        include/commands/Accelerate.h source/graphics/BaseBuffer.cpp include/interfaces/ITransform.h include/interfaces/IMesh.h source/components/CubeMesh.cpp include/components/CubeMesh.h source/components/Transform.cpp include/components/Transform.h)

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


