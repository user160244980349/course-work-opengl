//
// Created by user on 21.10.2017.
//


#include <objects/AngelLucy.h>
#include <core/ModelLoader.h>


void AngelLucy::prepare(Shader &shader) {

    _model = ModelLoader::getInstacne().load("lucy/lucy.obj");
    _model.prepare(shader);
}

void AngelLucy::render(Shader &shader, ICamera &camera, SkyBox &skyBox) {

    shader.use();
    shader.setUniform("camera.view", camera.getView());
    shader.setUniform("camera.projection", camera.getProjection());
    shader.setUniform("viewPosition", camera.getPosition());
    shader.setUniform("camera.model", transform.getModel());

    _model.render(shader, camera, skyBox);
}

void AngelLucy::update() {

}

