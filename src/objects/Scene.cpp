//
// Created by user on 20.10.2017.
//

#include <objects/Cube.h>
#include <objects/DynamicCamera.h>
#include <interfaces/IInput.h>
#include "graphics/Scene.h"

int application::graphics::Scene::prepare() {

    _input->subscribe(dynamic_cast<input::IControlable*>(_camera));

    _objects.push_back(new objects::Cube);

    for (auto &object : _objects) {
        object->prepare();
        object->setCamera(_camera);
    }

    return 0;
}

int application::graphics::Scene::draw() {

    _camera->update();
    for (auto &object : _objects)
        object->draw();

    return 0;
}

application::graphics::Scene::Scene(input::IInput* input) {

    _input = input;
    _camera = new objects::DynamicCamera;

}

application::graphics::Scene::~Scene() {

    delete(_camera);

    for (auto &object : _objects) {
        delete(object);
    }

}