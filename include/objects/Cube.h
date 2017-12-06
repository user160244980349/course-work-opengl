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
#include "BaseObject.h"

class Cube : public IDrawable, public BaseObject {
public:
    Cube();
    virtual ~Cube() override;

    int update() override;
    int draw(ICamera &camera) override;
    int translate(glm::vec3 position);

protected:
    struct {
        Vao vao;
        Vbo vbo;
        Ebo ebo;
    } _buffers;

    struct {
        glm::mat4 model = glm::mat4(1.0f);
    } _transform;

    ShaderProgram _shaderProgram;
    std::vector <glm::vec3> _vertices{};
    std::vector <GLuint> _order{};
};


#endif //OPENGL_CUBE_H
