//
// Created by user on 13.10.2017.
//

#include "graphics/Vao.h"


application::graphics::Vao::~Vao() {

    glDeleteVertexArrays(1, &id);

}

int application::graphics::Vao::create() {

    glGenVertexArrays(1, &id);

    return 0;
}

int application::graphics::Vao::bind() {

    glBindVertexArray(id);

    return 0;
}

int application::graphics::Vao::bind(GLuint draw_style, GLuint used_vertices) {

    glBindVertexArray(id);
    glDrawElements(draw_style, used_vertices, GL_UNSIGNED_INT, static_cast<GLvoid*>(nullptr));
    glBindVertexArray(0);

    return 0;
}
