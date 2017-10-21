//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_SUBJECT_H
#define OPENGL_SUBJECT_H

#include "Interfaces&Abstractions/ObserverInterface.h"

namespace application::templates {

    class SubjectInterface {
    public:
        virtual int subscribe(ObserverInterface* observer) = 0;
        virtual int unsubscribe(ObserverInterface* observer) = 0;
        virtual int notify() = 0;
    };

}


#endif //OPENGL_SUBJECT_H
