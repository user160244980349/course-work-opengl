//
// Created by user on 27.10.2017.
//

#include <utility>

#include "objects/AObject.h"

unsigned int application::objects::AObject::_count = 0;

application::objects::AObject::AObject() {
    _id = _count;
    _count++;
    _name = "object" + std::to_string(_id);
}

application::objects::AObject::AObject(std::string name) {
    _id = _count;
    _count++;
    _name = std::move(name);
}

std::string application::objects::AObject::getName() {
    return _name;
}

int application::objects::AObject::getId() {
    return _id;
}
