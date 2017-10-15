//
// Created by user on 07.10.2017.
//

#ifndef OPENGL_APPLICATION_HPP
#define OPENGL_APPLICATION_HPP


#ifdef __linux__
#include <SDL2/SDL.h>
#elif _WIN32
#include <SDL.h>
#endif

#include "GL/glew.h"

namespace application {

    class kernel {
    private:

        struct {
            int width;
            int height;
        } window_parameters;

        struct {
            SDL_Window *window;
            SDL_Event event;
            SDL_Event last_key_pressed;
        } sdl_variables;

        struct {
            bool running = true;
            GLboolean warframe = GL_FALSE;
        } state_variables;

        int init();
        int prepare_objects();
        int flow();
        int draw();
        int key_caption();

    public:

        kernel(int width, int height);
        ~kernel();
    };

}

#endif //OPENGL_APPLICATION_HPP
