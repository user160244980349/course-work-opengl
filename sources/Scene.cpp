//
// Created by user on 20.10.2017.
//

#include <objects/Cube.h>
#include <objects/DynamicCamera.h>
#include "objects/Scene.h"


void Scene::prepare() {

    _shader.compileShader("../resources/shaders/FirstVertex.glsl", VERTEX);
    _shader.compileShader("../resources/shaders/FirstFragment.glsl", FRAGMENT);
    _shader.link();

    _objects.push_back(new Cube);
    dynamic_cast<Cube *>(_objects.back())->transform.rotate(glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    dynamic_cast<Cube *>(_objects.back())->transform.translate(glm::vec3(0.0f, -100.0f, -300.0f));

    for (auto &object : _objects) {
        object->prepare(_shader);
    }
}

void Scene::render() {

    _camera.update(_shader);

    for (auto &object : _objects) {
        object->render(_shader);
    }
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