//
// Created by user on 08.10.2017.
//

#include <base_object.hpp>


int application::objects::base_object::prepare_shaders() {

    shaders.s1.prepare("../src/shaders/first_vertex.glsl", "../src/shaders/first_fragment.glsl");
    shaders.s1.use();

    buffers.vao_buffer.create();
    buffers.vbo_buffer.create();

    buffers.vao_buffer.set(buffers.vbo_buffer);
    buffers.vbo_buffer.set();

    return 0;
}

int application::objects::base_object::draw() {

    buffers.vao_buffer.bind();

    return 0;
}
