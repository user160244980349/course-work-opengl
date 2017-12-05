//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_ABSTRACTOBJECT_H
#define OPENGL_ABSTRACTOBJECT_H

#include <graphics/Vao.h>
#include <graphics/Vbo.h>
#include <graphics/Ebo.h>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <graphics/Shader.h>
#include <string>


class IObject {
public:
    virtual ~IObject() {};
    virtual std::string getName() {};
    virtual int getId() {};
    virtual int update() {};
};


#endif //OPENGL_ABSTRACTOBJECT_H
