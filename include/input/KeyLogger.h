//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_KEYLOGGER_H
#define OPENGL_KEYLOGGER_H

#include <Interfaces&Abstractions/ObserverInterface.h>
#include <Interfaces&Abstractions/Subject.h>

namespace application::input {

    class KeyLogger : public templates::ObserverInterface {
    public:
        int update(SDL_Event event) override;
    };

}


#endif //OPENGL_KEYLOGGER_H
