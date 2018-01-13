//
// Created by user on 21.10.2017.
//


#include <objects/Dragon.h>
#include <core/ModelLoader.h>


void Dragon::prepare(Shader &shader) {
    _model = ModelLoader::getInstacne().load("Dragon/Dragon.obj");
    _model.prepare(shader);
}

void Dragon::render(Shader &shader) {
    shader.setUniform("model", transform.getModel());
    _model.render(shader);
}

void Dragon::update() {

}

