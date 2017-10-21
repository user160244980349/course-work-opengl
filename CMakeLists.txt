cmake_minimum_required(VERSION 3.8)

project(OpenGL)

set(CMAKE_CXX_STANDARD 17)

# sources
aux_source_directory(${OpenGL_SOURCE_DIR} SUB_SOURCES)

# executables
set(OpenGL ${SOURCES})

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
