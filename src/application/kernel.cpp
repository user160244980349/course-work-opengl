//
// Created by user on 07.10.2017.
//

#include <iostream>
#include <GL/glew.h>
#include <kernel.hpp>
#include <global_variables.hpp>
#include "time/timer.hpp"
#include "time/interval_timer.hpp"
#include "objects/base_object.hpp"
#include "objects/one_sheet_hyperboloid.hpp"
#include "objects/bicameral_hyperboloid.hpp"


application::kernel::kernel(int width, int height) {

    _window_parameters.width = width;
    _window_parameters.height = height;
    _init();
    _prepare_objects();
    _flow();

}



application::kernel::~kernel() {

    SDL_DestroyWindow(_sdl_variables.window);
    SDL_Quit();

}



int application::kernel::_init() {

    if ( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0 ){
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
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

   _sdl_variables.window = SDL_CreateWindow(
           "OpenGL",
           SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
           _window_parameters.width,
           _window_parameters.height,
           SDL_WINDOW_OPENGL |
           SDL_WINDOW_FULLSCREEN
   );

    if(_sdl_variables.window == nullptr){
        std::cout << "Unable to create window, error: " << SDL_GetError() << std::endl;
        exit(5);
    }

    SDL_GLContext glcontext = SDL_GL_CreateContext(_sdl_variables.window);

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

    return 0;
}



int application::kernel::_flow() {

    time::world_time.run();
    time::frame_update.set(0.015);
    time::frame_update.run();

    while(_state_variables.running){

        _key_caption();

        if (time::frame_update.fired) {
            time::frame_update.reset();
            _draw();
            SDL_GL_SwapWindow(_sdl_variables.window);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }
    }

    return 0;
}



int application::kernel::_draw() {

    if (_state_variables.warframe == GL_TRUE)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    switch(_state_variables.n) {
        case 0:
            scene::base_object.draw();
            break;
        case 1:
            scene::one_sheet_hyperboloid.draw();
            break;
        case 2:
            scene::bicameral_hyperboloid.draw();
            break;

    }

    return 0;
}



int application::kernel::_prepare_objects() {

    scene::base_object.prepare();
    scene::one_sheet_hyperboloid.prepare();
    scene::bicameral_hyperboloid.prepare();

    return 0;
}



int application::kernel::_key_caption() {

    while(SDL_PollEvent(&_sdl_variables.event)) {
        switch (_sdl_variables.event.type) {
            case SDL_QUIT:
                _state_variables.running = false;
                break;

            case SDL_KEYDOWN:
                switch (_sdl_variables.event.key.keysym.sym) {
                    case SDLK_q:
                        if (_sdl_variables.last_key_pressed.type == SDL_KEYDOWN &&
                            _sdl_variables.last_key_pressed.key.keysym.sym == SDLK_LCTRL)
                            _state_variables.running = false;
                        break;
                    case SDLK_w:
                        time::world_time.stop();
                        break;
                    case SDLK_e:
                        time::world_time.run();
                        break;
                    case SDLK_r:
                        if (_state_variables.warframe == GL_TRUE)
                            _state_variables.warframe = GL_FALSE;
                        else
                            _state_variables.warframe = GL_TRUE;
                        break;
                    case SDLK_LEFT:
                        _state_variables.n--;
                        if (_state_variables.n < 0)
                            _state_variables.n = 2;
                        break;
                    case SDLK_RIGHT:
                        _state_variables.n++;
                        if (_state_variables.n > 2)
                            _state_variables.n = 0;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
        _sdl_variables.last_key_pressed = _sdl_variables.event;
    }

    return 0;
}

