//
// Created by user on 08.10.2017.
//

#include "vbo.hpp"

int application::graphics::vbo::create() {
    glGenBuffers(1, &buffer);
    return 0;
}

application::graphics::vbo::~vbo() {
//    TODO destructor crash
//    glDeleteBuffers(1, &buffer);
}

int application::graphics::vbo::set(std::vector<glm::vec3> v) {
    glBufferData( GL_ARRAY_BUFFER, sizeof(glm::vec3) * v.size(), v.data(), GL_STATIC_DRAW );
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), nullptr);
    glEnableVertexAttribArray(0);
    return 0;
}

GLuint application::graphics::vbo::get() {
    return buffer;
}
