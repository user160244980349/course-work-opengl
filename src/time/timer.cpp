//
// Created by user on 08.10.2017.
//

#include "time/timer.hpp"
#include <thread>

int application::time::timer::run() {

    if (!running) {
        running = true;
        std::thread timer_thread(detach, std::ref(running), std::ref(time));
        timer_thread.detach();
    }

    return 0;
}

int application::time::timer::reset() {
    time = 0;
    return 0;
}

int application::time::timer::stop() {
    running = false;
    return 0;
}
