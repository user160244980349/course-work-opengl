//
// Created by user on 07.12.2017.
//

#include "CubeMesh.h"

CubeMesh::CubeMesh() {
    _vertices.emplace_back(glm::vec3( 1.0f, 1.0f,-1.0f));
    _vertices.emplace_back(glm::vec3(-1.0f, 1.0f,-1.0f));
    _vertices.emplace_back(glm::vec3(-1.0f,-1.0f,-1.0f));
    _vertices.emplace_back(glm::vec3( 1.0f,-1.0f,-1.0f));

    _vertices.emplace_back(glm::vec3( 1.0f, 1.0f, 1.0f));
    _vertices.emplace_back(glm::vec3(-1.0f, 1.0f, 1.0f));
    _vertices.emplace_back(glm::vec3(-1.0f,-1.0f, 1.0f));
    _vertices.emplace_back(glm::vec3( 1.0f,-1.0f, 1.0f));

    _order.emplace_back(0u);
    _order.emplace_back(3u);
    _order.emplace_back(1u);
    _order.emplace_back(1u);
    _order.emplace_back(3u);
    _order.emplace_back(2u);

    _order.emplace_back(2u);
    _order.emplace_back(5u);
    _order.emplace_back(1u);
    _order.emplace_back(6u);
    _order.emplace_back(5u);
    _order.emplace_back(2u);

    _order.emplace_back(5u);
    _order.emplace_back(7u);
    _order.emplace_back(4u);
    _order.emplace_back(6u);
    _order.emplace_back(7u);
    _order.emplace_back(5u);

    _order.emplace_back(0u);
    _order.emplace_back(4u);
    _order.emplace_back(3u);
    _order.emplace_back(3u);
    _order.emplace_back(4u);
    _order.emplace_back(7u);

    _order.emplace_back(2u);
    _order.emplace_back(7u);
    _order.emplace_back(6u);
    _order.emplace_back(3u);
    _order.emplace_back(7u);
    _order.emplace_back(2u);

    _order.emplace_back(1u);
    _order.emplace_back(4u);
    _order.emplace_back(0u);
    _order.emplace_back(5u);
    _order.emplace_back(4u);
    _order.emplace_back(1u);

    _buffers.vao.create();
    _buffers.vao.bind();

    _buffers.vbo.create();
    _buffers.vbo.set(_vertices.data(), static_cast<GLuint>(_vertices.size()));

    _buffers.ebo.create();
    _buffers.ebo.set(_order.data(), static_cast<GLuint>(_order.size()));
}

void CubeMesh::render() {
    _buffers.vao.bind(GL_TRIANGLES, static_cast<GLuint>(_order.size()));
}

CubeMesh::~CubeMesh() {
    _buffers.vao.remove();
    _buffers.vbo.remove();
    _buffers.ebo.remove();
}
