//
// Created by user on 21.10.2017.
//


#include <objects/AngelLucy.h>
#include <core/ModelLoader.h>


void AngelLucy::prepare(Shader &shader) {

    _model = ModelLoader::getInstacne().load("lucy/lucy.obj");
    shader.use();
    _model.prepare(shader);
}

void AngelLucy::render(Shader &shader, ICamera &camera, SkyBox &skyBox) {

    shader.use();
    shader.setUniform("view", camera.getView());
    shader.setUniform("projection", camera.getProjection());
    shader.setUniform("model", transform.getModel());
    shader.setUniform("viewPos", camera.getPosition());

    _model.render(shader, camera, skyBox);
}

void AngelLucy::update() {

}

