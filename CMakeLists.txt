cmake_minimum_required(VERSION 3.8)

project(OpenGL)

set(CMAKE_CXX_STANDARD 17)


# sources
set(SOURCES

        include/Kernel.h
        include/graphics/shader.h
        include/graphics/vao.h
        include/graphics/vbo.h
        include/graphics/ebo.h
        include/graphics/ubo.h
        include/graphics/abstract_buffer.h
        include/time/abstract_timer.h
        include/time/interval_timer.h
        include/time/timer.h
        include/graphics/vertex_3d.h

        src/main.cpp
        src/Kernel.cpp
        src/graphics/shader.cpp
        src/graphics/vao.cpp
        src/graphics/vbo.cpp
        src/graphics/ebo.cpp
        src/graphics/ubo.cpp
        src/time/interval_timer.cpp
        src/time/timer.cpp

        include/Interfaces&Abstractions/InputInterface.h
        src/abstractions/Subject.cpp
        include/Interfaces&Abstractions/Subject.h
        include/Interfaces&Abstractions/ObserverInterface.h
        src/input/ClientInput.cpp
        include/input/ClientInput.h
        src/input/KeyLogger.cpp
        include/input/KeyLogger.h
        include/Interfaces&Abstractions/AbstractScene.h
        src/graphics/Scene.cpp
        include/graphics/Scene.h
        src/graphics/Graphics.cpp
        include/graphics/Graphics.h
        include/Interfaces&Abstractions/ClientInputInterface.h
        include/Interfaces&Abstractions/DrawableInterface.h
        src/objects/Cube.cpp
        include/objects/Cube.h
        include/Interfaces&Abstractions/AbstractObject.h
        include/Interfaces&Abstractions/AbstractCamera.h
        include/Interfaces&Abstractions/ControlableInterface.h
        include/Interfaces&Abstractions/DynamicCameraInterface.h
        src/objects/DynamicCamera.cpp
        include/objects/DynamicCamera.h)

# executables
add_executable(OpenGL ${SOURCES})

if (WIN32)

    # CMake modules path
    set(CMAKE_MODULE_PATH   ${CMAKE_MODULE_PATH} ${OpenGL_SOURCE_DIR}/../cmake-modules)

    # SDL path
    set(SDL2_PATH           ${OpenGL_SOURCE_DIR}/../lib/SDL2-2.0.6/x86_64-w64-mingw32)

    # include paths
    set(GLEW_INCLUDE_DIR    ${OpenGL_SOURCE_DIR}/../lib/glew-2.1.0/include)
    set(GLM_INCLUDE_DIR     ${OpenGL_SOURCE_DIR}/../lib/glm-0.9.8.5/)

    # libraries binaries
    set(GLEW_LIBRARY    ${OpenGL_SOURCE_DIR}/../lib/glew-2.1.0/bin/Release/x64/glew32.dll)

    # find section
    find_package(SDL2 REQUIRED)
    find_package(OpenGL REQUIRED)

    # include directories
    include_directories(
            include
            ${SDL2_INCLUDE_DIR}
            ${OPENGL_INCLUDE_DIRS}
            ${GLEW_INCLUDE_DIR}
            ${GLM_INCLUDE_DIR}
    )

    # link libraries
    target_link_libraries(OpenGL
            ${SDL2_LIBRARY}
            ${OPENGL_LIBRARIES}
            ${GLEW_LIBRARY}
    )

elseif(UNIX)

    set(CMAKE_CXX_FLAGS  -lpthread)

    # find section
    find_package(SDL2 REQUIRED)
    find_package(OpenGL REQUIRED)
    find_package(GLEW REQUIRED)

    # include directories
    include_directories(
            include
            ${SDL2_INCLUDE_DIR}
            ${OPENGL_INCLUDE_DIRS}
            ${GLEW_INCLUDE_DIR}
            ${GLM_INCLUDE_DIR}
    )

    # link libraries
    target_link_libraries(OpenGL
            ${SDL2_LIBRARIES}
            ${OPENGL_LIBRARIES}
            ${GLEW_LIBRARY}
    )

endif()
