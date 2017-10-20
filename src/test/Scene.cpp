//
// Created by user on 20.10.2017.
//

#include <GL/glew.h>
#include <objects/base_object.h>
#include "test/Scene.h"

int application::test::Scene::prepare() {

    for (auto &object : _objects)
        object->prepare();

    return 0;
}

int application::test::Scene::draw() {

    for (auto &object : _objects)
        object->draw();

    return 0;
}

application::test::Scene::Scene(Subject* subject) {

    _subject = subject;

    _objects.emplace_back(new application::objects::base_object);

}
