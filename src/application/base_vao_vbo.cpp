//
// Created by user on 09.10.2017.
//

#include <buffers_combo.hpp>
#include <vertex_3d.hpp>
#include "base_vao_vbo.hpp"

application::graphics::base_vao_vbo::~base_vao_vbo() {

    for (int i = 0; i < buffers.size(); i++) {
        glDeleteVertexArrays(1, &buffers[i].vao);
        glDeleteBuffers(1, &buffers[i].vbo);
        glDeleteBuffers(1, &buffers[i].ebo);
    }
}

int application::graphics::base_vao_vbo::new_buffer_combo(GLuint ds, vertex_3d *v, GLuint* o) {

    buffers.emplace_back();
    buffers.back().draw_style = ds;
    buffers.back().used_vertices = sizeof(GLuint) * sizeof(o);

    glGenVertexArrays(1, &buffers.back().vao);
    glGenBuffers(1, &buffers.back().vbo);
    glGenBuffers(1, &buffers.back().ebo);

    glBindVertexArray(buffers.back().vao);

    glBindBuffer(GL_ARRAY_BUFFER, buffers.back().vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_3d) * sizeof(v), v, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers.back().ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * sizeof(o), o, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(vertex_3d), (GLvoid*)nullptr);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(vertex_3d), (GLvoid*)sizeof(glm::vec4));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    return 0;
}

int application::graphics::base_vao_vbo::delete_buffer_combo(unsigned int n) {

    glDeleteVertexArrays(n, &buffers[n].vao);
    glDeleteBuffers(n, &buffers[n].vbo);
    glDeleteBuffers(n, &buffers[n].ebo);
    buffers.erase(buffers.begin() + n);

    return 0;
}

int application::graphics::base_vao_vbo::bind(unsigned int i, GLboolean warframe) {

    if (warframe)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glBindVertexArray(buffers[i].vao);
    glDrawElements(buffers[i].draw_style, buffers[i].used_vertices, GL_UNSIGNED_INT, nullptr);

    return 0;
}
