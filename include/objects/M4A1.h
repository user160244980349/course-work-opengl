//
// Created by user on 12.01.2018.
//

#ifndef OPENGL_FLOOR_H
#define OPENGL_FLOOR_H


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

class M4A1 : public IDrawable, public BaseObject {
public:
    Transform transform;

    void prepare(ShaderProgram &shader) override;

    void render(ShaderProgram &shader) override;

    void update() override;

protected:
    Model _model;

};


#endif //OPENGL_FLOOR_H
