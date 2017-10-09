//
// Created by user on 07.10.2017.
//

#ifndef OPENGL_APPLICATION_HPP
#define OPENGL_APPLICATION_HPP

#include <SDL.h>
#include "timer.hpp"
#include "base_object.hpp"
#include "triangles.hpp"
#include "lines.hpp"
#include "isosceles_triangle.hpp"
#include "trapeze.hpp"
#include "nangle.hpp"
#include "parallelogram.hpp"
#include "rectangle.hpp"
#include "deltoid.hpp"
#include "rhombus.hpp"
#include "random_dots.hpp"

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
            objects::base_object figure;
            objects::triangles triangles;
            objects::lines lines;
            objects::isosceles_triangle isosceles_triangle;
            objects::trapeze trapeze;
            objects::nangle nangle;
            objects::parallelogram parallelogram;
            objects::rectangle rectangle;
            objects::deltoid deltoid;
            objects::rhombus rhombus;
            objects::random_dots random_dots;
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
