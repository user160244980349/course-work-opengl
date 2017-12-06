//
// Created by user on 27.10.2017.
//

#include "objects/BaseObject.h"

unsigned int BaseObject::_count = 0;

BaseObject::BaseObject() {
    _id = _count;
    _count++;
    _name = "object" + std::to_string(_id);
}

BaseObject::~BaseObject() = default;

BaseObject::BaseObject(std::string name) {
    _id = _count;
    _count++;
    _name = std::move(name);
}

std::string BaseObject::getName() {
    return _name;
}

int BaseObject::getId() {
    return _id;
}

