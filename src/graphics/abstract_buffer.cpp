//
// Created by user on 13.10.2017.
//

#include "graphics/abstract_buffer.hpp"

application::graphics::abstract_buffer::~abstract_buffer() {
    glDeleteBuffers(1, &id);
}

int application::graphics::abstract_buffer::create() {
    return 0;
}
