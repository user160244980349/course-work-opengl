//
// Created by user on 08.10.2017.
//

#include "time/interval_timer.hpp"
#include <thread>

int application::time::interval_timer::set(float i) {

    _interval = (Uint32)(i * 1000);
    fired = false;

}



int application::time::interval_timer::run() {

    if (!_running) {
        _running = true;
        std::thread timer_thread(_detach, std::ref(_running), std::ref(time), std::ref(fired), _interval);
        timer_thread.detach();
    }

    return 0;
}



int application::time::interval_timer::reset() {
    time = 0;
    fired = false;
    return 0;
}



int application::time::interval_timer::stop() {
    _running = false;
    return 0;
}

