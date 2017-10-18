//
// Created by user on 08.10.2017.
//

#include "time/timer.h"
#include <thread>

int application::time::timer::run() {

    if (!_running) {
        _running = true;
        std::thread timer_thread(_detach, std::ref(_running), std::ref(time));
        timer_thread.detach();
    }

    return 0;
}



int application::time::timer::reset() {
    time = 0;
    return 0;
}



int application::time::timer::stop() {
    _running = false;
    return 0;
}
