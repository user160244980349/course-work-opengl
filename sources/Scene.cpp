//
// Created by user on 20.10.2017.
//

#include <objects/DynamicCamera.h>
#include <objects/Nanosuit.h>
#include <objects/Cube.h>
#include "objects/Scene.h"


void Scene::prepare() {

    _shader.compileShader("../resources/shaders/vertex.glsl", VERTEX);
    _shader.compileShader("../resources/shaders/fragment.glsl", FRAGMENT);
    _shader.link();

    _objects.push_back(new Nanosuit);
    dynamic_cast<Nanosuit *>(_objects.back())->transform.translate(glm::vec3(20.0f, -5.0f, 0.0f));
    dynamic_cast<Nanosuit *>(_objects.back())->transform.rotate(glm::radians(-135.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    _objects.push_back(new Cube);

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