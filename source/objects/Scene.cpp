//
// Created by user on 20.10.2017.
//

#include <objects/Cube.h>
#include <objects/DynamicCamera.h>
#include <input/ClientInput.h>
#include "objects/Scene.h"

int Scene::draw() {

    _camera.update();
    for (auto &object : _objects) {
        auto drawableObject = dynamic_cast<IDrawable *>(object);
        if (drawableObject != nullptr) {
            drawableObject->draw();
        }
    }

    return 0;
}

Scene::Scene() {

    _objects.push_back(new Cube);
    dynamic_cast<Cube*>(_objects.back())->translate({8,0,3});
    _objects.push_back(new Cube);
    dynamic_cast<Cube*>(_objects.back())->translate({1,0,3});
    _objects.push_back(new Cube);
    dynamic_cast<Cube*>(_objects.back())->translate({4,0,3});
    _objects.push_back(new Cube);
    dynamic_cast<Cube*>(_objects.back())->translate({4,0,0});
    _objects.push_back(new Cube);
    dynamic_cast<Cube*>(_objects.back())->translate({4,0,-3});

    for (auto &object : _objects) {
        auto drawableObject = dynamic_cast<IDrawable*>(object);
        if (drawableObject != nullptr) {
            drawableObject->prepare();
            drawableObject->setCamera(_camera);
        }
    }

    dynamic_cast<IControlable*>(&_camera)->initCommands();
    ClientInput::getInstance().addCommands(dynamic_cast<IControlable*>(&_camera)->getCommands());
}

Scene::~Scene() {
    for (auto &object : _objects) {
        delete(object);
    }
    _objects.clear();
}
