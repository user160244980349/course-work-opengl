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
        } _window_parameters;

        struct {
            SDL_Window *window;
            SDL_Event event;
            SDL_Event last_key_pressed;
        } _sdl_variables;

        struct {
            bool running = true;
            GLboolean warframe = GL_FALSE;
        } _state_variables;

        int _init();
        int _prepare_objects();
        int _flow();
        int _draw();
        int _key_caption();

    public:

        kernel(int width, int height);
        ~kernel();
    };

}

#endif //OPENGL_APPLICATION_HPP
