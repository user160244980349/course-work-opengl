cmake_minimum_required(VERSION 3.8)

project(OpenGL)

set(CMAKE_CXX_STANDARD 17)

# sources
set(SOURCES

        # HEADERS
        include/graphics/UboBindIndexes.h

        include/graphics/Graphics.h
        include/graphics/AbstractBuffer.h
        include/graphics/Ebo.h
        include/graphics/Shader.h
        include/graphics/Scene.h
        include/graphics/Ubo.h
        include/graphics/Vao.h
        include/graphics/Vbo.h
        include/graphics/Vertex3d.h

        include/interfaces/IInput.h
        include/interfaces/IScene.h
        include/interfaces/ICamera.h
        include/interfaces/IControlable.h
        include/interfaces/IDrawable.h
        include/interfaces/IDynamicCamera.h
        include/interfaces/IObject.h

        include/input/ClientInput.h
        include/input/KeyLogger.h

        include/objects/Cube.h
        include/objects/DynamicCamera.h

        include/Kernel.h

        # SOURCES
        src/graphics/Ebo.cpp
        src/graphics/Graphics.cpp
        src/graphics/Scene.cpp
        src/graphics/Shader.cpp
        src/graphics/Ubo.cpp
        src/graphics/Vao.cpp
        src/graphics/Vbo.cpp

        src/input/ClientInput.cpp
        src/input/KeyLogger.cpp

        src/objects/Cube.cpp
        src/objects/DynamicCamera.cpp

        src/Kernel.cpp
        src/main.cpp)

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
