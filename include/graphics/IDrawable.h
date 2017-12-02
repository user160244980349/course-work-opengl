//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_DRAWABLEINTERFACE_H
#define OPENGL_DRAWABLEINTERFACE_H

#include "objects/ICamera.h"


class IDrawable {
public:
    virtual int draw() = 0;
    virtual int setCamera(ICamera& camera) = 0;
};


#endif //OPENGL_DRAWABLEINTERFACE_H
