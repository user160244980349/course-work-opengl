//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_SUBJECT_H
#define OPENGL_SUBJECT_H

#include "Interfaces&Abstractions/IObserver.h"

namespace application::templates {

    class ISubject {
    public:
        virtual int subscribe(IObserver* observer) = 0;
        virtual int unsubscribe(IObserver* observer) = 0;
        virtual int notify() = 0;
    };

}


#endif //OPENGL_SUBJECT_H
