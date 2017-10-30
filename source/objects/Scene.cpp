//
// Created by user on 20.10.2017.
//

#include <objects/Cube.h>
#include <objects/DynamicCamera.h>
#include <interfaces/IInput.h>
#include "graphics/Scene.h"

int application::graphics::Scene::prepare() {

    _input->addCommands(dynamic_cast<objects::DynamicCamera*>(_camera)->getCommands());

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

application::graphics::Scene::Scene(interfaces::IInput* input) {

    _input = input;
    _camera = new objects::DynamicCamera;
    _objects.push_back(new objects::Cube);

}

application::graphics::Scene::~Scene() {

    delete(_camera);

    for (auto &object : _objects) {
        delete(object);
    }

}
