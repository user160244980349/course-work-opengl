//
// Created by user on 19.10.17.
//

#include "test_notifier.h"

int application::test_notifier::send_to_all(int a) {
    _a = a;
    send();
    return 0;
}

int application::test_notifier::send() {
    std::list<observer*>::iterator it;
    for (it = observers.begin(); it != observers.end(); it++)
        (*it)->recieve(_a);
    return 0;
}
