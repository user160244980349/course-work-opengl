//
// Created by user on 30.10.2017.
//

#ifndef OPENGL_ACONTROLABLE_H
#define OPENGL_ACONTROLABLE_H

#include <commands/IInputCommand.h>
#include <input/IControlable.h>
#include <list>


class AControlable : public IControlable {
public:
    std::list<IInputCommand*> getCommands() final;

protected:
    std::list<IInputCommand*> _commands;
};


#endif //OPENGL_ACONTROLABLE_H
