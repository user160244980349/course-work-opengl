//
// Created by user on 14.10.2017.
//

#ifndef OPENGL_UBO_HPP
#define OPENGL_UBO_HPP


#include <glm/mat4x4.hpp>
#include <graphics/abstract_buffer.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace application::graphics {

    class ubo : public abstract_buffer {
    protected:

        struct {
            glm::mat4 projection = glm::perspective(glm::radians(70.0f), 4.0f / 3.0f, 0.1f, 100.0f);
            glm::mat4 view = glm::lookAt(
                    glm::vec3(4,4,3),
                    glm::vec3(0,0,0),
                    glm::vec3(0,1,0)
            );
            glm::mat4 model = glm::mat4(1.0f);
        } shader_data;

    public:

        int create() override;
        int set();
        int update();
        int connect(GLuint program);
    };

}


#endif //OPENGL_UBO_HPP
