#include <glm/gtc/matrix_transform.hpp>

#include "../include/core/OpenGl.h"
#include "../include/core/Shader.h"
#include "../include/core/ShadowMap.h"

void ShadowMap::prepare() {
    OpenGl::getInstance().genFramebuffers(1, &_fbo);
    OpenGl::getInstance().genTextures(1, &_id);
    OpenGl::getInstance().bindTexture(GL_TEXTURE_2D, _id);
    OpenGl::getInstance().texImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT,
                                     1920, 1080, 0, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr);
    OpenGl::getInstance().texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    OpenGl::getInstance().texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    OpenGl::getInstance().texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    OpenGl::getInstance().texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    OpenGl::getInstance().bindFramebuffer(GL_FRAMEBUFFER, 1);
    OpenGl::getInstance().framebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, _id, 0);
    OpenGl::getInstance().drawBuffer(GL_NONE);
    OpenGl::getInstance().readBuffer(GL_NONE);
    OpenGl::getInstance().bindFramebuffer(GL_FRAMEBUFFER, 0);
}

void ShadowMap::bind(Shader &shader) {
    shader.use();
    OpenGl::getInstance().activeTexture(GL_TEXTURE0);
    shader.setUniform("shadowMap", 0);
    OpenGl::getInstance().bindTexture(GL_TEXTURE_2D, _id);
}

void ShadowMap::bindForBuild(Shader &shader) {
    shader.use();
    OpenGl::getInstance().bindFramebuffer(GL_FRAMEBUFFER, _fbo);
    OpenGl::getInstance().clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    OpenGl::getInstance().framebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, _id, 0);
    OpenGl::getInstance().activeTexture(GL_TEXTURE0);
    OpenGl::getInstance().bindTexture(GL_TEXTURE_2D, _id);
}

void ShadowMap::unbind() {
    OpenGl::getInstance().bindFramebuffer(GL_FRAMEBUFFER, 0);
    OpenGl::getInstance().clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

unsigned int ShadowMap::getId() {
    return _id;
}
