//
// Created by user on 16.01.2018.
//

#include <core/OpenGl.h>
#include <glm/detail/type_mat.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <core/Shader.h>
#include <core/DirectionalLight.h>
#include "core/ShadowMap.h"

void ShadowMap::prepare() {
    OpenGl::getInstance().genTextures(1, &_id);
    OpenGl::getInstance().bindTexture(GL_TEXTURE_2D, _id);
    OpenGl::getInstance().texImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT,
                                     1920, 1080, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
    OpenGl::getInstance().texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    OpenGl::getInstance().texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    OpenGl::getInstance().texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    OpenGl::getInstance().texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    _fbo.bind();
    OpenGl::getInstance().framebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, _id, 0);
    OpenGl::getInstance().drawBuffer(GL_NONE);
    OpenGl::getInstance().readBuffer(GL_NONE);

}

void ShadowMap::bind() {
    OpenGl::getInstance().activeTexture(GL_TEXTURE0);
    OpenGl::getInstance().bindTexture(GL_TEXTURE_2D, _id);
}

void ShadowMap::buildMap(DirectionalLight &light, Shader &shader) {
    shader.use();
    shader.setUniform("lightProjection", light.getProjection());
    shader.setUniform("lightPosition", light.getPosition());
    shader.setUniform("lightView", light.getView());
    _fbo.bind();
    OpenGl::getInstance().clear(GL_DEPTH_BUFFER_BIT);
}
