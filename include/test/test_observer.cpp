//
// Created by user on 19.10.17.
//

#include <iostream>
#include "test_observer.h"

int application::test_observer::recieve(int a) {
    std::cout << a <<std::endl;
    return 0;
}
