//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_CLIENTINPUT_H
#define OPENGL_CLIENTINPUT_H

#include <SDL2/SDL_events.h>
#include <list>
#include <interfaces/IInput.h>
#include <interfaces/IControlable.h>

namespace application::input {

    class ClientInput : public interfaces::IInput {
    public:
        ClientInput();
        int perform() override;
        int addCommands(std::list<interfaces::IInputCommand*> commands) override;
    protected:
        std::list<interfaces::IInputCommand*> _commands;
        SDL_Event _event{};
    };

}

#endif //OPENGL_CLIENTINPUT_H
