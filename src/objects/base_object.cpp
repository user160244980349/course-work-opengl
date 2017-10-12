//
// Created by user on 09.10.2017.
//

#include "base_object.hpp"

int application::objects::base_object::prepare() {

    shaders.emplace_back(graphics::shader(
            "../src/shaders/first_vertex.glsl",
            "../src/shaders/first_fragment.glsl")
    );

    shaders.front().use();

    verices.emplace_back(graphics::vertex_3d{glm::vec4(-0.9f, -0.9f, 0.0f, 1.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f)});
    verices.emplace_back(graphics::vertex_3d{glm::vec4(-0.9f,  0.9f, 0.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)});
    verices.emplace_back(graphics::vertex_3d{glm::vec4( 0.9f,  0.9f, 0.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)});
    verices.emplace_back(graphics::vertex_3d{glm::vec4( 0.9f, -0.9f, 0.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)});

    order.emplace_back(0u);
    order.emplace_back(1u);
    order.emplace_back(3u);
    order.emplace_back(1u);
    order.emplace_back(3u);
    order.emplace_back(2u);

    buffers.new_buffer_combo(GL_TRIANGLES, verices.data(), order.data());

    return 0;
}

int application::objects::base_object::draw() {

    buffers.bind(0, GL_FALSE);

    return 0;
}

int application::objects::base_object::draw_wf() {

    buffers.bind(0, GL_TRUE);

    return 0;
}