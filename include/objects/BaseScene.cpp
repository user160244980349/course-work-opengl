//
// Created by user on 21.12.2017.
//

#include "BaseScene.h"

unsigned int BaseScene::_count = 0;

BaseScene::BaseScene() {
    _id = _count;
    _count++;
    _name = "scene" + std::to_string(_id);
}

BaseScene::BaseScene(std::string name) {
    _id = _count;
    _count++;
    _name = std::move(name);
}

std::string BaseScene::getName() {
    return _name;
}

unsigned int BaseScene::getId() {
    return _id;
}