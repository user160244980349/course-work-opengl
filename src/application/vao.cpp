//
// Created by user on 08.10.2017.
//

#include "vao.hpp"


int application::graphics::vao::create() {
    glGenVertexArrays(1, &buffer);
    return 0;
}

application::graphics::vao::~vao() {
    glDeleteVertexArrays(1, &buffer);
}

int application::graphics::vao::set(vbo b, GLuint ds) {

    draw_style = ds;
    glBindVertexArray(buffer);
    glBindBuffer(GL_ARRAY_BUFFER, b.get());

    return 0;
}

int application::graphics::vao::bind(std::vector<glm::vec3> v) {
    glBindVertexArray(buffer);
    glDrawArrays(draw_style, 0, v.size());
    return 0;
}
