//
// Created by user on 07.10.2017.
//

#include <primitive.hpp>

int application::objects::primitive::prepare_shaders() {

    shaders.s1.prepare("../src/shaders/first_vertex.glsl", "../src/shaders/first_fragment.glsl");

    return 0;
}

int application::objects::primitive::draw() {

    shaders.s1.draw();

    return 0;
}

