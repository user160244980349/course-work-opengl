//
// Created by user on 20.10.2017.
//

#include <objects/Cube.h>
#include <objects/DynamicCamera.h>
#include "objects/Scene.h"

int Scene::draw() {

    for (auto &object : _objects) {
        object->update();
    }

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
    dynamic_cast<Cube*>(_objects.back())->translate({9,0,0});
    _objects.push_back(new Cube);
    dynamic_cast<Cube*>(_objects.back())->translate({6,0,0});
    _objects.push_back(new Cube);
    dynamic_cast<Cube*>(_objects.back())->translate({3,0,0});

    _objects.push_back(new Cube);
    dynamic_cast<Cube*>(_objects.back())->translate({9,0,3});
    _objects.push_back(new Cube);
    dynamic_cast<Cube*>(_objects.back())->translate({6,0,3});
    _objects.push_back(new Cube);
    dynamic_cast<Cube*>(_objects.back())->translate({3,0,3});

    _objects.push_back(new Cube);
    dynamic_cast<Cube*>(_objects.back())->translate({9,0,6});
    _objects.push_back(new Cube);
    dynamic_cast<Cube*>(_objects.back())->translate({6,0,6});
    _objects.push_back(new Cube);
    dynamic_cast<Cube*>(_objects.back())->translate({3,0,6});

    for (auto &object : _objects) {
        auto drawableObject = dynamic_cast<IDrawable*>(object);
        if (drawableObject != nullptr) {
            drawableObject->setCamera(_camera);
        }
    }
}

Scene::~Scene() {
    for (auto &object : _objects) {
        delete(object);
    }
    _objects.clear();
}
