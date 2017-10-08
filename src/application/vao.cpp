//
// Created by user on 08.10.2017.
//

#include "vao.hpp"


int application::graphics::vao::create() {

    glGenVertexArrays(1, &buffer);

    return 0;
}

application::graphics::vao::~vao() {

    glDeleteVertexArrays( 1, &buffer );

}

int application::graphics::vao::set(vbo b) {

    glBindVertexArray(buffer);
    glBindBuffer(GL_ARRAY_BUFFER, b.get());

    return 0;
}

int application::graphics::vao::bind() {

    glBindVertexArray(buffer);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    return 0;
}
