//
// Created by user on 10.10.2017.
//

#include "rectangle.hpp"

int application::objects::rectangle::draw() {

    GLuint order[] = {
        1u, 2u, 6u, 7u, 1u
    };

    buffers.bind_with_order(0, verices, 5, GL_LINE_STRIP, order);

    return 0;
}