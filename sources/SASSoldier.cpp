//
// Created by user on 21.10.2017.
//


#include <objects/SASSoldier.h>
#include <core/ModelLoader.h>


void SASSoldier::prepare(ShaderProgram &shader) {
    _model = ModelLoader::getInstacne().load("../resources/models/CHR_SAS_Smoke/CHR_SAS_Smoke.obj");
    _model.prepare(shader);
}

void SASSoldier::render(ShaderProgram &shader) {
    shader.setUniform("model", transform.getModel());
    _model.render(shader);
}

void SASSoldier::update() {

}

