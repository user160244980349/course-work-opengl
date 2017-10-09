//
// Created by user on 09.10.2017.
//

#include "isosceles_triangle.hpp"

int application::objects::isosceles_triangle::draw() {

    GLuint order[] = {
        0u, 4u, 6u, 0u
    };

    buffers.bind_with_order(0, verices, 4, GL_LINE_STRIP, order);

    return 0;
}