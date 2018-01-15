//
// Created by user on 12.01.2018.
//

#include <iostream>
#include <objects/SkyBox.h>
#include "core/Material.h"


void Material::build(std::vector<Texture> textures) {
    _textures = std::move(textures);
}

void Material::bind(Shader &shader, SkyBox &skyBox) {
    unsigned int block = 0;
//    shader.setUniform("light.direction", glm::normalize(glm::vec3(-1.0f)));
//    shader.setUniform("light.color", glm::normalize(glm::vec3(1.0f)));
//    shader.setUniform("material.ka", 0.2f);
//    shader.setUniform("material.kd", 0.1f);
//    shader.setUniform("material.ks", 0.0f);
//    shader.setUniform("material.s", 32.0f);
    shader.setUniform("lightPos", glm::vec3(1.0f, -1.0f, -1.0f));

    for (auto &texture : _textures)
        texture.bind(shader, block++);

    skyBox.bind(shader, block);
}
