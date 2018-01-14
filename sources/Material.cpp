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
    for (auto &texture : _textures)
        texture.bind(shader, block++);
    skyBox.bind(shader, block);
}
