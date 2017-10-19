//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_KEYLOGGER_H
#define OPENGL_KEYLOGGER_H

#include <test/ObserverInterface.h>
#include <test/Subject.h>

namespace application::test {

    class KeyLogger : public ObserverInterface {
    public:
        explicit KeyLogger(Subject* subject);
        int update(SDL_Event event) override;
    };

}


#endif //OPENGL_KEYLOGGER_H
