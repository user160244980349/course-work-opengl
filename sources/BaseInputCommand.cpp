//
// Created by user on 27.11.2017.
//

#include <core/UserInput.h>
#include "commands/BaseInputCommand.h"

BaseInputCommand::BaseInputCommand(IControlable &object) : _object(object) {}

