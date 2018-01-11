//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_SASSOLDIR_H
#define OPENGL_SASSOLDIR_H

#include <interfaces/IDrawable.h>
#include <interfaces/IObject.h>
#include <interfaces/ICamera.h>
#include <core/ShaderProgram.h>
#include <core/Vao.h>
#include <core/Vbo.h>
#include <core/Ebo.h>
#include <vector>
#include <core/Mesh.h>
#include <core/Transform.h>
#include <core/Model.h>
#include "BaseObject.h"

class SASSoldier : public IDrawable, public BaseObject {
public:
    Transform transform;

    void prepare(ShaderProgram &shader) override;

    void render(ShaderProgram &shader) override;

    void update() override;

protected:
    Model _model;

};

#endif //OPENGL_SASSOLDIR_H
