//
// Created by user on 21.10.2017.
//


#include <objects/Cube.h>

Cube::~Cube() {}

Cube::Cube() : BaseObject() {
    _shaderProgram.compileShader("../resources/shaders/FirstVertex.glsl", VERTEX);
    _shaderProgram.compileShader("../resources/shaders/FirstFragment.glsl", FRAGMENT);
    _shaderProgram.link();
}

void Cube::render(ICamera &camera) {
    _shaderProgram.use();
    camera.display(_shaderProgram);
    _shaderProgram.setUniform("model", transform.getModel());
    _mesh.render();
}

void Cube::update() {

}

