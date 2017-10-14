//
// Created by user on 14.10.2017.
//

#include "graphics/ubo.hpp"
#include <cstring>
#include <global_variables.hpp>

int application::graphics::ubo::create() {

    glGenBuffers(1, &id);

    return 0;
}

int application::graphics::ubo::connect(GLuint program) {

    GLuint block_index = glGetUniformBlockIndex(program, "shader_data");
    glBindBufferBase(GL_UNIFORM_BUFFER, 0, id);
    glUniformBlockBinding(program, block_index, 0);

    return 0;
}

int application::graphics::ubo::set() {

    glBindBuffer(GL_UNIFORM_BUFFER, id);
    glBufferData(GL_UNIFORM_BUFFER, sizeof(shader_data), &shader_data, GL_DYNAMIC_DRAW);

    return 0;
}

int application::graphics::ubo::update() {

//    (float)sin(time::world_time.time/1000.0)*

    shader_data.projection = glm::perspective(glm::radians(((float)sin(time::world_time.time/1000.0)+1)*70.0f), 4.0f / 3.0f, 0.1f, 100.0f);

    GLvoid* p = glMapBuffer(GL_UNIFORM_BUFFER, GL_WRITE_ONLY);
    memcpy(p, &shader_data, sizeof(shader_data));
    glUnmapBuffer(GL_UNIFORM_BUFFER);

    return 0;
}
