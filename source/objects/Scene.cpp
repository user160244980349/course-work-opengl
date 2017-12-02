//
// Created by user on 20.10.2017.
//

#include <objects/Cube.h>
#include <objects/DynamicCamera.h>
#include <input/IInput.h>
#include "objects/Scene.h"

int Scene::prepare() {

    dynamic_cast<IControlable*>(_camera)->initCommands();
    _input->addCommands(dynamic_cast<IControlable*>(_camera)->getCommands());

    for (auto &object : _objects) {
        object->prepare();
        object->setCamera(_camera);
    }

    return 0;
}

int Scene::draw() {

    _camera->update();
    for (auto &object : _objects)
        object->draw();

    return 0;
}

Scene::Scene(IInput* input) {

    _input = input;
    _camera = new DynamicCamera;

    _objects.push_back(new Cube);

}

Scene::~Scene() {

    delete(_camera);

    for (auto &object : _objects) {
        delete(object);
    }

}
