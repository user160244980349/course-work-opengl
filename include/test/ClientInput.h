//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_CLIENTINPUT_H
#define OPENGL_CLIENTINPUT_H


#include <SDL_events.h>
#include "InputInterface.h"
#include "Subject.h"

namespace application::test {

    class ClientInput : public InputInterface, Subject {
    public:
        int perform() override;
    protected:
        SDL_Event _event{};
    };

}


#endif //OPENGL_CLIENTINPUT_H
