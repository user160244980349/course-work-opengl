//
// Created by user on 12.01.2018.
//

#include <core/ModelLoader.h>
#include "objects/M4A1.h"

void M4A1::prepare(ShaderProgram &shader) {
//    _model = ModelLoader::getInstacne().load("../resources/models/floor/sol.obj");
    _model = ModelLoader::getInstacne().load("../resources/models/m4a1/m4a1_s.obj");
    _model.prepare(shader);
}

void M4A1::render(ShaderProgram &shader) {
    shader.setUniform("model", transform.getModel());
    _model.render(shader);
}

void M4A1::update() {

}