//
// Created by user on 12.01.2018.
//

#include <core/ModelLoader.h>
#include "objects/Cube.h"

void Cube::prepare(Shader &shader) {
    _model = ModelLoader::getInstacne().load("../resources/models/cube/cube.obj");
    _model.prepare(shader);
}

void Cube::render(Shader &shader) {
    shader.setUniform("model", transform.getModel());
    _model.render(shader);
}

void Cube::update() {

}