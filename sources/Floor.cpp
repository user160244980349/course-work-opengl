//
// Created by user on 12.01.2018.
//

#include <core/ModelLoader.h>
#include "objects/Floor.h"

void Floor::prepare(ShaderProgram &shader) {
//    _model = ModelLoader::getInstacne().load("../resources/models/floor/sol.obj");
    _model = ModelLoader::getInstacne().load("../resources/models/m4a1/m4a1_s.obj");
    _model.prepare(shader);
}

void Floor::render(ShaderProgram &shader) {
    shader.setUniform("model", transform.getModel());
    _model.render(shader);
}

void Floor::update() {

}