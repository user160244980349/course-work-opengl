//
// Created by user on 09.10.2017.
//

#include "lines.hpp"

int application::objects::lines::draw() {

    GLuint order[] = {
            0u, 1u,
            2u, 3u,
            4u, 5u,
            6u, 7u,
            8u, 9u,
    };

    buffers.bind_with_order(0, verices, 10, GL_LINES, order);

    return 0;
}