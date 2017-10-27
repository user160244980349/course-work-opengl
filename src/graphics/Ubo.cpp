//
// Created by user on 14.10.2017.
//

#include <graphics/OpenGl.h>
#include "graphics/Ubo.h"

application::graphics::Ubo::~Ubo() {

    OpenGl::getInstance()->glDeleteBuffers(1, &id);

}

int application::graphics::Ubo::create() {

    OpenGl::getInstance()->glGenBuffers(1, &id);

    return 0;
}

int application::graphics::Ubo::connect(GLuint program, UboBindIndex bindIndex, std::string blockName) {

    OpenGl::getInstance()->glBindBuffer(GL_UNIFORM_BUFFER, id);
    GLuint blockIndex = OpenGl::getInstance()->glGetUniformBlockIndex(program, blockName.c_str());
    OpenGl::getInstance()->glBindBufferBase(GL_UNIFORM_BUFFER, bindIndex, id);
    OpenGl::getInstance()->glUniformBlockBinding(program, blockIndex, bindIndex);

    return 0;
}

int application::graphics::Ubo::set(GLvoid *data, GLuint size) {

    OpenGl::getInstance()->glBindBuffer(GL_UNIFORM_BUFFER, id);
    OpenGl::getInstance()->glBufferData(GL_UNIFORM_BUFFER, size, data, GL_DYNAMIC_DRAW);

    return 0;
}

int application::graphics::Ubo::update(GLvoid *data, GLuint size) {

    OpenGl::getInstance()->glBindBuffer(GL_UNIFORM_BUFFER, id);
    GLvoid* p = OpenGl::getInstance()->glMapBuffer(GL_UNIFORM_BUFFER, GL_WRITE_ONLY);
    memcpy(p, data, size);
    OpenGl::getInstance()->glUnmapBuffer(GL_UNIFORM_BUFFER);

    return 0;
}
