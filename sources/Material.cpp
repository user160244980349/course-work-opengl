//
// Created by user on 12.01.2018.
//

#include <iostream>
#include <objects/SkyBox.h>
#include <SDL2/SDL_timer.h>
#include "core/Material.h"


void Material::build(std::vector<Texture> textures) {
    _textures = std::move(textures);
}

void Material::bind(Shader &shader) {

    shader.use();
    shader.setUniform("ka", glm::normalize(glm::vec3(0.05375f, 0.05f, 0.06625f)));
    shader.setUniform("kd", glm::normalize(glm::vec3(0.18275f, 0.17f, 0.22525f)));
    shader.setUniform("ks", glm::normalize(glm::vec3(0.332741f, 0.328634f, 0.346435f)));
    shader.setUniform("s", 128.0f);
    shader.setUniform("lightPos", glm::vec3(sinf(SDL_GetTicks() * 0.001f), -1.0f, cosf(SDL_GetTicks() * 0.001f)));

    unsigned int block = 0;
    for (auto &texture : _textures)
        texture.bind(shader, block++);
}
