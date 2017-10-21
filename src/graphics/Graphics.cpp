//
// Created by user on 20.10.2017.
//

#include <SDL.h>
#include <iostream>
#include <GL/glew.h>
#include "graphics/Graphics.h"

application::graphics::Graphics::Graphics(Uint32 width, Uint32 height) {

    _width = width;
    _height = height;

    if ( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0 ){
        std::cout << "Unable to init SDL, error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    SDL_ShowCursor(SDL_DISABLE); // показ курсора
    SDL_SetRelativeMouseMode(SDL_TRUE); // захват курсора в окне

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

    _window = SDL_CreateWindow(
            "OpenGL",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            _width,
            _height,
            SDL_WINDOW_OPENGL //|
//            SDL_WINDOW_FULLSCREEN
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

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_MULTISAMPLE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable(GL_POINT_SMOOTH);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

    glewInit();
}

application::graphics::Graphics::~Graphics() {

    SDL_DestroyWindow(_window);
    SDL_Quit();

}

int application::graphics::Graphics::swapWindow() {

    SDL_GL_SwapWindow(_window);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    return 0;
}
