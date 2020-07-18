#ifndef OPENGL_DRAWABLEINTERFACE_H
#define OPENGL_DRAWABLEINTERFACE_H


#include "ICamera.h"
#include "../objects/SkyBox.h"

class IDrawable {
public:
    virtual ~IDrawable() = default;
    virtual void prepare(Shader &shader) {};
    virtual void render(Shader &shader, ICamera &camera) {};
};


#endif //OPENGL_DRAWABLEINTERFACE_H
