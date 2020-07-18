cmake_minimum_required(VERSION 3.18)

project(course_work_opengl)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH  ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake-scripts")

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lmingw32 -mwindows")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lmingw32 -mconsole")

file(GLOB_RECURSE HEADERS "include/*.h")
file(GLOB_RECURSE SOURCES "sources/*.cpp")

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)
# find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(OpenGL REQUIRED)
find_package(assimp REQUIRED)

target_include_directories(
    ${PROJECT_NAME} PUBLIC
    ${OPENGL_INCLUDE_DIRS}
    ${assimp_INCLUDE_DIRS}
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
    ${SDL2_TTF_INCLUDE_DIRS}
)

target_link_libraries(
    ${PROJECT_NAME}
    ${OPENGL_LIBRARIES}
    ${assimp_LIBRARIES}
    ${SDL2_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
)

target_compile_options(${PROJECT_NAME} PUBLIC ${SDL2_CFLAGS_OTHER})

# ${CMAKE_SOURCE_DIR}/../x86_64-w64-mingw32/lib/libSDL2main.a
# ${CMAKE_SOURCE_DIR}/../x86_64-w64-mingw32/lib/libSDL2.dll.a
# ${CMAKE_SOURCE_DIR}/../x86_64-w64-mingw32/lib/libSDL2_image.dll.a
# ${CMAKE_SOURCE_DIR}/../x86_64-w64-mingw32/lib/libassimp.dll.a)
