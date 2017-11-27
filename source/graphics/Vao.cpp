//
// Created by user on 13.10.2017.
//

#include <graphics/OpenGl.h>
#include "graphics/Vao.h"

Vao::~Vao() {

    OpenGl::getInstance()->deleteVertexArrays(1, &id);

}

int Vao::create() {

    OpenGl::getInstance()->genVertexArrays(1, &id);

    return 0;
}

int Vao::bind() {

    OpenGl::getInstance()->bindVertexArray(id);

    return 0;
}

int Vao::bind(GLuint draw_style, GLuint used_vertices) {

    OpenGl::getInstance()->bindVertexArray(id);
    OpenGl::getInstance()->drawElements(draw_style, used_vertices, GL_UNSIGNED_INT, static_cast<GLvoid*>(nullptr));
    OpenGl::getInstance()->bindVertexArray(0);

    return 0;
}
