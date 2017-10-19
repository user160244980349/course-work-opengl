//
// Created by user on 19.10.17.
//

#ifndef OPENGL_NOTIFIER_H
#define OPENGL_NOTIFIER_H


#include "observer.h"
#include <list>

namespace application {

    class notifier {
    protected:
        std::list<observer*> observers;
    public:
        int add(observer* o);
        int remove(observer* o);
        virtual int send() = 0;
    };

}


#endif //OPENGL_NOTIFIER_H
