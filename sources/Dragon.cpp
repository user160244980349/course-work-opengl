//
// Created by user on 21.10.2017.
//


#include <objects/Dragon.h>
#include <core/ModelLoader.h>


void Dragon::prepare(Shader &shader) {


    _model = ModelLoader::getInstacne().load("Dragon/Dragon.obj");
    _model.prepare(shader);
}

void Dragon::render(Shader &shader, ICamera &camera) {

    shader.use();
    shader.setUniform("camera.view", camera.getView());
    shader.setUniform("camera.projection", camera.getProjection());
    shader.setUniform("camera.model", transform.getModel());

    _model.render(shader, camera);
}

void Dragon::update() {

}

