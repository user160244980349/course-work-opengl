//
// Created by user on 20.10.2017.
//

#include <objects/Cube.h>
#include <objects/DynamicCamera.h>
#include "objects/Scene.h"

void Scene::render() {

    _camera.update();

    for (auto &object : _objects) {
        object->update();
    }

    for (auto &object : _objects) {
        auto drawableObject = dynamic_cast<IDrawable *>(object);
        if (drawableObject != nullptr) {
            drawableObject->render(_camera);
        }
    }
}

Scene::Scene() {

    for (int i = -40; i < 40; i++) {
        for (int j = -40; j < 40; j++) {
            _objects.push_back(new Cube);
            dynamic_cast<Cube*>(_objects.back())->transform.translate({i * 3, 0, j * 3});
        }
    }

}

Scene::~Scene() {
    for (auto &object : _objects) {
        delete(object);
    }
    _objects.clear();
}
