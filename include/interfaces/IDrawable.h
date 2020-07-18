#ifndef OPENGL_DRAWABLEINTERFACE_H
#define OPENGL_DRAWABLEINTERFACE_H


#include "ICamera.h"
#include "../objects/SkyBox.h"

class IDrawable {
public:
    virtual ~IDrawable() = default;
    virtual void prepare(Shader &shader) = 0;
    virtual void render(Shader &shader, ICamera &camera) = 0;
};


#endif //OPENGL_DRAWABLEINTERFACE_H
