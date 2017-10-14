//
// Created by user on 08.10.2017.
//

#ifndef OPENGL_INTERVAL_TIMER_HPP
#define OPENGL_INTERVAL_TIMER_HPP


#include "abstract_timer.hpp"

namespace application::time {

    class interval_timer : public abstract_timer {

    protected:
        Uint32 interval;
        bool running;

        static int detach(bool &running, Uint32 &time, bool &fired, Uint32 interval){
            time = SDL_GetTicks();
            Uint32 last_time = time;
            while (running) {
                if (!fired) {
                    time = SDL_GetTicks();
                    if (interval < time - last_time) {
                        last_time = time;
                        fired = true;
                    }
                }
            }
            return 0;
        };

    public:
        bool fired;

        int set(float i);
        int reset();
        int run() override;
        int stop() override;
    };

}

#endif //OPENGL_TIMER_HPP
