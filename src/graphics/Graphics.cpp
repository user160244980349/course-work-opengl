//
// Created by user on 20.10.2017.
//

#include <SDL.h>
#include "graphics/Graphics.h"
#include <iostream>
#include <graphics/OpenGl.h>

application::graphics::Graphics::Graphics() {

    _fps = 60;
    _width = 3840;
    _height = 2160;

    if ( SDL_Init(SDL_INIT_VIDEO) != 0 ){
        std::cout << "Unable to init SDL, error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    _window = SDL_CreateWindow(
            "OpenGL",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            _width,
            _height,
            SDL_WINDOW_OPENGL |
            SDL_WINDOW_FULLSCREEN_DESKTOP |
            SDL_WINDOW_SHOWN
    );

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 8);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 16);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

    if(_window == nullptr){
        std::cout << "Unable to create window, error: " << SDL_GetError() << std::endl;
        exit(5);
    }

    SDL_GLContext glcontext = SDL_GL_CreateContext(_window);

    if(glcontext == nullptr){
        std::cout << "Unable to create OpenGL context, error: " << SDL_GetError() << std::endl;
        exit(6);
    }

    SDL_GL_SetSwapInterval(1);

    OpenGl::getInstance()->enable(GL_CULL_FACE);
    OpenGl::getInstance()->enable(GL_DEPTH_TEST);
    OpenGl::getInstance()->enable(GL_MULTISAMPLE);

    SDL_SetRelativeMouseMode(SDL_TRUE);
    SDL_ShowCursor(SDL_DISABLE);
}

application::graphics::Graphics::~Graphics() {

    delete(OpenGl::getInstance());
    SDL_GL_DeleteContext(_glContext);
    SDL_DestroyWindow(_window);
    SDL_Quit();

}

int application::graphics::Graphics::prepare(objects::IScene* scene) {

    scene->prepare();

    return 0;
}

int application::graphics::Graphics::draw(objects::IScene* scene) {

    static Uint32 start;
    Uint32 duration;

    OpenGl::getInstance()->clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    scene->draw();
    SDL_GL_SwapWindow(_window);

    duration = SDL_GetTicks() - start;

    if (duration <= 1000 / _fps)
        SDL_Delay(1000 / _fps - duration);

    start = SDL_GetTicks();

    return 0;
}
