//
// Created by user on 07.10.2017.
//

#ifndef OPENGL_APPLICATION_HPP
#define OPENGL_APPLICATION_HPP

#include <SDL.h>
#include "cube.hpp"
#include "timer.hpp"
#include "base_object.hpp"
#include "figure.hpp"

namespace application {

    class application {
    private:

        struct {
            const int width = 640;
            const int height = 480;
        } window_parameters;

        struct {
            SDL_Window *window;
            SDL_Event event;
            SDL_Event last_key_pressed;
        } sdl_variables;

        struct {
            bool running = true;
        } state_variables;

        struct {
//            objects::cube cube;
            objects::figure figure;
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
