//
// Created by user on 13.10.2017.
//

#include <core/OpenGl.h>
#include "core/Vao.h"

void Vao::create() {
    OpenGl::getInstance().genVertexArrays(1, &_id);
}

void Vao::bind() {
    OpenGl::getInstance().bindVertexArray(_id);
}

void Vao::bind(GLuint draw_style, GLuint used_vertices) {
    OpenGl::getInstance().bindVertexArray(_id);
    OpenGl::getInstance().drawElements(draw_style, used_vertices, GL_UNSIGNED_INT, static_cast<GLvoid *>(nullptr));
}

void Vao::remove() {
    OpenGl::getInstance().deleteVertexArrays(1, &_id);
}
