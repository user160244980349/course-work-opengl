//
// Created by user on 20.10.2017.
//

#include <objects/Cube.h>
#include <objects/DynamicCamera.h>
#include "objects/Scene.h"

int Scene::draw() {

    _camera.update();

//    for (auto &object : _objects) {
//        object->update();
//    }

    for (auto &object : _objects) {
        auto drawableObject = dynamic_cast<IDrawable *>(object);
        if (drawableObject != nullptr) {
            drawableObject->draw();
        }
    }

    return 0;
}

Scene::Scene() {

    for (int i = -10; i < 10; i++) {
        for (int j = -10; j < 10; j++) {
            for (int k = -10; k < 10; k++) {
                _objects.push_back(new Cube);
                dynamic_cast<Cube *>(_objects.back())->translate({i * 3, k * 3, j * 3});
            }
        }
    }

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
