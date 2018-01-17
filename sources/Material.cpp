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

    shader.setUniform("ka", glm::normalize(glm::vec3(0.2125, 0.2275, 0.254)));
    shader.setUniform("kd", glm::normalize(glm::vec3(0.3, 0.4284, 0.48144)));
    shader.setUniform("ks", glm::normalize(glm::vec3(0.1, 0.1, 0.1)));
    shader.setUniform("s", 8.0f);

    unsigned int block = 1;
    for (auto &texture : _textures)
        texture.bind(shader, block++);
}
