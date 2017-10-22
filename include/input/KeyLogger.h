//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_KEYLOGGER_H
#define OPENGL_KEYLOGGER_H


#include <SDL_events.h>
#include <interfaces/IControlable.h>

namespace application::input {

    class KeyLogger : public input::IControlable {
    public:
        int controlResponse(SDL_Event event) override;
    };

}


#endif //OPENGL_KEYLOGGER_H
