//
// Created by user on 19.10.17.
//

#ifndef OPENGL_TEST_OBSERVER_H
#define OPENGL_TEST_OBSERVER_H


#include "observer.h"

namespace application {

    class test_observer : public observer {
    public:
        int recieve(int a) override;
    };

}


#endif //OPENGL_TEST_OBSERVER_H
