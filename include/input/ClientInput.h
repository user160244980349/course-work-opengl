//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_CLIENTINPUT_H
#define OPENGL_CLIENTINPUT_H


#include <SDL_events.h>
#include <Interfaces&Abstractions/ObserverInterface.h>
#include "Interfaces&Abstractions/ClientInputInterface.h"
#include <list>

namespace application::input {

    class ClientInput : public ClientInputInterface {
    public:
        int perform() override;
        int notify() override;
        int subscribe(templates::ObserverInterface* observer) override;
        int unsubscribe(templates::ObserverInterface* observer) override;
    protected:
        std::list<templates::ObserverInterface*> _observers{};
        SDL_Event _event{};
    };

}


#endif //OPENGL_CLIENTINPUT_H
