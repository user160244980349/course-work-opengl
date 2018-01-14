//
// Created by user on 20.10.2017.
//

#include <objects/DynamicCamera.h>
#include <objects/AngelLucy.h>
#include "objects/Scene.h"


void Scene::prepare() {

    _shader.compileShader("../resources/shaders/vertex.glsl", VERTEX);
    _shader.compileShader("../resources/shaders/fragment.glsl", FRAGMENT);
    _shader.link();

    _skyBoxShader.compileShader("../resources/shaders/skyboxVertex.glsl", VERTEX);
    _skyBoxShader.compileShader("../resources/shaders/skyboxFragment.glsl", FRAGMENT);
    _skyBoxShader.link();

    _objects.push_back(new AngelLucy);
    dynamic_cast<BaseObject *>(_objects.back())->transform.translate(glm::vec3(20.0f, 0.0f, 0.0f));
    dynamic_cast<BaseObject *>(_objects.back())->transform.rotate(glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    for (auto &object : _objects) {
        object->prepare(_shader);
    }

    _camera.lookVertical(-200);

    _skyBox.load();
    _skyBox.prepare(_skyBoxShader);
}

void Scene::render() {

    _camera.update();


    for (auto &object : _objects) {
        object->render(_shader, _camera, _skyBox);
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