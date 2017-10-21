//
// Created by user on 20.10.2017.
//

#include "Interfaces&Abstractions/Subject.h"

int application::templates::Subject::subscribe(ObserverInterface* observer) {
    _observers.push_back(observer);
    return 0;
}

int application::templates::Subject::unsubscribe(ObserverInterface* observer) {
    _observers.remove(observer);
    return 0;
}
