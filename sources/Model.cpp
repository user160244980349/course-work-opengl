//
// Created by user on 11.01.2018.
//

#include <utility>
#include <iostream>

#include "core/Model.h"

void Model::render(Shader shader, ICamera &camera, SkyBox &skyBox) {
    for (auto &mesh : _meshes)
        mesh.render(shader, skyBox);
}

void Model::prepare(Shader shader) {
    shader.use();

    for (auto &mesh : _meshes)
        mesh.prepare(shader);
}

void Model::build(std::vector<Mesh> meshes) {
    _meshes = std::move(meshes);
}
