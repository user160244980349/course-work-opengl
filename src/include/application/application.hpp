//
// Created by user on 07.10.2017.
//

#ifndef OPENGL_APPLICATION_HPP
#define OPENGL_APPLICATION_HPP

#include <SDL.h>
#include "timer.hpp"
#include "objects/base_object.hpp"

namespace application {

    class application {
    private:

        struct {
            const int width = 800;
            const int height = 600;
        } window_parameters;

        struct {
            SDL_Window *window;
            SDL_Event event;
            SDL_Event last_key_pressed;
        } sdl_variables;

        struct {
            bool running = true;
            int n = 0; // номер задания
        } state_variables;

        struct {
            objects::base_object base_object;
        } objects;

        timer frame_update;

        int init();
        int prepare_objects();
        int flow();
        int draw();
        int key_caption();

    public:

        application();
        ~application();
    };

}

#endif //OPENGL_APPLICATION_HPP
