//
// Created by user on 16.01.2018.
//

#ifndef OPENGL_SHADOWMAP_H
#define OPENGL_SHADOWMAP_H


#include <interfaces/IScene.h>
#include "Fbo.h"
#include "Shader.h"

class ShadowMap {
public:

    void prepare();

    void bind(Shader &shader);

    void bindForBuild(Shader &shader);

    void unbind();

    unsigned int getId();

protected:
    unsigned int _id;
    unsigned int _fbo;

};


#endif //OPENGL_SHADOWMAP_H
