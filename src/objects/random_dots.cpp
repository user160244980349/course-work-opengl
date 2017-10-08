//
// Created by user on 09.10.2017.
//

#include "random_dots.hpp"

int application::objects::random_dots::prepare() {

    graphics::shader shader1;
    shader1.prepare("../src/shaders/first_vertex.glsl", "../src/shaders/first_fragment.glsl");
    shader1.use();

    for (GLfloat i = -1.0f; i <= 1.0f; i+=0.1f) {
        for (GLfloat j = -1.0f; j <= 1.0f; j+=0.1f) {
            verices.emplace_back(glm::vec3(0.05+i-0.05f, 0.05+j-0.05f, 0.0f));
            verices.emplace_back(glm::vec3(0.05+i+0.05f, 0.05+j-0.05f, 0.0f));
            verices.emplace_back(glm::vec3(0.05+i+0.0f, 0.05+j+0.05f, 0.0f));
        }
    }

    buffers.vao_buffer.create();
    buffers.vbo_buffer.create();

    buffers.vao_buffer.set(buffers.vbo_buffer, GL_TRIANGLES);
    buffers.vbo_buffer.set(verices);

    shaders.push_back(shader1);

    return 0;
}

int application::objects::random_dots::draw() {
    buffers.vao_buffer.bind(verices);
    return 0;
}