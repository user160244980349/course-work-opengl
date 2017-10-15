//
// Created by user on 08.10.2017.
//

#ifndef OPENGL_TIMER_HPP
#define OPENGL_TIMER_HPP


#include "abstract_timer.hpp"

namespace application::time {

    class timer : public abstract_timer {
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

#endif //OPENGL_TIMER_HPP
