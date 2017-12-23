//
// Created by user on 20.10.2017.
//

#include <objects/Cube.h>
#include <objects/DynamicCamera.h>
#include "objects/CubeScene.h"


CubeScene::CubeScene() {

    _objects.push_back(new Cube);

}

CubeScene::~CubeScene() {
    for (auto &object : _objects) {
        delete (object);
    }
    _objects.clear();
}

void CubeScene::render() {

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

void CubeScene::update() {
    for (auto &object : _objects) {
        object->update();
    }
}
