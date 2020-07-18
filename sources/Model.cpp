#include <utility>
#include <iostream>

#include "../include/core/Model.h"

void Model::render(Shader shader, ICamera &camera) {
    for (auto &mesh : _meshes)
        mesh.render(shader);
}

void Model::prepare(Shader shader) {
    shader.use();

    for (auto &mesh : _meshes)
        mesh.prepare(shader);
}

void Model::build(std::vector<Mesh> meshes) {
    _meshes = std::move(meshes);
}
