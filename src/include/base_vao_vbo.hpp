//
// Created by user on 09.10.2017.
//

#ifndef OPENGL_BASE_VAO_VBO_HPP
#define OPENGL_BASE_VAO_VBO_HPP


#include <GL/glew.h>
#include <vector>
#include "vertex_3d.hpp"
#include "buffers_combo.hpp"
#include "abstract_video_buffers.hpp"

namespace application::graphics {

    class base_vao_vbo : public abstract_video_buffers {
    protected:
        std::vector<buffers_combo> buffers;

    public:
        ~base_vao_vbo();
        int new_buffer_combo(GLuint ds, vertex_3d *v, GLuint *o);
        int delete_buffer_combo(unsigned int n) override;
        int bind(unsigned int i, GLboolean warframe) override;
    };

}

#endif //OPENGL_VAO_VBO_HPP
