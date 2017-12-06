//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_DRAWABLEINTERFACE_H
#define OPENGL_DRAWABLEINTERFACE_H

#include "ICamera.h"


class IDrawable {
public:
    virtual int draw(ICamera &camera) {};
};


#endif //OPENGL_DRAWABLEINTERFACE_H
