cmake_minimum_required(VERSION 3.9)
project(OpenGL)
set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lmingw32 -mwindows")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lmingw32 -mconsole")

# cmake modules path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake-modules)

# compiler path
set(COMPILER_PATH "D:/Program\ Files/mingw-w64/x86_64-7.2.0-posix-seh-rt_v5-rev1/mingw64/x86_64-w64-mingw32")

set(SOURCES
        # graphics
        include/graphics/OpenGl.h
        include/graphics/Graphics.h
        include/graphics/BaseBuffer.h
        include/graphics/Ebo.h
        include/graphics/Vao.h
        include/graphics/Vbo.h
        include/graphics/ShaderTypes.h
        include/graphics/ShaderProgram.h
        # input
        include/input/UserInput.h
        # objects
        include/objects/Cube.h
        include/objects/BaseObject.h
        include/objects/DynamicCamera.h
        include/objects/Scene.h
        # commands
        include/commands/MoveLeft.h
        include/commands/MoveRight.h
        include/commands/MoveBack.h
        include/commands/MoveForward.h
        include/commands/LookHorizontal.h
        include/commands/LookVertical.h
        include/commands/QuitCommand.h
        include/commands/BaseInputCommand.h
        include/commands/MoveUp.h
        include/commands/MoveDown.h
        include/commands/Accelerate.h
        # components
        include/components/Transform.h
        include/components/CubeMesh.h
        # interfaces
        include/interfaces/ITransform.h
        include/interfaces/IMesh.h
        include/interfaces/IDrawable.h
        include/interfaces/ICommand.h
        include/interfaces/IInputCommand.h
        include/interfaces/IObject.h
        include/interfaces/ICamera.h
        include/interfaces/IControlable.h

        include/Kernel.h
        # sources
        sources/main.cpp
        sources/OpenGl.cpp
        sources/Ebo.cpp
        sources/Graphics.cpp
        sources/Scene.cpp
        sources/Vao.cpp
        sources/Vbo.cpp
        sources/UserInput.cpp
        sources/Cube.cpp
        sources/DynamicCamera.cpp
        sources/BaseObject.cpp
        sources/QuitCommand.cpp
        sources/LookVertical.cpp
        sources/LookHorizontal.cpp
        sources/MoveForward.cpp
        sources/MoveBack.cpp
        sources/MoveRight.cpp
        sources/MoveLeft.cpp
        sources/BaseInputCommand.cpp
        sources/Kernel.cpp
        sources/MoveUp.cpp
        sources/MoveDown.cpp
        sources/ShaderProgram.cpp
        sources/Accelerate.cpp
        sources/BaseBuffer.cpp
        sources/CubeMesh.cpp
        sources/Transform.cpp
        sources/ShaderProgramException.cpp include/exceptions/ShaderProgramException.h sources/ShaderProgramCreationException.cpp include/exceptions/ShaderProgramCreationException.h sources/BaseException.cpp include/exceptions/BaseException.h)

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


