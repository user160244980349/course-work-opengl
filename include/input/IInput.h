//
// Created by user on 22.10.2017.
//

#ifndef OPENGL_IINPUT_H
#define OPENGL_IINPUT_H

#include "IControlable.h"

namespace application::input {

    class IInput {
    public:
        virtual int perform() = 0;
        virtual int addCommands(std::list<commands::IInputCommand*> commands) = 0;
    };

}

#endif //OPENGL_IINPUT_H