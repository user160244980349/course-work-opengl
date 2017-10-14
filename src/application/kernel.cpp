//
// Created by user on 07.10.2017.
//

#include <iostream>
#include <GL/glew.h>
#include <kernel.hpp>
#include <global_variables.hpp>


application::kernel::kernel() {

    init();
    prepare_objects();
    flow();

}

application::kernel::~kernel() {

    SDL_DestroyWindow(sdl_variables.window);
    SDL_Quit();

}

int application::kernel::init() {

    if ( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0 ){
        std::cout << "Unable to init SDL, error: " << SDL_GetError() << std::endl;
        exit(1);
    }

   sdl_variables.window = SDL_CreateWindow(
           "OpenGL",
           SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
           window_parameters.width,
           window_parameters.height,
           SDL_WINDOW_OPENGL |
           SDL_WINDOW_FULLSCREEN_DESKTOP
   );

    if(sdl_variables.window == nullptr){
        std::cout << "Unable to create window, error: " << SDL_GetError() << std::endl;
        exit(5);
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);

    SDL_GLContext glcontext = SDL_GL_CreateContext(sdl_variables.window);

    if(glcontext == nullptr){
        std::cout << "Unable to create OpenGL context, error: " << SDL_GetError() << std::endl;
        exit(6);
    }

    glewInit();

//    glViewport(0, 0, window_parameters.width, window_parameters.height);
    glEnable(GL_DEPTH_TEST);

    return 0;
}

int application::kernel::flow() {

    time::world_time.run();
    time::frame_update.set(0.016);
    time::frame_update.run();

    while(state_variables.running){

        key_caption();

        if (time::frame_update.fired) {
            time::frame_update.reset();
            draw();
            SDL_GL_SwapWindow(sdl_variables.window);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }
    }

    return 0;
}

int application::kernel::draw() {

    if (state_variables.warframe == GL_TRUE)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    scene::base_object.draw();

    return 0;
}

int application::kernel::prepare_objects() {

    scene::base_object.prepare();

    return 0;
}

int application::kernel::key_caption() {

    while(SDL_PollEvent(&sdl_variables.event)) {
        switch (sdl_variables.event.type) {
            case SDL_QUIT:
                state_variables.running = false;
                break;

            case SDL_KEYDOWN:
                switch (sdl_variables.event.key.keysym.sym) {
                    case SDLK_q:
                        if (sdl_variables.last_key_pressed.type == SDL_KEYDOWN &&
                            sdl_variables.last_key_pressed.key.keysym.sym == SDLK_LCTRL)
                            state_variables.running = false;
                        break;
                    case SDLK_w:
                        time::frame_update.stop();
                        break;
                    case SDLK_e:
                        time::frame_update.run();
                        break;
                    case SDLK_r:
                        if (state_variables.warframe == GL_TRUE)
                            state_variables.warframe = GL_FALSE;
                        else
                            state_variables.warframe = GL_TRUE;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
        sdl_variables.last_key_pressed = sdl_variables.event;
    }

    return 0;
}

