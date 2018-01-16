//
// Created by user on 16.01.2018.
//

#ifndef OPENGL_SHADOWMAP_H
#define OPENGL_SHADOWMAP_H


#include <interfaces/IScene.h>
#include "Fbo.h"

class ShadowMap {
public:

    void prepare();

    void bind();

    void buildMap(DirectionalLight &light, Shader &shader);

protected:
    unsigned int _id;
    Fbo _fbo;

};


#endif //OPENGL_SHADOWMAP_H
