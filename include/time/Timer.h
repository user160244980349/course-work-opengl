//
// Created by user on 08.10.2017.
//

#ifndef OPENGL_TIMER_H
#define OPENGL_TIMER_H


#include "AbstractTimer.h"

namespace application::time {

    class Timer : public AbstractTimer {
    public:
        int reset();
        int run() override;
        int stop() override;

    protected:
        bool _running;

        static int _detach(bool &_running, Uint32 &time){
            while (_running)
                time = SDL_GetTicks();
            return 0;
        };
    };

}

#endif //OPENGL_TIMER_H
