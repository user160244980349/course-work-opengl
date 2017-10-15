//
// Created by user on 09.10.2017.
//

#ifndef OPENGL_BASE_OBJECT_HPP
#define OPENGL_BASE_OBJECT_HPP

#include <vector>
#include <graphics/ubo.hpp>
#include "abstract_object.hpp"
#include "graphics/shader.hpp"
#include "graphics/vertex_3d.hpp"
#include "graphics/vao.hpp"
#include "graphics/vbo.hpp"
#include "graphics/ebo.hpp"
#include "drawable.hpp"
#include <global_variables.hpp>
#include <glm/gtc/matrix_transform.hpp>


namespace application::objects {

    class base_object : public abstract_object, drawable {
    protected:

        struct {
            graphics::vao vao;
            graphics::vbo vbo;
            graphics::ebo ebo;
            graphics::ubo ubo;
        } buffers;

        struct {
            glm::mat4 perspective = graphics::perspective;
            glm::mat4 view = glm::lookAt(
                    glm::vec3(4,2,3),
                    glm::vec3(0,0,0),
                    glm::vec3(0,1,0)
            );
            glm::mat4 model = glm::mat4(1.0f);
        } transform;

        std::vector<graphics::vertex_3d> vertices;
        std::vector<GLuint> order;
        std::vector<graphics::shader> shaders;

    public:

        int prepare() override;
        int draw() override;
        int rotate();
    };

}


#endif //OPENGL_BASE_OBJECT_HPP
