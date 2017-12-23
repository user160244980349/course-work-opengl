//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_CUBE_H
#define OPENGL_CUBE_H

#include <interfaces/IDrawable.h>
#include <interfaces/IObject.h>
#include <interfaces/ICamera.h>
#include <graphics/ShaderProgram.h>
#include <graphics/Vao.h>
#include <graphics/Vbo.h>
#include <graphics/Ebo.h>
#include <vector>
#include <components/CubeMesh.h>
#include <components/Transform.h>
#include "BaseObject.h"

class Cube : public IDrawable, public BaseObject {
public:
    Cube();

    void update() override;

    void render(ICamera &camera) override;

    Transform transform;

protected:

    CubeMesh _mesh;
    ShaderProgram _shaderProgram;
};

#endif //OPENGL_CUBE_H
