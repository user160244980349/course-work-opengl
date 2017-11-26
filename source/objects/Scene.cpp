//
// Created by user on 20.10.2017.
//

#include <objects/Cube.h>
#include <objects/DynamicCamera.h>
#include <input/IInput.h>
#include <iostream>
#include "graphics/Scene.h"

int application::graphics::Scene::prepare() {

    std::cout << "qq" << std::endl;
    _input->addCommands(dynamic_cast<input::IControlable*>(_camera)->getCommands());
    _input->addCommands(dynamic_cast<input::IControlable*>(_objects.back())->getCommands());

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
    dynamic_cast<input::IControlable*>(_camera)->initCommands();
    _objects.push_back(new objects::Cube);
    dynamic_cast<input::IControlable*>(_objects.back())->initCommands();

}

application::graphics::Scene::~Scene() {

    delete(_camera);

    for (auto &object : _objects) {
        delete(object);
    }

}
