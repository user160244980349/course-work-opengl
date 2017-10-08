//
// Created by user on 08.10.2017.
//

#ifndef OPENGL_TIMER_HPP
#define OPENGL_TIMER_HPP

#include <SDL_events.h>

namespace application {

    class timer {

    private:
        Uint32 interval;
        bool running;

        static int detach(bool &running, bool &fired, Uint32 interval){
            Uint32 last_time = SDL_GetTicks();
            Uint32 current_time = last_time;
            while (running) {
                if (!fired) {
                    current_time = SDL_GetTicks();
                    if (interval < current_time - last_time) {
                        last_time = current_time;
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
        int run();
        int stop();
    };

}

#endif //OPENGL_TIMER_HPP
