//
// Created by user on 21.10.2017.
//


#include <objects/Cube.h>


void Cube::prepare(ShaderProgram &shader) {
    _mesh.prepare(shader);
}

void Cube::render(ShaderProgram &shader) {
    shader.use();
    shader.setUniform("model", transform.getModel());
    _mesh.render(shader);
}

void Cube::update() {

}

