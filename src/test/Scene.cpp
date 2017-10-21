//
// Created by user on 20.10.2017.
//

#include <test/Cube.h>
#include "test/Scene.h"

int application::test::Scene::prepare() {

    for (auto &object : _objects) {
        object->prepare();
    }

    return 0;
}

int application::test::Scene::draw() {

    for (auto &object : _objects)
        object->draw(_camera);

    return 0;
}

application::test::Scene::Scene(Subject* subject) {

    _subject = subject;
    _camera = new Camera;

    _objects.emplace_back(new application::test::Cube);

}
