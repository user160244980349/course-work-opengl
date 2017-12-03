//
// Created by user on 14.10.2017.
//

#include <graphics/OpenGl.h>
#include <cstring>
#include "graphics/Ubo.h"

Ubo::~Ubo() {

    OpenGl::getInstance().deleteBuffers(1, &id);

}

int Ubo::create() {

    OpenGl::getInstance().genBuffers(1, &id);

    return 0;
}

int Ubo::connect(GLuint program, UboBindIndex bindIndex, std::string blockName) {

    GLuint blockIndex = OpenGl::getInstance().getUniformBlockIndex(program, blockName.c_str());
    OpenGl::getInstance().bindBufferBase(GL_UNIFORM_BUFFER, bindIndex, id);
    OpenGl::getInstance().uniformBlockBinding(program, blockIndex, bindIndex);

    return 0;
}

int Ubo::set(GLvoid *data, GLuint size) {

    OpenGl::getInstance().bindBuffer(GL_UNIFORM_BUFFER, id);
    OpenGl::getInstance().bufferData(GL_UNIFORM_BUFFER, size, data, GL_DYNAMIC_DRAW);

    return 0;
}

int Ubo::update(GLvoid *data, GLuint size) {

    OpenGl::getInstance().bindBuffer(GL_UNIFORM_BUFFER, id);
    GLvoid* p = OpenGl::getInstance().mapBuffer(GL_UNIFORM_BUFFER, GL_WRITE_ONLY);
    memcpy(p, data, size);
    OpenGl::getInstance().unmapBuffer(GL_UNIFORM_BUFFER);

    return 0;
}
