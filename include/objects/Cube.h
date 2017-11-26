//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_CUBE_H
#define OPENGL_CUBE_H

#include <graphics/IDrawable.h>
#include <objects/IObject.h>
#include <objects/ICamera.h>
#include <input/AControlable.h>
#include "AObject.h"

namespace application::objects {

    class Cube : public graphics::IDrawable, public objects::AObject, public input::AControlable {
    public:
        int setCamera(objects::ICamera* camera) override;
        int prepare() override;
        int update() override;
        int draw() override;
        int warframe();
        int initCommands() override;

    protected:
        struct {
            graphics::Vao vao;
            graphics::Vbo vbo;
            graphics::Ebo ebo;
            graphics::Ubo ubo;
        } _buffers;

        struct {
            glm::mat4 model = glm::mat4(1.0f);
        } _transform;

        std::vector <graphics::Shader> _shaders{};
        std::vector <graphics::Vertex3d> _vertices{};
        std::vector <GLuint> _order{};

        bool _warframe = true;
    };

}

#endif //OPENGL_CUBE_H
