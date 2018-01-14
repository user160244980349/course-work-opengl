//
// Created by user on 11.01.2018.
//

#include <utility>
#include <iostream>

#include "core/Model.h"

void Model::render(Shader shader, ICamera &camera, SkyBox &skyBox) {
//  glm::normalize(glm::vec3(sinf(SDL_GetTicks()*0.01f)*5.0f, -1.0f, cosf(SDL_GetTicks()*0.01f)*5.0f)));

    shader.setUniform("light.direction", glm::normalize(glm::vec3(-1.0f)));
    shader.setUniform("light.color", glm::normalize(glm::vec3(1.0f)));

    shader.setUniform("material.ka", 0.2f);
    shader.setUniform("material.kd", 0.1f);
    shader.setUniform("material.ks", 0.5f);
    shader.setUniform("material.s", 32.0f);

//    shader.setUniform("material.ka", (sinf(SDL_GetTicks()*0.001f) + 1.0f)*0.5f);
//    shader.setUniform("material.kd", (sinf(SDL_GetTicks()*0.001f) + 1.0f)*0.5f);
//    shader.setUniform("material.ks", (sinf(SDL_GetTicks()*0.001f) + 1.0f)*0.5f);
//    shader.setUniform("material.s", (sinf(SDL_GetTicks()*0.001f) + 1.0f)*100.0f);

    for (auto &mesh : _meshes) {
        mesh.render(shader, skyBox);
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
