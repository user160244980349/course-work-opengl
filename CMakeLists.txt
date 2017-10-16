cmake_minimum_required(VERSION 3.8)

project(OpenGL)

set(CMAKE_CXX_STANDARD 17)

# headers
set(HEADERS
        src/include/kernel.hpp
        src/include/graphics/vertex_3d.hpp
        src/include/graphics/shader.hpp
        src/include/graphics/vao.hpp
        src/include/graphics/vbo.hpp
        src/include/graphics/ebo.hpp
        src/include/graphics/ubo.hpp
        src/include/graphics/abstract_buffer.hpp
        src/include/time/abstract_timer.hpp
        src/include/time/interval_timer.hpp
        src/include/time/timer.hpp
        src/include/objects/abstract_object.hpp
        src/include/objects/base_object.hpp
        src/include/objects/drawable.hpp
        src/include/objects/bicameral_hyperboloid.hpp
        src/include/environment.hpp)

# sources
set(SOURCES
        src/main.cpp
        src/application/kernel.cpp
        src/application/environment.cpp
        src/graphics/shader.cpp
        src/graphics/vao.cpp
        src/graphics/vbo.cpp
        src/graphics/ebo.cpp
        src/graphics/ubo.cpp
        src/time/abstract_timer.cpp
        src/time/interval_timer.cpp
        src/time/timer.cpp
        src/objects/base_object.cpp
        src/objects/bicameral_hyperboloid.cpp
        src/objects/one_sheet_hyperboloid.cpp)

# executables
add_executable(OpenGL   ${HEADERS} ${SOURCES})

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
            src/include
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
            src/include
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
