//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_OBSERVERINTERFACE_H
#define OPENGL_OBSERVERINTERFACE_H


#include <SDL_events.h>

namespace application::templates {

    class ObserverInterface {
    public:
        virtual int update(SDL_Event event) = 0;
    };

}


#endif //OPENGL_OBSERVERINTERFACE_H
