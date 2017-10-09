//
// Created by user on 10.10.2017.
//

#include "trapeze.hpp"

int application::objects::trapeze::draw() {

    GLuint order[] = {
            1u, 3u, 7u, 9u, 1u
    };

    buffers.bind_with_order(0, verices, 5, GL_LINE_STRIP, order);

    return 0;
}