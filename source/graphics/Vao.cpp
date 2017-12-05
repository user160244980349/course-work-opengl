//
// Created by user on 13.10.2017.
//

#include <graphics/OpenGl.h>
#include "graphics/Vao.h"

void Vao::create() {
    OpenGl::getInstance().genVertexArrays(1, &id);
}

void Vao::bind() {
    OpenGl::getInstance().bindVertexArray(id);
}

void Vao::bind(GLuint draw_style, GLuint used_vertices) {
    OpenGl::getInstance().bindVertexArray(id);
    OpenGl::getInstance().drawElements(draw_style, used_vertices, GL_UNSIGNED_INT, static_cast<GLvoid*>(nullptr));
}

void Vao::remove() {
    OpenGl::getInstance().deleteVertexArrays(1, &id);
}
