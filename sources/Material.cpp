//
// Created by user on 12.01.2018.
//

#include <iostream>
#include <objects/SkyBox.h>
#include "core/Material.h"


void Material::build(std::vector<Texture> textures) {
    _textures = std::move(textures);
}

void Material::bind(Shader &shader) {

    shader.use();
    shader.setUniform("ka", glm::normalize(glm::vec3(0.05375f, 0.05f, 0.06625f)));
    shader.setUniform("kd", glm::normalize(glm::vec3(0.58275f, 0.57f, 0.62525f)));
    shader.setUniform("ks", glm::normalize(glm::vec3(0.332741f, 0.328634f, 0.346435f)));
    shader.setUniform("s", 128.0f);

    unsigned int block = 1;
    for (auto &texture : _textures)
        texture.bind(shader, block++);
}
