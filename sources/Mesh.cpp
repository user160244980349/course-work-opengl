//
// Created by user on 07.12.2017.
//

#include <core/Mesh.h>
#include <iostream>


void Mesh::prepare(Shader &shader) {

    unsigned int portion;

    _buffers.vao.create();
    _buffers.vao.bind();

    _buffers.vbo.create();
    _buffers.vbo.allocate(_vertices.data(), _vertices.size() * sizeof(Vertex));

    portion = 3;
    shader.enableAttribute("aPos");
    _buffers.vbo.attach(shader, "aPos", portion, sizeof(Vertex), (void *) offsetof(Vertex, position));

    portion = 3;
    shader.enableAttribute("aNormal");
    _buffers.vbo.attach(shader, "aNormal", portion, sizeof(Vertex), (void *) offsetof(Vertex, normal));

    portion = 2;
    shader.enableAttribute("aTexCoords");
    _buffers.vbo.attach(shader, "aTexCoords", portion, sizeof(Vertex), (void *) offsetof(Vertex, uv));

    portion = 3;
    shader.enableAttribute("aTangent");
    _buffers.vbo.attach(shader, "aTangent", portion, sizeof(Vertex), (void *) offsetof(Vertex, tangent));

    portion = 3;
    shader.enableAttribute("aBitangent");
    _buffers.vbo.attach(shader, "aBitangent", portion, sizeof(Vertex), (void *) offsetof(Vertex, bitangent));

    _buffers.ebo.create();
    _buffers.ebo.set(_indices.data(), _indices.size());

}

void Mesh::render(Shader &shader, SkyBox &skyBox) {
    _material.bind(shader, skyBox);
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
