//
// Created by user on 07.10.2017.
//

#ifndef OPENGL_APPLICATION_HPP
#define OPENGL_APPLICATION_HPP

#include <SDL.h>
#include "cube.hpp"
#include "timer.hpp"
#include "triangle.hpp"
#include "many_triangles.hpp"
#include "many_lines.hpp"
#include "nonfilled_triangle.hpp"
#include "trapeze.hpp"
#include "parallelogram.hpp"
#include "rectangle.hpp"
#include "nangle.hpp"
#include "deltoid.hpp"
#include "rhombus.hpp"
#include "random_dots.hpp"

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
//            objects::cube cd;
//            objects::triangle pd;
//            objects::many_triangles pd;
//            objects::many_lines pd;
//            objects::nonfilled_triangle pd;
//            objects::trapeze pd;
//            objects::parallelogram pd;
//            objects::rectangle pd;
//            objects::nangle pd;
//            objects::deltoid pd;
//            objects::rhombus pd;
            objects::random_dots pd;

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
