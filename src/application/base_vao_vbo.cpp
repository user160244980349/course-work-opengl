//
// Created by user on 09.10.2017.
//

#include <iostream>
#include "base_vao_vbo.hpp"

application::graphics::base_vao_vbo::~base_vao_vbo() {

    for (int i = 0; i < buffers.size(); i++) {
        glDeleteVertexArrays(i, &buffers[i].vao);
        glDeleteBuffers(i, &buffers[i].vbo);
//        glDeleteBuffers(i, &buffers[i].ebo);
    }
}

int application::graphics::base_vao_vbo::new_buffer_combo(GLuint ds, vertex_3d *v, GLuint* o) {

    buffers.emplace_back();
    buffers.back().ds = ds;
    buffers.back().o = o;

    glGenVertexArrays(1, &buffers.back().vao);
    glGenBuffers(1, &buffers.back().vbo);
//    glGenBuffers(1, &buffers.back().ebo);

    glBindVertexArray(buffers.back().vao);

    glBindBuffer(GL_ARRAY_BUFFER, buffers.back().vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_3d) * sizeof(v), v, GL_STATIC_DRAW);

//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers.back().ebo);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(o), o, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(vertex_3d), (GLbyte*)nullptr);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(vertex_3d), (GLbyte*)sizeof(glm::vec4));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    return 0;
}

int application::graphics::base_vao_vbo::delete_buffer_combo(unsigned int n) {

    glDeleteVertexArrays(n, &buffers[n].vao);
    glDeleteBuffers(n, &buffers[n].vbo);
//    glDeleteBuffers(n, &buffers[n].ebo);
    buffers.erase(buffers.begin() + n);

    return 0;
}

int application::graphics::base_vao_vbo::bind(unsigned int i) {

    glBindVertexArray(buffers[i].vao);
    glDrawElements(buffers[i].ds, sizeof(buffers[i].o), GL_UNSIGNED_INT, buffers[i].o);

    return 0;
}
