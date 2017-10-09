//
// Created by user on 09.10.2017.
//

#include <base_object.hpp>
#include "figure.hpp"

int application::objects::figure::prepare() {

    shaders.emplace_back(graphics::shader("../src/shaders/first_vertex.glsl", "../src/shaders/first_fragment.glsl"));
    shaders.front().use();

    verices.emplace_back(graphics::vertex{glm::vec2(-1.0f, -1.0f), glm::vec3(1.0f, 0.0f, 0.0f)});
    verices.emplace_back(graphics::vertex{glm::vec2( 0.0f,  1.0f), glm::vec3(1.0f, 1.0f, 1.0f)});
    verices.emplace_back(graphics::vertex{glm::vec2( 1.0f, -1.0f), glm::vec3(0.0f, 0.0f, 1.0f)});

    buffers.new_buffer_combo(GL_TRIANGLES, verices);

    return 0;
}

int application::objects::figure::draw() {

    buffers.bind(0, verices);

    return 0;
}