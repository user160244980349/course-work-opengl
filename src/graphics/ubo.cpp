//
// Created by user on 14.10.2017.
//

#include "graphics/ubo.h"
#include <cstring>


application::graphics::ubo::~ubo() {

    glDeleteBuffers(1, &id);

}



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



int application::graphics::ubo::set(GLvoid *data, GLuint size) {

    glBindBuffer(GL_UNIFORM_BUFFER, id);
    glBufferData(GL_UNIFORM_BUFFER, size, data, GL_DYNAMIC_DRAW);

    return 0;
}



int application::graphics::ubo::update(GLvoid *data, GLuint size) {

    GLvoid* p = glMapBuffer(GL_UNIFORM_BUFFER, GL_WRITE_ONLY);
    memcpy(p, data, size);
    glUnmapBuffer(GL_UNIFORM_BUFFER);

    return 0;
}
