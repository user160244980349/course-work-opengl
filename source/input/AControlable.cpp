//
// Created by user on 31.10.2017.
//

#include "input/AControlable.h"

std::list<application::commands::IInputCommand*> application::input::AControlable::getCommands() {
    return _commands;
}
