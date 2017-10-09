//
// Created by user on 09.10.2017.
//

#include "vao_vbo.hpp"

application::graphics::vao_vbo::~vao_vbo() {

    for (int i = 0; i < buffers.size(); i++) {
        glDeleteVertexArrays(i, &buffers[i].vao);
        glDeleteBuffers(i, &buffers[i].vbo);
    }
}

int application::graphics::vao_vbo::new_buffer_combo(GLuint ds, std::vector<vertex> &v) {

    buffers_combo bc;

    bc.ds = ds;
    glGenVertexArrays(1, &bc.vao);
    glGenBuffers(1, &bc.vbo);
    glBindVertexArray(bc.vao);
    glBindBuffer(GL_ARRAY_BUFFER, bc.vbo);

    //Разрешить использование вершинного атрибута с индексом 0 (позиция)
    glEnableVertexAttribArray(0);
    //Указываем параметры доступа вершинного атрибута к VBO
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (GLbyte*)NULL);
    //Разрешить использование вершинного атрибута с индексом 1 (цвет)
    glEnableVertexAttribArray(1);
    //Указываем параметры доступа вершинного атрибута к VBO
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (GLbyte*)NULL + sizeof(glm::vec2));

    glBufferData( GL_ARRAY_BUFFER, sizeof(vertex) * v.size(), v.data(), GL_STATIC_DRAW );

    buffers.emplace_back(bc);

    return 0;
}

int application::graphics::vao_vbo::delete_buffer_combo(unsigned int n) {

    glDeleteVertexArrays( n, &buffers[n].vao );
    glDeleteBuffers( n, &buffers[n].vbo );
    buffers.erase(buffers.begin() + n);

    return 0;
}

int application::graphics::vao_vbo::bind_with_order(unsigned int n, std::vector<vertex> v, GLuint* o) {

    glBindVertexArray(buffers[n].vao);
    glDrawElements(buffers[n].ds, v.size(), GL_UNSIGNED_INT, o);

    return 0;
}

int application::graphics::vao_vbo::bind(unsigned int n, std::vector<vertex> v) {

    glBindVertexArray(buffers[n].vao);
    glDrawArrays(buffers[n].ds, 0, v.size());

    return 0;
}
