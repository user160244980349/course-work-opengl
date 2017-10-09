//
// Created by user on 09.10.2017.
//

#include "triangles.hpp"

int application::objects::triangles::prepare() {

    shaders.emplace_back(graphics::shader(
            "../src/shaders/first_vertex.glsl",
            "../src/shaders/first_fragment.glsl")
    );

    shaders.front().use();

    verices.emplace_back(graphics::vertex{glm::vec2( 0.0f,  0.9f), glm::vec3(1.0f, 0.0f, 0.0f)});
    verices.emplace_back(graphics::vertex{glm::vec2( 0.4f,  0.7f), glm::vec3(0.0f, 1.0f, 0.0f)});
    verices.emplace_back(graphics::vertex{glm::vec2( 0.7f,  0.25f), glm::vec3(0.0f, 0.0f, 1.0f)});
    verices.emplace_back(graphics::vertex{glm::vec2( 0.7f, -0.25f), glm::vec3(1.0f, 0.0f, 0.0f)});
    verices.emplace_back(graphics::vertex{glm::vec2( 0.4f, -0.7f), glm::vec3(0.0f, 1.0f, 0.0f)});
    verices.emplace_back(graphics::vertex{glm::vec2( 0.0f, -0.9f), glm::vec3(0.0f, 0.0f, 1.0f)});
    verices.emplace_back(graphics::vertex{glm::vec2(-0.4f, -0.7f), glm::vec3(1.0f, 0.0f, 0.0f)});
    verices.emplace_back(graphics::vertex{glm::vec2(-0.7f, -0.25f), glm::vec3(0.0f, 1.0f, 0.0f)});
    verices.emplace_back(graphics::vertex{glm::vec2(-0.7f,  0.25f), glm::vec3(0.0f, 0.0f, 1.0f)});
    verices.emplace_back(graphics::vertex{glm::vec2(-0.4f,  0.7f), glm::vec3(1.0f, 0.0f, 0.0f)});
    verices.emplace_back(graphics::vertex{glm::vec2( -0.1f,  0.25f), glm::vec3(0.0f, 1.0f, 0.0f)});

    buffers.new_buffer_combo(GL_TRIANGLES, verices);

    return 0;
}

int application::objects::triangles::draw() {

    GLuint order[] = {
            0u, 1u, 2u,
            2u, 3u, 4u,
            4u, 5u, 6u,
            6u, 7u, 8u,
            8u, 9u, 0u
    };

    buffers.bind_with_order(0, verices, sizeof(order), GL_TRIANGLES, order);

    return 0;
}