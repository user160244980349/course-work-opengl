//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_CLIENTINPUT_H
#define OPENGL_CLIENTINPUT_H

#include <SDL2/SDL_events.h>
#include <list>
#include <input/IInput.h>
#include <input/IControlable.h>

namespace application::input {

    class ClientInput : public input::IInput {
    public:
        ClientInput();
        int perform() override;
        int addCommands(std::list<commands::IInputCommand*> commands) override;
    protected:
        std::list<commands::IInputCommand*> _commands;
        SDL_Event _event{};
    };

}

#endif //OPENGL_CLIENTINPUT_H
