//
// Created by user on 12.01.2018.
//

#include <iostream>
#include "core/Material.h"


void Material::build(std::vector<Texture> textures) {
    _textures = std::move(textures);
}

void Material::bind(Shader &shader) {
    unsigned int block = 0;
    for (auto &texture : _textures)
        texture.bind(shader, block++);
}
