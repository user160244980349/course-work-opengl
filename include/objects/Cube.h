//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_CUBE_H
#define OPENGL_CUBE_H

#include <interfaces/IDrawable.h>
#include <interfaces/IObject.h>
#include <interfaces/ICamera.h>
#include <interfaces/IControlable.h>
#include "AObject.h"

namespace application::objects {

    class Cube : public graphics::IDrawable, public objects::AObject, public input::IControlable {
    public:
        int draw() override;
        int prepare() override;
        int setCamera(ICamera* camera) override;
        int control(SDL_Event event) override;

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
