//
// Created by user on 10.10.2017.
//

#include <iostream>
#include <ctime>
#include "random_dots.hpp"

int application::objects::random_dots::prepare() {

    shaders.emplace_back(graphics::shader(
            "../src/shaders/first_vertex.glsl",
            "../src/shaders/first_fragment.glsl")
    );

    shaders.front().use();

    srand(time(0));

    for (int i = 0; i < 10000; i++) {
        verices.emplace_back(graphics::vertex{
                glm::vec2((float)(rand() % 200 - 100) / 100, (float)(rand() % 200 - 100) / 100) ,
                glm::vec3((float)(rand() % 100) / 100, (float)(rand() % 100) / 100, (float)(rand() % 100) / 100) //1.0f, 1.0f, 0.0f
        });
    }

    buffers.new_buffer_combo(GL_POINTS, verices);

    return 0;
}

int application::objects::random_dots::draw() {

    buffers.bind(0, verices);

    return 0;
}