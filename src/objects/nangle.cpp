//
// Created by user on 10.10.2017.
//

#include "nangle.hpp"

int application::objects::nangle::draw() {
    GLuint order[] = {
        1u, 4u, 9u, 6u, 1u
    };

    buffers.bind_with_order(0, verices, 5, GL_LINE_STRIP, order);

    return 0;
}