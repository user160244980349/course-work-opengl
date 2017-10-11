//
// Created by user on 08.10.2017.
//

#include <SDL2/SDL_timer.h>
#include "application/timer.hpp"
#include <thread>

int application::timer::set(float i) {

    interval = (Uint32)(i * 1000);
    fired = false;

}

int application::timer::run() {

    if (!running) {
        running = true;
        std::thread time(detach, std::ref(running), std::ref(fired), interval);
        time.detach();
    }

    return 0;
}

int application::timer::reset() {
    fired = false;
    return 0;
}

int application::timer::stop() {
    running = false;
    return 0;
}

