//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_CLIENTINPUT_H
#define OPENGL_CLIENTINPUT_H


#include <SDL_events.h>
#include <list>
#include <interfaces&abstractions/IClientInput.h>
#include <interfaces&abstractions/IObserver.h>

namespace application::input {

    class ClientInput : public IClientInput {
    public:
        int perform() override;
        int notify() override;
        int subscribe(templates::IObserver* observer) override;
        int unsubscribe(templates::IObserver* observer) override;
    protected:
        std::list<templates::IObserver*> _observers{};
        SDL_Event _event{};
    };

}


#endif //OPENGL_CLIENTINPUT_H
