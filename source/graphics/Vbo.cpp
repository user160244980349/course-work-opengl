//
// Created by user on 13.10.2017.
//

#include <graphics/OpenGl.h>
#include "graphics/Vbo.h"

Vbo::~Vbo() {

    OpenGl::getInstance().deleteBuffers(1, &id);

}

int Vbo::create() {

    OpenGl::getInstance().genBuffers(1, &id);

    return 0;
}

int Vbo::set(glm::vec3* v, GLuint size) {

    OpenGl::getInstance().bindBuffer(GL_ARRAY_BUFFER, id);
    OpenGl::getInstance().bufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * size, v, GL_STATIC_DRAW);

    OpenGl::getInstance().vertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), static_cast<GLvoid*>(nullptr));

    OpenGl::getInstance().enableVertexAttribArray(0);

    return 0;
}
