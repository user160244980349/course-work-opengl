cmake_minimum_required(VERSION 3.18)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_SOURCE_DIR}/cmake_modules/copy_resources.cmake)
set(CMAKE_MODULE_PATH  ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake_modules")

project(opengl)

file(GLOB_RECURSE INC "include/*.h")
file(GLOB_RECURSE SRC "sources/*.cpp")

add_executable(${PROJECT_NAME} ${INC} ${SRC})

if(WIN32)

    # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lmingw32 -mwindows")
    # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lmingw32 -mconsole")

    set(SDL2_PATH D:/Programs/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32)
    set(SDL2_TTF_PATH D:/Programs/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32)
    set(SDL2_IMAGE_PATH D:/Programs/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32)
    set(ASSIMP_PATH D:/Programs/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32)

    find_package(assimp REQUIRED)
    find_package(SDL2 REQUIRED)
    find_package(SDL2_image REQUIRED)
    find_package(SDL2_ttf REQUIRED)

else(WIN32)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(SDL2 REQUIRED sdl2)
    pkg_check_modules(SDL2IMAGE REQUIRED SDL2_image)
    pkg_check_modules(SDL2TTF REQUIRED SDL2_ttf)
    pkg_check_modules(assimp REQUIRED assimp)

endif(WIN32)

find_package(OpenGL REQUIRED)

target_include_directories(
    ${PROJECT_NAME} PUBLIC
    ${OPENGL_INCLUDE_DIRS}
    ${assimp_INCLUDE_DIRS}
    ${SDL2_INCLUDE_DIRS}
    ${SDL2IMAGE_INCLUDE_DIRS}
    ${SDL2TTF_INCLUDE_DIRS}
)

target_link_libraries(
    ${PROJECT_NAME}
    ${OPENGL_LIBRARIES}
    ${assimp_LIBRARIES}
    ${SDL2_LIBRARIES}
    ${SDL2TTF_LIBRARIES}
    ${SDL2IMAGE_LIBRARIES}
)

target_compile_options(${PROJECT_NAME} PUBLIC ${SDL2_CFLAGS_OTHER})

copy_resources(${CMAKE_SOURCE_DIR}/resources)
