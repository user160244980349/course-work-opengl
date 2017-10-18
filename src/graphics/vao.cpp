//
// Created by user on 13.10.2017.
//

#include "graphics/vao.h"


application::graphics::vao::~vao() {

    glDeleteVertexArrays(1, &id);

}



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
    glBindVertexArray(0);

    return 0;
}
