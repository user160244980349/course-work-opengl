//
// Created by user on 27.11.2017.
//

#include "commands/AInputCommand.h"

application::commands::AInputCommand::AInputCommand(application::input::IControlable *o) {
    _object = o;
}
