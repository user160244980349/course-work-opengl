//
// Created by user on 21.10.2017.
//


#include <objects/Cube.h>
#include <core/ModelLoader.h>


void Cube::prepare(ShaderProgram &shader) {
    ModelLoader loader;
    _model = loader.load("../resources/models/nanosuit/nanosuit.obj");
    _model.prepare(shader);
}

void Cube::render(ShaderProgram &shader) {
    shader.setUniform("model", transform.getModel());
    _model.render(shader);
}

void Cube::update() {

}

