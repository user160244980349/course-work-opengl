//
// Created by user on 20.10.2017.
//

#include <objects/Cube.h>
#include <objects/DynamicCamera.h>
#include "graphics/Scene.h"

int application::graphics::Scene::prepare() {

//    _subject->subscribe(_camera);

    _objects.emplace_back(new objects::Cube);

    for (auto &object : _objects) {
        object->prepare();
    }

    return 0;
}

int application::graphics::Scene::draw() {

    for (auto &object : _objects)
        object->draw(_camera);

    return 0;
}

application::graphics::Scene::Scene(templates::Subject* subject) {

    _subject = subject;
    _camera = new objects::DynamicCamera;

}
