//
// Created by user on 31.10.2017.
//

#include "input/AControlable.h"

std::list<IInputCommand*> AControlable::getCommands() {
    return _commands;
}
