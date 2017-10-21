//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_DRAWABLEINTERFACE_H
#define OPENGL_DRAWABLEINTERFACE_H

#include "AbstractCamera.h"

namespace application::test {

    class DrawableInterface {
    public:
        virtual int draw(AbstractCamera* camera) = 0;
        virtual int prepare() = 0;
    };

}


#endif //OPENGL_DRAWABLEINTERFACE_H
