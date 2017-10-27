//
// Created by user on 13.10.2017.
//

#include <graphics/Vertex3d.h>
#include <graphics/OpenGl.h>
#include "graphics/Vbo.h"

application::graphics::Vbo::~Vbo() {

    OpenGl::getInstance()->deleteBuffers(1, &id);

}

int application::graphics::Vbo::create() {

    OpenGl::getInstance()->genBuffers(1, &id);

    return 0;
}

int application::graphics::Vbo::set(Vertex3d *v, GLuint size) {

    OpenGl::getInstance()->bindBuffer(GL_ARRAY_BUFFER, id);
    OpenGl::getInstance()->bufferData(GL_ARRAY_BUFFER, sizeof(Vertex3d) * size, v, GL_STATIC_DRAW);

    OpenGl::getInstance()->vertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex3d), static_cast<GLvoid*>(nullptr));
    OpenGl::getInstance()->vertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex3d), reinterpret_cast<GLvoid*>(sizeof(glm::vec4)));

    OpenGl::getInstance()->enableVertexAttribArray(0);
    OpenGl::getInstance()->enableVertexAttribArray(1);

    return 0;
}
