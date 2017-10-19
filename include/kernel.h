//
// Created by user on 07.10.2017.
//

#ifndef OPENGL_APPLICATION_H
#define OPENGL_APPLICATION_H


#ifdef __linux__
#include <SDL2/SDL.h>
#include <objects/one_sheet_hyperboloid.h>
#include <objects/base_object.h>
#include <objects/bicameral_hyperboloid.h>
#include <time/interval_timer.h>

#elif _WIN32
#include <SDL.h>
#include <objects/base_object.h>
#include <objects/one_sheet_hyperboloid.h>
#include <objects/bicameral_hyperboloid.h>
#include <time/interval_timer.h>
#include <time/timer.h>

#endif

#include "GL/glew.h"

namespace application {

    class kernel {
    public:
        kernel(int width, int height);
        ~kernel();

    protected:
        struct {
            int width;
            int height;
        } _window_parameters;

        struct {
            SDL_Window *window;
            SDL_Event event;
            SDL_KeyboardEvent last_key_pressed;
        } _sdl_variables;

        struct {
            objects::base_object base_object;
            objects::one_sheet_hyperboloid one_sheet_hyperboloid;
            objects::bicameral_hyperboloid bicameral_hyperboloid;
        } objects;

        struct {
            bool running = true;
            time::interval_timer frame_update;
            GLboolean warframe = GL_FALSE;
            int n = 0;
        } _state_variables;

        int init();
        int prepare_objects();
        int flow();
        int draw();
        int key_caption();
    };

}

#endif //OPENGL_APPLICATION_H
