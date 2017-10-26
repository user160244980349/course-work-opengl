//
// Created by user on 13.10.2017.
//

#include <graphics/Vertex3d.h>
#include "graphics/Vbo.h"


application::graphics::Vbo::~Vbo() {

    glDeleteBuffers(1, &id);

}



int application::graphics::Vbo::create() {

    glGenBuffers(1, &id);

    return 0;
}



int application::graphics::Vbo::set(Vertex3d *v, GLuint size) {

    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex3d) * size, v, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex3d), static_cast<GLvoid*>(nullptr));
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex3d), reinterpret_cast<GLvoid*>(sizeof(glm::vec4)));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    return 0;
}
