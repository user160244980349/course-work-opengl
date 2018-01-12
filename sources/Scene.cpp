//
// Created by user on 20.10.2017.
//

#include <objects/SASSoldier.h>
#include <objects/DynamicCamera.h>
#include "objects/Scene.h"


void Scene::prepare() {

    _shader.compileShader("../resources/shaders/FirstVertex.glsl", VERTEX);
    _shader.compileShader("../resources/shaders/FirstFragment.glsl", FRAGMENT);
    _shader.link();

//    _objects.push_back(new M4A1);
//    dynamic_cast<M4A1 *>(_objects.back())->transform.translate(glm::vec3(50.0f, 0.0f, -15.0f));

    _objects.push_back(new SASSoldier);
    dynamic_cast<SASSoldier *>(_objects.back())->transform.scale(glm::vec3(0.01));
    dynamic_cast<SASSoldier *>(_objects.back())->transform.rotate(glm::radians(-135.0f), glm::vec3(0.0f, 1.0f, 0.0f));


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