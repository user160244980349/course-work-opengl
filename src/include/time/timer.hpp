//
// Created by user on 08.10.2017.
//

#ifndef OPENGL_TIMER_HPP
#define OPENGL_TIMER_HPP


#include "abstract_timer.hpp"

namespace application::time {

    class timer : public abstract_timer {

    protected:
        bool running;

        static int detach(bool &running, Uint32 &time){
            while (running)
                time = SDL_GetTicks();
            return 0;
        };

    public:

        int reset();
        int run() override;
        int stop() override;
    };

}

#endif //OPENGL_TIMER_HPP
