//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_SUBJECT_H
#define OPENGL_SUBJECT_H

#include "Interfaces&Abstractions/ObserverInterface.h"
#include <list>

namespace application::templates {

    class Subject {
    public:
        int subscribe(ObserverInterface* observer);
        int unsubscribe(ObserverInterface* observer);
        virtual int notify() = 0;
    protected:
        std::list<ObserverInterface*> _observers{};
    };

}


#endif //OPENGL_SUBJECT_H
