//
// Created by user on 20.10.2017.
//

#include <SDL.h>
//#include <sdl_opengl.h>
//#include <GL/glew.h>
#include "glcorearb.h"
#include "graphics/Graphics.h"
#include <iostream>

application::graphics::Graphics::Graphics(GLuint width, GLuint height) {

    _fps = 59;
    _width = width;
    _height = height;

    if ( SDL_Init(SDL_INIT_VIDEO) != 0 ){
        std::cout << "Unable to init SDL, error: " << SDL_GetError() << std::endl;
        exit(1);
    }

//    const auto context_flags = SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG | (gl_debug ? SDL_GL_CONTEXT_DEBUG_FLAG : 0);

    SDL_ShowCursor(SDL_DISABLE);
    SDL_SetRelativeMouseMode(SDL_TRUE);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
    SDL_GL_SetSwapInterval(0);

    _window = SDL_CreateWindow(
            "OpenGL",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            _width,
            _height,
            SDL_WINDOW_OPENGL |
            SDL_WINDOW_FULLSCREEN_DESKTOP
    );

    if(_window == nullptr){
        std::cout << "Unable to create window, error: " << SDL_GetError() << std::endl;
        exit(5);
    }

    SDL_GLContext glcontext = SDL_GL_CreateContext(_window);

    if(glcontext == nullptr){
        std::cout << "Unable to create OpenGL context, error: " << SDL_GetError() << std::endl;
        exit(6);
    }



    if (SDL_GL_LoadLibrary(NULL) != 0) {
        std::cerr << "Error: " << SDL_GetError() << '\n';
        exit(5);
    }

    auto glEnable = (PFNGLENABLEPROC)SDL_GL_GetProcAddress("glEnable");
    auto glClipControl = (PFNGLCLIPCONTROLPROC)SDL_GL_GetProcAddress("glClipControl");
    auto glViewportIndexedf = (PFNGLVIEWPORTINDEXEDFPROC)SDL_GL_GetProcAddress("glViewportIndexedf");
    auto glClearNamedFramebufferfv = (PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)SDL_GL_GetProcAddress("glClearNamedFramebufferfv");
    auto glCreateBuffers = (PFNGLCREATEBUFFERSPROC)SDL_GL_GetProcAddress("glCreateBuffers");
    auto glNamedBufferData = (PFNGLNAMEDBUFFERDATAPROC)SDL_GL_GetProcAddress("glNamedBufferData");
    auto glCreateVertexArrays = (PFNGLCREATEVERTEXARRAYSPROC)SDL_GL_GetProcAddress("glCreateVertexArrays");
    auto glEnableVertexArrayAttrib = (PFNGLENABLEVERTEXARRAYATTRIBPROC)SDL_GL_GetProcAddress("glEnableVertexArrayAttrib");
    auto glVertexArrayAttribFormat = (PFNGLVERTEXARRAYATTRIBFORMATPROC)SDL_GL_GetProcAddress("glVertexArrayAttribFormat");
    auto glVertexArrayVertexBuffer = (PFNGLVERTEXARRAYVERTEXBUFFERPROC)SDL_GL_GetProcAddress("glVertexArrayVertexBuffer");
    auto glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)SDL_GL_GetProcAddress("glBindVertexArray");
//    auto glDrawArrays = (PFNGLDRAWARRAYSPROC)SDL_GL_GetProcAddress("glDrawArrays");

    SDL_GL_UnloadLibrary();

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_MULTISAMPLE);

//    glewInit();

}

application::graphics::Graphics::~Graphics() {

    SDL_DestroyWindow(_window);
    SDL_GL_DeleteContext(_glContext);
    SDL_Quit();

}

int application::graphics::Graphics::prepare(objects::IScene* scene) {

    scene->prepare();

    return 0;
}

int application::graphics::Graphics::draw(objects::IScene* scene) {

    static Uint32 start;
    Uint32 duration;

    if (SDL_GL_LoadLibrary(NULL) != 0) {
        std::cerr << "Error: " << SDL_GetError() << '\n';
        exit(5);
    }

    SDL_GL_UnloadLibrary();
    auto glClear = (PFNGLCLEARPROC)SDL_GL_GetProcAddress("glClear");

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    scene->draw();
    SDL_GL_SwapWindow(_window);

    duration = SDL_GetTicks() - start;

    if (duration <= 1000 / _fps)
        SDL_Delay(1000 / _fps - duration);

    start = SDL_GetTicks();

    return 0;
}
