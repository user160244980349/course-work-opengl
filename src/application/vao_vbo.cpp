//
// Created by user on 08.10.2017.
//

#include "vao_vbo.hpp"

int application::graphics::vao_vbo::prepare(GLfloat* vertices, int count) {

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, count * sizeof( GLfloat ), ( GLvoid * ) 0);

    return 0;
}

int application::graphics::vao_vbo::draw(int count) {

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, count);

    return 0;
}

application::graphics::vao_vbo::~vao_vbo() {

    glDeleteVertexArrays( 1, &VAO );
    glDeleteBuffers( 1, &VBO );

}
