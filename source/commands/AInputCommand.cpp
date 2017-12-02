//
// Created by user on 27.11.2017.
//

#include <input/ClientInput.h>
#include "commands/AInputCommand.h"

AInputCommand::AInputCommand(IControlable *o) {
    _object = o;
    ClientInput::getInstance().addCommand(this);
}
