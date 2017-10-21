//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_DRAWABLEINTERFACE_H
#define OPENGL_DRAWABLEINTERFACE_H

#include "AbstractCamera.h"

namespace application::graphics {

    class DrawableInterface {
    public:
        virtual int draw(objects::AbstractCamera* camera) = 0;
        virtual int prepare() = 0;
    };

}


#endif //OPENGL_DRAWABLEINTERFACE_H
