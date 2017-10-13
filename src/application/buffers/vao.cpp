//
// Created by user on 13.10.2017.
//

#include "buffers/vao.hpp"

int application::graphics::vao::create() {

    glGenVertexArrays(1, &id);

    return 0;
}

int application::graphics::vao::bind() {

    glBindVertexArray(id);

    return 0;
}

int application::graphics::vao::bind(GLuint draw_style, GLuint used_vertices) {

    glBindVertexArray(id);
    glDrawElements(draw_style, used_vertices, GL_UNSIGNED_INT, nullptr);

    return 0;
}

application::graphics::vao::~vao() {

    glDeleteVertexArrays(1, &id);

}
