//
// Created by user on 20.10.2017.
//

#include <objects/DynamicCamera.h>
#include <objects/AngelLucy.h>
#include <objects/LucyBase.h>
#include <functional>
#include "objects/Scene.h"


void Scene::prepare() {

    _skyBoxShader.compileShader("../resources/shaders/skyboxVertex.glsl", VERTEX);
    _skyBoxShader.compileShader("../resources/shaders/skyboxFragment.glsl", FRAGMENT);
    _skyBoxShader.link();

    _shader.compileShader("../resources/shaders/mainVertex.glsl", VERTEX);
    _shader.compileShader("../resources/shaders/mainFragment.glsl", FRAGMENT);
    _shader.link();

    _depthShader.compileShader("../resources/shaders/depthVertex.glsl", VERTEX);
    _depthShader.link();

    _debug.compileShader("../resources/shaders/debugQuadVertex.glsl", VERTEX);
    _debug.compileShader("../resources/shaders/debugQuadFragment.glsl", FRAGMENT);
    _debug.link();

    _skyBox.load();

    _light.prepare();
    _camera.prepare();

    _shadowMap.prepare();
    _skyBox.prepare(_skyBoxShader);

    _objects.push_back(new AngelLucy);
    _objects.push_back(new LucyBase);

    for (auto &object : _objects) {
        object->prepare(_depthShader);
    }

    for (auto &object : _objects) {
        object->prepare(_shader);
    }

    _camera.lookVertical(-200);

    dynamic_cast<BaseObject *>(_objects.front())->transform.translate(glm::vec3(0.0f, 0.0f, 0.0f));
    dynamic_cast<BaseObject *>(_objects.front())->transform.rotate(glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    dynamic_cast<BaseObject *>(_objects.back())->transform.translate(glm::vec3(0.0f, 0.0f, 0.0f));
    dynamic_cast<BaseObject *>(_objects.back())->transform.rotate(glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
}

void Scene::render() {

    std::vector<std::reference_wrapper<Shader>> shaders;

    shaders.push_back(std::ref(_shader));
    shaders.push_back(std::ref(_skyBoxShader));
    shaders.push_back(std::ref(_depthShader));
    shaders.push_back(std::ref(_debug));

    _light.update(shaders);
    _camera.update(shaders);

    _shadowMap.bindForBuild(_depthShader);
//    OpenGl::getInstance().cullFace(GL_FRONT);
    for (auto &object : _objects) {
        object->render(_depthShader, _camera);
    }
//    OpenGl::getInstance().cullFace(GL_BACK);
    _shadowMap.unbind();

    _shadowMap.bind(_shader);
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