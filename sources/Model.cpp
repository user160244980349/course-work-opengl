//
// Created by user on 11.01.2018.
//

#include <utility>

#include "core/Model.h"

void Model::render(ShaderProgram shader) {
    for (auto &mesh : _meshes) {
        mesh.render(shader);
    }
}

void Model::prepare(ShaderProgram shader) {
    for (auto &mesh : _meshes) {
        mesh.prepare(shader);
    }
}

void Model::build(std::vector<Mesh> meshes) {
    _meshes = std::move(meshes);
}
