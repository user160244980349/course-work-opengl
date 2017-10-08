//
// Created by user on 09.10.2017.
//

#include "rhombus.hpp"

int application::objects::rhombus::prepare() {

    graphics::shader shader1;
    shader1.prepare("../src/shaders/first_vertex.glsl", "../src/shaders/first_fragment.glsl");
    shader1.use();

    verices.emplace_back(glm::vec3(-0.5f, 0.0f, 0.0f));
    verices.emplace_back(glm::vec3(0.0f, -0.9f, 0.0f));
    verices.emplace_back(glm::vec3(0.5f, 0.0f, 0.0f));
    verices.emplace_back(glm::vec3(0.0f, 0.9f, 0.0f));
    verices.emplace_back(glm::vec3(-0.5f, 0.0f, 0.0f));

    buffers.vao_buffer.create();
    buffers.vbo_buffer.create();

    buffers.vao_buffer.set(buffers.vbo_buffer, GL_LINE_STRIP);
    buffers.vbo_buffer.set(verices);

    shaders.push_back(shader1);

    return 0;
}

int application::objects::rhombus::draw() {
    buffers.vao_buffer.bind(verices);
    return 0;
}