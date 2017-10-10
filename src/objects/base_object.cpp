//
// Created by user on 09.10.2017.
//

#include "objects/base_object.hpp"

int application::objects::base_object::prepare() {

    shaders.emplace_back(graphics::shader(
            "../src/shaders/first_vertex.glsl",
            "../src/shaders/first_fragment.glsl")
    );

    shaders.front().use();

    verices.emplace_back(graphics::vertex_2d{glm::vec2(-0.9f, -0.9f), glm::vec3(1.0f, 0.0f, 0.0f)});
    verices.emplace_back(graphics::vertex_2d{glm::vec2( 0.0f,  0.9f), glm::vec3(0.0f, 1.0f, 0.0f)});
    verices.emplace_back(graphics::vertex_2d{glm::vec2( 0.9f, -0.9f), glm::vec3(0.0f, 0.0f, 1.0f)});

    buffers.new_buffer_combo(GL_TRIANGLES, verices);

    return 0;
}

int application::objects::base_object::draw() {

    buffers.bind(0, verices.size(), 0);

    return 0;
}