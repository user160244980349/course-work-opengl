#include "../include/objects/LucyBase.h"

void LucyBase::prepare(Shader &shader) {

//    _model = ModelLoader::getInstacne().load("lucy/base.obj");
    shader.use();
    _model.prepare(shader);
}

void LucyBase::render(Shader &shader, ICamera &camera) {

    shader.use();
    shader.setUniform("view", camera.getView());
    shader.setUniform("projection", camera.getProjection());
    shader.setUniform("model", transform.getModel());
    shader.setUniform("viewPos", camera.getPosition());

    _model.render(shader, camera);
}

void LucyBase::update() {

}
