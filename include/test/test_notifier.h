//
// Created by user on 19.10.17.
//

#ifndef OPENGL_TEST_NOTIFIER_H
#define OPENGL_TEST_NOTIFIER_H


#include "notifier.h"

namespace application {

    class test_notifier : public notifier {
    public:
        int send() override;
        int send_to_all(int a);
    protected:
        int _a;
    };

}


#endif //OPENGL_TEST_NOTIFIER_H
