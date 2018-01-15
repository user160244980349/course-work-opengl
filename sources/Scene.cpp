//
// Created by user on 20.10.2017.
//

#include <objects/DynamicCamera.h>
#include <objects/AngelLucy.h>
#include <objects/LucyBase.h>
#include <SDL2/SDL_timer.h>
#include "objects/Scene.h"


void Scene::prepare() {

    _skyBoxShader.compileShader("../resources/shaders/skyboxVertex.glsl", VERTEX);
    _skyBoxShader.compileShader("../resources/shaders/skyboxFragment.glsl", FRAGMENT);
    _skyBoxShader.link();

    _shader.compileShader("../resources/shaders/vertex.glsl", VERTEX);
    _shader.compileShader("../resources/shaders/fragment.glsl", FRAGMENT);
    _shader.link();

    _skyBox.load();
    _skyBox.prepare(_skyBoxShader);

    _objects.push_back(new AngelLucy);
    dynamic_cast<BaseObject *>(_objects.back())->transform.translate(glm::vec3(0.0f, 0.0f, 0.0f));
    dynamic_cast<BaseObject *>(_objects.back())->transform.rotate(glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    _objects.push_back(new LucyBase);
    dynamic_cast<BaseObject *>(_objects.back())->transform.rotate(glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    dynamic_cast<BaseObject *>(_objects.back())->transform.translate(glm::vec3(3.0f, 0.0f, 0.0f));

    for (auto &object : _objects) {
        object->prepare(_shader);
    }

    _camera.lookVertical(-200);
}

void Scene::render() {

    _camera.update();

    float time = SDL_GetTicks() * 0.001f;
    glm::vec3 lightColor = glm::normalize(glm::vec3(sinf(time), cosf(time + 1), sinf(time + 2)));
    float lightIntense = 0.05f;
    _shader.use();
    _shader.setUniform("lightColor", lightColor);
    _shader.setUniform("lightIntense", lightIntense);
    _skyBoxShader.use();
    _skyBoxShader.setUniform("lightColor", lightColor);
    _skyBoxShader.setUniform("lightIntense", 0.1f);

    for (auto &object : _objects) {
        object->render(_shader, _camera);
    }

    _skyBox.render(_skyBoxShader, _camera);

}

void Scene::update() {
    for (auto &object : _objects) {
        auto updatableObject = dynamic_cast<IObject *>(object);
        if (updatableObject != nullptr) {
            updatableObject->update();
        }
    }
}

Scene::~Scene() {
    for (auto &object : _objects) {
        delete (object);
    }
    _objects.clear();
}