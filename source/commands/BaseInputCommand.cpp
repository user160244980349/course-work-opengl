//
// Created by user on 27.11.2017.
//

#include <input/UserInput.h>
#include "commands/BaseInputCommand.h"

BaseInputCommand::BaseInputCommand(IControlable &object) : _object(object) {}

void BaseInputCommand::execute(SDL_Event event) {}
