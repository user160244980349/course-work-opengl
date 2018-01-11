//
// Created by user on 07.12.2017.
//

#include <core/CubeMesh.h>

CubeMesh::CubeMesh() {

    _vertices.emplace_back(glm::vec3(1.0f, 1.0f, -1.0f));
    _vertices.emplace_back(glm::vec3(-1.0f, 1.0f, -1.0f));
    _vertices.emplace_back(glm::vec3(-1.0f, -1.0f, -1.0f));
    _vertices.emplace_back(glm::vec3(1.0f, -1.0f, -1.0f));

    _vertices.emplace_back(glm::vec3(1.0f, 1.0f, 1.0f));
    _vertices.emplace_back(glm::vec3(-1.0f, 1.0f, 1.0f));
    _vertices.emplace_back(glm::vec3(-1.0f, -1.0f, 1.0f));
    _vertices.emplace_back(glm::vec3(1.0f, -1.0f, 1.0f));

    _indices.emplace_back(0u);
    _indices.emplace_back(3u);
    _indices.emplace_back(1u);
    _indices.emplace_back(1u);
    _indices.emplace_back(3u);
    _indices.emplace_back(2u);

    _indices.emplace_back(2u);
    _indices.emplace_back(5u);
    _indices.emplace_back(1u);
    _indices.emplace_back(6u);
    _indices.emplace_back(5u);
    _indices.emplace_back(2u);

    _indices.emplace_back(5u);
    _indices.emplace_back(7u);
    _indices.emplace_back(4u);
    _indices.emplace_back(6u);
    _indices.emplace_back(7u);
    _indices.emplace_back(5u);

    _indices.emplace_back(0u);
    _indices.emplace_back(4u);
    _indices.emplace_back(3u);
    _indices.emplace_back(3u);
    _indices.emplace_back(4u);
    _indices.emplace_back(7u);

    _indices.emplace_back(2u);
    _indices.emplace_back(7u);
    _indices.emplace_back(6u);
    _indices.emplace_back(3u);
    _indices.emplace_back(7u);
    _indices.emplace_back(2u);

    _indices.emplace_back(1u);
    _indices.emplace_back(4u);
    _indices.emplace_back(0u);
    _indices.emplace_back(5u);
    _indices.emplace_back(4u);
    _indices.emplace_back(1u);

}

void CubeMesh::prepare(ShaderProgram &shader) {

    _buffers.vao.create();
    _buffers.vao.bind();

    unsigned int portion = 3;
    _buffers.positionsVbo.create();
    _buffers.positionsVbo.set(_vertices.data(), _vertices.size());
    shader.enableAttribute("vertexPosition");
    _buffers.positionsVbo.attach(shader, "vertexPosition", portion, portion * sizeof(float));

    _buffers.ebo.create();
    _buffers.ebo.set(_indices.data(), _indices.size());

}

void CubeMesh::render(ShaderProgram &shader) {
    shader.use();
    _buffers.vao.render(GL_TRIANGLES, _indices.size());
}

CubeMesh::~CubeMesh() {
    _buffers.vao.remove();
    _buffers.positionsVbo.remove();
    _buffers.ebo.remove();
}
