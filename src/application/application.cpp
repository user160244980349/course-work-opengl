//
// Created by user on 07.10.2017.
//

#include "application.hpp"
#include <iostream>
#include <GL/glew.h>
#include <application.hpp>


application::application::application() {

    init();
    prepare_shaders();
    flow();

}

application::application::~application() {

    SDL_DestroyWindow(sdl_variables.window);
    SDL_Quit();

}

int application::application::init() {

    if ( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0 ){
        std::cout << "Unable to init SDL, error: " << SDL_GetError() << std::endl;
        exit(1);
    }

   sdl_variables.window = SDL_CreateWindow("Cube", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_parameters.width, window_parameters.height, SDL_WINDOW_OPENGL);

    if(sdl_variables.window == nullptr){
        std::cout << "Unable to create window, error: " << SDL_GetError() << std::endl;
        exit(5);
    }

    SDL_GLContext glcontext = SDL_GL_CreateContext(sdl_variables.window);

    if(glcontext == nullptr){
        std::cout << "Unable to create OpenGL context, error: " << SDL_GetError() << std::endl;
        exit(6);
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 6);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//    glClearDepth(1.0);
//    glDepthFunc(GL_LESS);
//    glEnable(GL_DEPTH_TEST);
//    glShadeModel(GL_SMOOTH);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(45.0f, (float) window_parameters.width / (float) window_parameters.height, 0.1f, 100.0f);
//    glMatrixMode(GL_MODELVIEW);

    return 0;
}

int application::application::flow() {

    glClear(GL_COLOR_BUFFER_BIT);

    while(state_variables.running){

        SDL_PollEvent(&sdl_variables.event);
        switch(sdl_variables.event.type){
            case SDL_QUIT:
                state_variables.running = false;
                break;

            case SDL_KEYDOWN:
                switch(sdl_variables.event.key.keysym.sym){
                    case SDLK_q:
                        if (sdl_variables.last_key_pressed.type == SDL_KEYDOWN &&
                            sdl_variables.last_key_pressed.key.keysym.sym == SDLK_LCTRL)
                            state_variables.running = false;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
        sdl_variables.last_key_pressed = sdl_variables.event;

        draw();

        SDL_GL_SwapWindow(sdl_variables.window);
    }

    return 0;
}

int application::application::draw() {

    objects.p1.draw();

    return 0;
}

int application::application::prepare_shaders() {

    objects.p1.prepare_shaders();

    return 0;
}

