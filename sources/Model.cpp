//
// Created by user on 11.01.2018.
//

#include <utility>
#include <iostream>

#include "core/Model.h"

void Model::render(Shader shader, ICamera &camera, SkyBox &skyBox) {

    shader.use();
    shader.setUniform("light.direction", glm::normalize(glm::vec3(0.5f, -1.0f, 0.5f)));
    shader.setUniform("light.ambient", glm::vec3(0.1f));
    shader.setUniform("light.diffuse", glm::vec3(0.7f));
    shader.setUniform("light.specular", glm::vec3(0.2f));
    shader.setUniform("material.shininess", 0.2f);

    for (auto &mesh : _meshes) {
        mesh.render(shader, skyBox);
    }
}

void Model::prepare(Shader shader) {
    shader.use();

    for (auto &mesh : _meshes) {
        mesh.prepare(shader);
    }
}

void Model::build(std::vector<Mesh> meshes) {
    _meshes = std::move(meshes);
}
