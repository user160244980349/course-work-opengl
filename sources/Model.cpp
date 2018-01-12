//
// Created by user on 11.01.2018.
//

#include <utility>
#include <iostream>

#include "core/Model.h"

void Model::render(Shader shader) {
    for (auto &mesh : _meshes) {
        mesh.render(shader);
    }
}

void Model::prepare(Shader shader) {
    for (auto &mesh : _meshes) {
        mesh.prepare(shader);
    }
}

void Model::build(std::vector<Mesh> meshes) {
    _meshes = std::move(meshes);
}
