//
// Created by user on 20.10.2017.
//

#include <objects/Cube.h>
#include <objects/DynamicCamera.h>
#include "objects/Scene.h"

void Scene::draw() {

    _camera.update();

    for (auto &object : _objects) {
        object->update();
    }

    for (auto &object : _objects) {
        auto drawableObject = dynamic_cast<IDrawable *>(object);
        if (drawableObject != nullptr) {
            drawableObject->draw(_camera);
        }
    }
}

Scene::Scene() {

    for (int i = -10; i < 10; i++) {
        for (int j = -10; j < 10; j++) {
            _objects.push_back(new Cube);
            dynamic_cast<Cube*>(_objects.back())->translate({i * 3, 0, j * 3});
        }
    }

}

Scene::~Scene() {
    for (auto &object : _objects) {
        delete(object);
    }
    _objects.clear();
}
