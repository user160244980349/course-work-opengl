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
        include/objects/abstract_object.h
        include/objects/drawable.h
        include/time/abstract_timer.h
        include/time/interval_timer.h
        include/time/timer.h
        include/objects/base_object.h
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
        src/objects/base_object.cpp

        include/test/InputInterface.h
        src/test/Subject.cpp
        include/test/Subject.h
        include/test/ObserverInterface.h
        src/test/ClientInput.cpp
        include/test/ClientInput.h
        src/test/KeyLogger.cpp
        include/test/KeyLogger.h
        include/test/AbstractScene.h
        src/test/Scene.cpp
        include/test/Scene.h
        src/test/Graphics.cpp
        include/test/Graphics.h
        include/test/ClientInputInterface.h include/test/DrawableInterface.h src/test/Cube.cpp include/test/Cube.h include/test/AbstractObject.h include/test/AbstractCamera.h src/test/Camera.cpp include/test/Camera.h)

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
