//
// Created by user on 27.10.2017.
//

#include "objects/AObject.h"

unsigned int AObject::_count = 0;

AObject::AObject() {
    _id = _count;
    _count++;
    _name = "object" + std::to_string(_id);
}

AObject::AObject(std::string name) {
    _id = _count;
    _count++;
    _name = std::move(name);
}

std::string AObject::getName() {
    return _name;
}

int AObject::getId() {
    return _id;
}
