//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_CUBE_H
#define OPENGL_CUBE_H

#include <graphics/IDrawable.h>
#include <objects/IObject.h>
#include <objects/ICamera.h>
#include "AObject.h"


class Cube : public IDrawable, public AObject {
public:
    Cube();
    virtual ~Cube() override;

    int setCamera(ICamera& camera) override;
    int update() override;
    int draw() override;
    int translate(glm::vec3 position);

protected:
    struct {
        Vao vao;
        Vbo vbo;
        Ebo ebo;
        Ubo ubo;
    } _buffers;

    struct {
        glm::mat4 model = glm::mat4(1.0f);
    } _transform;

    std::vector <Shader> _shaders{};
    std::vector <glm::vec3> _vertices{};
    std::vector <GLuint> _order{};
};


#endif //OPENGL_CUBE_H
