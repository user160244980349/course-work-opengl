cmake_minimum_required(VERSION 3.9)
project(OpenGL)
set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lmingw32 -mwindows")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lmingw32 -mconsole")

set(SOURCES
        include/core/OpenGl.h
        include/core/Graphics.h
        include/core/BaseBuffer.h
        include/core/Ebo.h
        include/core/Vao.h
        include/core/Vbo.h
        include/core/ShaderTypes.h
        include/core/ShaderProgram.h
        include/core/UserInput.h
        include/objects/Cube.h
        include/objects/BaseObject.h
        include/objects/DynamicCamera.h
        include/objects/BaseScene.h
        include/objects/Scene.h
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
        include/core/Transform.h
        include/core/Mesh.h
        include/interfaces/ITransform.h
        include/interfaces/IMesh.h
        include/interfaces/IDrawable.h
        include/interfaces/ICommand.h
        include/interfaces/IInputCommand.h
        include/interfaces/IObject.h
        include/interfaces/IScene.h
        include/interfaces/ICamera.h
        include/interfaces/IControlable.h
        include/exceptions/ShaderProgramException.h
        include/exceptions/ShaderProgramCreationException.h
        include/exceptions/BaseException.h
        include/core/Kernel.h
        sources/main.cpp
        sources/OpenGl.cpp
        sources/Ebo.cpp
        sources/Graphics.cpp
        sources/Vao.cpp
        sources/Vbo.cpp
        sources/UserInput.cpp
        sources/Cube.cpp
        sources/DynamicCamera.cpp
        sources/BaseObject.cpp
        sources/BaseScene.cpp
        sources/Scene.cpp
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
        sources/Mesh.cpp
        sources/Transform.cpp
        sources/ShaderProgramException.cpp
        sources/ShaderProgramCreationException.cpp
        sources/BaseException.cpp
        include/core/ModelLoader.h
        sources/ModelLoader.cpp
        include/core/Model.h
        sources/Model.cpp
        include/core/Vertex.h)

add_executable(${PROJECT_NAME} ${SOURCES})

include_directories(
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/../x86_64-w64-mingw32/include)

find_package(OpenGL REQUIRED)

target_link_libraries(
        ${PROJECT_NAME}
        ${OPENGL_LIBRARIES}
        ${CMAKE_SOURCE_DIR}/../x86_64-w64-mingw32/lib/libSDL2main.a
        ${CMAKE_SOURCE_DIR}/../x86_64-w64-mingw32/lib/libSDL2.dll.a
        ${CMAKE_SOURCE_DIR}/../x86_64-w64-mingw32/lib/libSDL2_image.dll.a
        ${CMAKE_SOURCE_DIR}/../x86_64-w64-mingw32/lib/libassimp.dll.a)


