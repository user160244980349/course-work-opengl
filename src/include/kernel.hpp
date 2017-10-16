//
// Created by user on 07.10.2017.
//

#ifndef OPENGL_APPLICATION_HPP
#define OPENGL_APPLICATION_HPP


#ifdef __linux__
#include <SDL2/SDL.h>
#elif _WIN32
#include <SDL.h>
#include <objects/base_object.hpp>
#include <objects/one_sheet_hyperboloid.hpp>
#include <objects/bicameral_hyperboloid.hpp>
#include <time/interval_timer.hpp>
#include <time/timer.hpp>

#endif

#include "GL/glew.h"

namespace application {

    class kernel {
    public:
        kernel(int width, int height);
        ~kernel();

    private:
        struct {
            int width;
            int height;
        } _window_parameters;

        struct {
            SDL_Window *window;
            SDL_Event event;
            SDL_Event last_key_pressed;
        } _sdl_variables;

        struct {
            objects::base_object base_object;
            objects::one_sheet_hyperboloid one_sheet_hyperboloid;
            objects::bicameral_hyperboloid bicameral_hyperboloid;
        } objects;

        struct {
            bool running = true;
            time::timer world_time ;
            time::interval_timer frame_update;
            GLboolean warframe = GL_FALSE;
            int n = 0;
        } _state_variables;

        int _init();
        int _prepare_objects();
        int _flow();
        int _draw();
        int _key_caption();
    };

}

#endif //OPENGL_APPLICATION_HPP
