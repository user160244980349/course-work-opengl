//
// Created by user on 27.11.2017.
//

#include <input/UserInput.h>
#include "commands/AInputCommand.h"

AInputCommand::AInputCommand(IControlable *o) {
    _object = o;
    UserInput::getInstance().addCommand(this);
}
