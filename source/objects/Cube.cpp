//
// Created by user on 21.10.2017.
//


#include <objects/Cube.h>

Cube::~Cube() {}

Cube::Cube() : BaseObject() {
    _shaderProgram.compileShader("../resource/shaders/FirstVertex.glsl", VERTEX);
    _shaderProgram.compileShader("../resource/shaders/FirstFragment.glsl", FRAGMENT);
    _shaderProgram.link();
}

void Cube::render(ICamera &camera) {
    _shaderProgram.use();
    camera.display(_shaderProgram);
    _shaderProgram.setUniform("model", transform.getModel());
    _mesh.render();
}

void Cube::update() {
//    _transform.translate({3.0f * _id, sinf(SDL_GetTicks() + _id * 0.0005f) * 5, 3.0f * _id / 10});
}

