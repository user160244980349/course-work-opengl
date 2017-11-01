//
// Created by user on 20.10.2017.
//

#include <SDL2/SDL.h>
#include "graphics/Graphics.h"
#include <iostream>
#include <graphics/OpenGl.h>

application::graphics::Graphics::Graphics() {

    _fps = 59;
    _width = 1920;
    _height = 1080;

    if ( SDL_Init(SDL_INIT_VIDEO) != 0 ) {
        std::cout << "Unable to init SDL, error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 16);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

    _window = SDL_CreateWindow(
            "OpenGL",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            _width,
            _height,
            SDL_WINDOW_OPENGL
            | SDL_WINDOW_ALLOW_HIGHDPI
//            | SDL_WINDOW_FULLSCREEN
//            | SDL_WINDOW_FULLSCREEN_DESKTOP
    );

    if(_window == nullptr) {
        std::cout << "Unable to create window, error: " << SDL_GetError() << std::endl;
        exit(5);
    }

    _glContext = SDL_GL_CreateContext(_window);

    if(_glContext == nullptr) {
        std::cout << "Unable to create OpenGL context, error: " << SDL_GetError() << std::endl;
        exit(6);
    }

    SDL_GL_SetSwapInterval(1);

    OpenGl::getInstance()->enable(GL_CULL_FACE);
    OpenGl::getInstance()->enable(GL_DEPTH_TEST);
    OpenGl::getInstance()->enable(GL_MULTISAMPLE);
    OpenGl::getInstance()->clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    OpenGl::getInstance()->clearColor(0.0f, 0.0f, 0.0f, 1.0f);
    OpenGl::getInstance()->finish();
}

application::graphics::Graphics::~Graphics() {

    delete(OpenGl::getInstance());
    SDL_GL_DeleteContext(_glContext);
    SDL_DestroyWindow(_window);
    SDL_Quit();

}

int application::graphics::Graphics::prepare(interfaces::IScene* scene) {

    scene->prepare();

    return 0;
}

int application::graphics::Graphics::draw(interfaces::IScene* scene) {

    static Uint32 start;
    Uint32 duration;

    OpenGl::getInstance()->clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    scene->update();
    scene->draw();
    OpenGl::getInstance()->finish();
//    OpenGl::getInstance()->flush(); ?
    SDL_GL_SwapWindow(_window);

    duration = SDL_GetTicks() - start;

    if (duration <= 1000 / _fps)
        SDL_Delay(1000 / _fps - duration);

    start = SDL_GetTicks();

    return 0;
}
