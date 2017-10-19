//
// Created by user on 20.10.2017.
//

#include "test/Subject.h"

int application::test::Subject::subscribe(ObserverInterface* observer) {
    _observers.emplace_back(observer);
    return 0;
}

int application::test::Subject::unsubscribe(ObserverInterface* observer) {
    _observers.remove(observer);
    return 0;
}
