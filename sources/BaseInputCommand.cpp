#include "../include/core/UserInput.h"
#include "../include/commands/BaseInputCommand.h"

BaseInputCommand::BaseInputCommand(IControlable &object) : _object(object) {}
