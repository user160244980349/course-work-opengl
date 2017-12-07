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

    for (int i = -20; i < 20; i++) {
        for (int j = -20; j < 20; j++) {
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
