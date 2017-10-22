//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_CLIENTINPUT_H
#define OPENGL_CLIENTINPUT_H


#include <SDL_events.h>
#include <list>
#include <interfaces/IInput.h>
#include <interfaces/IControlable.h>

namespace application::input {

    class ClientInput : public IInput {
    public:
        int perform() override;
        int notify() override;
        int subscribe(IControlable* observer) override;
        int unsubscribe(IControlable* observer) override;
    protected:
        std::list<IControlable*> _observers{};
        SDL_Event _event{};
    };

}


#endif //OPENGL_CLIENTINPUT_H
