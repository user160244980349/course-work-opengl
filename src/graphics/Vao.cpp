//
// Created by user on 13.10.2017.
//

#include <graphics/OpenGl.h>
#include "graphics/Vao.h"

application::graphics::Vao::~Vao() {

    OpenGl::getInstance()->glDeleteVertexArrays(1, &id);

}

int application::graphics::Vao::create() {

    OpenGl::getInstance()->glGenVertexArrays(1, &id);

    return 0;
}

int application::graphics::Vao::bind() {

    OpenGl::getInstance()->glBindVertexArray(id);

    return 0;
}

int application::graphics::Vao::bind(GLuint draw_style, GLuint used_vertices) {

    OpenGl::getInstance()->glBindVertexArray(id);
    OpenGl::getInstance()->glDrawElements(draw_style, used_vertices, GL_UNSIGNED_INT, static_cast<GLvoid*>(nullptr));
    OpenGl::getInstance()->glBindVertexArray(0);

    return 0;
}
