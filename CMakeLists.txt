cmake_minimum_required(VERSION 3.9)
project(opengl CXX)
set(CMAKE_CXX_STANDARD 17)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lmingw32 -mwindows")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lmingw32 -mconsole")

file(GLOB_RECURSE HEADERS "include/*.h")
file(GLOB_RECURSE SOURCES "source/*.cpp")

message(${HEADERS} ${SOURCES})

# include_directories(${CMAKE_SOURCE_DIR}/../x86_64-w64-mingw32/include)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

# find_package(OpenGL REQUIRED)
# find_package(Assimp REQUIRED)
# find_package(SDL2 REQUIRED)

target_link_libraries(${PROJECT_NAME})
    # ${OPENGL_LIBRARIES})
    # ${CMAKE_SOURCE_DIR}/../x86_64-w64-mingw32/lib/libSDL2main.a
    # ${CMAKE_SOURCE_DIR}/../x86_64-w64-mingw32/lib/libSDL2.dll.a
    # ${CMAKE_SOURCE_DIR}/../x86_64-w64-mingw32/lib/libSDL2_image.dll.a
    # ${CMAKE_SOURCE_DIR}/../x86_64-w64-mingw32/lib/libassimp.dll.a)
