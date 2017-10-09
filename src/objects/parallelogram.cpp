//
// Created by user on 10.10.2017.
//

#include "parallelogram.hpp"

int application::objects::parallelogram::draw() {

    GLuint order[] = {
        2u, 4u, 6u, 10u, 2u
    };

    buffers.bind_with_order(0, verices, 5, GL_LINE_STRIP, order);

    return 0;
}