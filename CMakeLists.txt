cmake_minimum_required(VERSION 3.8)

project(OpenGL)

set(CMAKE_CXX_STANDARD 17)

# sources
set(SOURCE_FILES
        src/main.cpp

        src/application/application.cpp
        src/include/application/application.hpp

        src/application/shader.cpp
        src/include/application/shader.hpp

        src/application/timer.cpp
        src/include/application/timer.hpp

        src/objects/abstractions/abstract_object.cpp
        src/include/objects/abstractions/abstract_object.hpp

        src/application/abstractions/abstract_vao_vbo.cpp
        src/include/application/abstractions/abstract_vao_vbo.hpp

        src/objects/base_object.cpp
        src/include/objects/base_object.hpp

        src/application/base_vao_vbo.cpp
        src/include/application/base_vao_vbo.hpp

        src/include/application/buffers_combo.hpp
)

# executables
add_executable(OpenGL   ${SOURCE_FILES})

if (WIN32)

    # CMake modules path
    set(CMAKE_MODULE_PATH   ${CMAKE_MODULE_PATH} ${OpenGL_SOURCE_DIR}/cmake-modules)

    # SDL path
    set(SDL2_PATH           ${OpenGL_SOURCE_DIR}/lib/SDL2-2.0.5/x86_64-w64-mingw32)

    # include paths
    set(GLEW_INCLUDE_DIR    ${OpenGL_SOURCE_DIR}/lib/glew-2.1.0/include)
    set(GLM_INCLUDE_DIR     ${OpenGL_SOURCE_DIR}/lib/glm-0.9.8.5/)

    # libraries binaries
    set(GLEW_LIBRARY    ${OpenGL_SOURCE_DIR}/lib/glew-2.1.0/bin/Release/x64/glew32.dll)

    # find section
    find_package(SDL2 REQUIRED)
    find_package(OpenGL REQUIRED)
    find_package(GLM REQUIRED)

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
