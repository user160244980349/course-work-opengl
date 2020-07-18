#include "../include/objects/AngelLucy.h"
#include "../include/core/ModelLoader.h"

void AngelLucy::prepare(Shader &shader) {

    _model = ModelLoader::getInstacne().load("Lucy/Lucy.obj");
    shader.use();
    _model.prepare(shader);
}

void AngelLucy::render(Shader &shader, ICamera &camera) {
    shader.use();
    shader.setUniform("model", transform.getModel());
    _model.render(shader, camera);
}

void AngelLucy::update() {

}
