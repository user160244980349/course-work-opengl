//
// Created by user on 14.10.2017.
//

#include "graphics/Ubo.h"


application::graphics::Ubo::~ubo() {

    glDeleteBuffers(1, &id);

}



int application::graphics::Ubo::create() {

    glGenBuffers(1, &id);

    return 0;
}



int application::graphics::Ubo::connect(GLuint program, GLuint bindIndex, std::string blockName) {

    GLuint blockIndex = glGetUniformBlockIndex(program, blockName.c_str());
    glBindBufferBase(GL_UNIFORM_BUFFER, bindIndex, id);
    glUniformBlockBinding(program, blockIndex, bindIndex);

    return 0;
}



int application::graphics::Ubo::set(GLvoid *data, GLuint size) {

    glBindBuffer(GL_UNIFORM_BUFFER, id);
    glBufferData(GL_UNIFORM_BUFFER, size, data, GL_DYNAMIC_DRAW);

    return 0;
}



int application::graphics::Ubo::update(GLvoid *data, GLuint size) {

    glBindBuffer(GL_UNIFORM_BUFFER, id);
    GLvoid* p = glMapBuffer(GL_UNIFORM_BUFFER, GL_WRITE_ONLY);
    memcpy(p, data, size);
    glUnmapBuffer(GL_UNIFORM_BUFFER);

    return 0;
}