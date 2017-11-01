//
// Created by user on 30.10.2017.
//

#ifndef OPENGL_ACONTROLABLE_H
#define OPENGL_ACONTROLABLE_H

#include <commands/IInputCommand.h>
#include <input/IControlable.h>
#include <list>

namespace application::input {

    class AControlable : public input::IControlable {
    public:
        std::list<commands::IInputCommand*> getCommands() final;

    protected:
        std::list<commands::IInputCommand*> _commands;
    };

}

#endif //OPENGL_ACONTROLABLE_H
