//
// Created by user on 30.10.2017.
//

#ifndef OPENGL_ACONTROLABLE_H
#define OPENGL_ACONTROLABLE_H

#include <interfaces/IInputCommand.h>
#include <interfaces/IControlable.h>
#include <list>

namespace application::input {

    class AControlable : public interfaces::IControlable {
    public:
        std::list<interfaces::IInputCommand*> getCommands() final;

    protected:
        std::list<interfaces::IInputCommand*> _commands;
    };

}

#endif //OPENGL_ACONTROLABLE_H
