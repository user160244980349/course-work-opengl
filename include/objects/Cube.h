//
// Created by user on 12.01.2018.
//

#ifndef OPENGL_CUBE_H
#define OPENGL_CUBE_H


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

class Cube : public IDrawable, public BaseObject {
public:

    void prepare(Shader &shader) override;

    void render(Shader &shader) override;

    void update() override;

protected:
    Model _model;

};


#endif //OPENGL_FLOOR_H
