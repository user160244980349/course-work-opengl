//
// Created by user on 08.10.2017.
//

#include "vao_vbo.hpp"

int application::graphics::vao_vbo::prepare() {

    glGenBuffers(1, &buffers.VBO);
    glBindVertexArray(buffers.VAO);

    return 0;
}

int application::graphics::vao_vbo::draw() {

    glBindVertexArray(buffers.VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    return 0;
}

application::graphics::vao_vbo::~vao_vbo() {

    glDeleteVertexArrays( 1, &buffers.VAO );
    glDeleteBuffers( 1, &buffers.VBO );

}
