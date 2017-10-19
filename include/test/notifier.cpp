//
// Created by user on 19.10.17.
//
#include "notifier.h"


int application::notifier::add(observer* o) {
    observers.emplace_back(o);
    return 0;
}

int application::notifier::remove(application::observer* o) {
    observers.remove(o);
    return 0;
}
