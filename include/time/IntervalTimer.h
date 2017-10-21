//
// Created by user on 08.10.2017.
//

#ifndef OPENGL_INTERVAL_TIMER_H
#define OPENGL_INTERVAL_TIMER_H


#include "AbstractTimer.h"

namespace application::time {

    class IntervalTimer : public ITimer {
    public:
        bool fired;
        Uint32 time;

        int set(float i);
        int reset();
        int run() override;
        int stop() override;

    protected:
        Uint32 _interval;
        bool _running;

        static int _detach(bool &_running, Uint32 &time, bool &fired, Uint32 interval){
            time = SDL_GetTicks();
            Uint32 last_time = time;
            while (_running) {
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
    };

}

#endif //OPENGL_TIMER_H
