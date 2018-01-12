//
// Created by user on 07.12.2017.
//

#include <core/Mesh.h>
#include <iostream>
#include <math.h>


void Mesh::prepare(Shader &shader) {

    unsigned int portion;

    _buffers.vao.create();
    _buffers.vao.bind();

    _buffers.vbo.create();
    _buffers.vbo.set(_vertices.data(), _vertices.size() * sizeof(Vertex));

    portion = 3;
    shader.enableAttribute("position");
    _buffers.vbo.attach(shader, "position", portion, sizeof(Vertex), (void *) offsetof(Vertex, position));

    portion = 3;
    shader.enableAttribute("normal");
    _buffers.vbo.attach(shader, "normal", portion, sizeof(Vertex), (void *) offsetof(Vertex, normal));

    portion = 2;
    shader.enableAttribute("uv");
    _buffers.vbo.attach(shader, "uv", portion, sizeof(Vertex), (void *) offsetof(Vertex, uv));

    portion = 3;
    shader.enableAttribute("tangent");
    _buffers.vbo.attach(shader, "tangent", portion, sizeof(Vertex), (void *) offsetof(Vertex, tangent));

    portion = 3;
    shader.enableAttribute("bitangent");
    _buffers.vbo.attach(shader, "bitangent", portion, sizeof(Vertex), (void *) offsetof(Vertex, bitangent));

    _buffers.ebo.create();
    _buffers.ebo.set(_indices.data(), _indices.size());

}

void Mesh::render(Shader &shader) {
    shader.use();
    shader.setUniform("light.position", glm::vec3(0.0f));
    shader.setUniform("light.ambient", glm::vec3(0.8f));
    shader.setUniform("light.diffuse", glm::vec3(1.0f));
    shader.setUniform("light.specular", glm::vec3(1.0f));

    _material.bind(shader);
    _buffers.vao.render(GL_TRIANGLES, _indices.size());
}

Mesh::~Mesh() {
    _buffers.vao.remove();
    _buffers.vbo.remove();
    _buffers.ebo.remove();
}

void Mesh::build(std::vector<Vertex> vertices, std::vector<unsigned int> indices, Material material) {
    _vertices = std::move(vertices);
    _indices = std::move(indices);
    _material = std::move(material);
}
