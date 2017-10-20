//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_CLIENTINPUT_H
#define OPENGL_CLIENTINPUT_H


#include <SDL_events.h>
#include "ClientInputInterface.h"

namespace application::test {

    class ClientInput : public ClientInputInterface {
    public:
        int perform() override;
        int notify() override;
    protected:
        SDL_Event _event{};
    };

}


#endif //OPENGL_CLIENTINPUT_H
