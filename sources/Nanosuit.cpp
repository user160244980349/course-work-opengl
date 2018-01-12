//
// Created by user on 21.10.2017.
//


#include <objects/Nanosuit.h>
#include <core/ModelLoader.h>


void Nanosuit::prepare(Shader &shader) {
    _model = ModelLoader::getInstacne().load("nanosuit/nanosuit.obj");
    _model.prepare(shader);
}

void Nanosuit::render(Shader &shader) {
    shader.setUniform("model", transform.getModel());
    _model.render(shader);
}

void Nanosuit::update() {

}

