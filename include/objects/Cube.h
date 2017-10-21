//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_CUBE_H
#define OPENGL_CUBE_H


#include <interfaces&abstractions/IDrawable.h>
#include <interfaces&abstractions/IObject.h>
#include <interfaces&abstractions/ICamera.h>

namespace application::objects {

    class Cube : public graphics::IDrawable, public objects::IObject {
    public:
        int prepare() override;
        int draw(ICamera* camera) override;

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

        std::vector <graphics::Vertex3d> _vertices{};
        std::vector <GLuint> _order{};
        std::vector <graphics::Shader> _shaders{};
    };

}


#endif //OPENGL_CUBE_H
