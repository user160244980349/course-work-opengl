//
// Created by user on 12.01.2018.
//

#include <core/ModelLoader.h>
#include "objects/Cube.h"

void Cube::prepare(Shader &shader) {
    _model = ModelLoader::getInstacne().load("room/untitled.obj");
    _model.prepare(shader);
}

void Cube::render(Shader &shader, ICamera &camera) {

    shader.use();
    shader.setUniform("camera.view", camera.getView());
    shader.setUniform("camera.projection", camera.getProjection());
    shader.setUniform("camera.model", transform.getModel());

    _model.render(shader, camera);
}

void Cube::update() {

}

