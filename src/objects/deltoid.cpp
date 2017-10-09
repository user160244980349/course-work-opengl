//
// Created by user on 10.10.2017.
//

#include "deltoid.hpp"

int application::objects::deltoid::draw() {

    GLuint order[] = {
            0u, 4u, 5u, 6u, 0u
    };

    buffers.bind_with_order(0, verices, 5, GL_LINE_STRIP, order);

    return 0;
}