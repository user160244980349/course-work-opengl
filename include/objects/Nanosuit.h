//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_SASSOLDIR_H
#define OPENGL_SASSOLDIR_H

#include <interfaces/IDrawable.h>
#include <interfaces/IObject.h>
#include <interfaces/ICamera.h>
#include <core/Shader.h>
#include <core/Vao.h>
#include <core/Vbo.h>
#include <core/Ebo.h>
#include <vector>
#include <core/Mesh.h>
#include <core/Transform.h>
#include <core/Model.h>
#include "BaseObject.h"

class Nanosuit : public IDrawable, public BaseObject {
public:
    Transform transform;

    void prepare(Shader &shader) override;

    void render(Shader &shader) override;

    void update() override;

protected:
    Model _model;

};

#endif //OPENGL_SASSOLDIR_H
