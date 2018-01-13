//
// Created by user on 11.01.2018.
//

#include <utility>
#include <iostream>

#include "core/Model.h"

void Model::render(Shader shader) {

    shader.use();
    shader.setUniform("light.position", glm::vec3(0.0f, 5.0f, 0.0f));
    shader.setUniform("light.ambient", glm::vec3(0.2f));
    shader.setUniform("light.diffuse", glm::vec3(0.3f));
    shader.setUniform("light.specular", glm::vec3(0.6f));
    shader.setUniform("material.shininess", 64.0f);

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
