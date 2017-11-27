//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_ABSTRACTOBJECT_H
#define OPENGL_ABSTRACTOBJECT_H

#include <graphics/Vao.h>
#include <graphics/Vbo.h>
#include <graphics/Ubo.h>
#include <graphics/Ebo.h>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <graphics/Shader.h>


class IObject {
public:
    virtual std::string getName() = 0;
    virtual int getId() = 0;
    virtual int update() = 0;
};


#endif //OPENGL_ABSTRACTOBJECT_H
