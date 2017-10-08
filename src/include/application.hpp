//
// Created by user on 07.10.2017.
//

#ifndef OPENGL_APPLICATION_HPP
#define OPENGL_APPLICATION_HPP

#include <SDL.h>
#include "cube.hpp"

namespace application {

    class application {
    private:
        struct {
            const int width = 640; // ширина окна
            const int height = 480; // высота окна
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
            objects::cube c1;
        } objects;

        int init();
        int flow();
        int draw();
        int drop();

    public:
        application();
    };

}

#endif //OPENGL_APPLICATION_HPP
