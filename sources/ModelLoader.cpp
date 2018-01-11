//
// Created by user on 11.01.2018.
//

#include <glm/vec3.hpp>
#include <iostream>
#include <core/Model.h>
#include "core/ModelLoader.h"


Model ModelLoader::load(std::string path) {

    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_GenNormals);

    if (scene == nullptr || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cerr << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
        exit(0);
    }

    _directory = path.substr(0, path.find_last_of('/'));
    sceneBypass(scene->mRootNode, scene);

    Model newModel;
    newModel.build(_meshes);
    _meshes.clear();

    return newModel;
}

void ModelLoader::sceneBypass(aiNode *node, const aiScene *scene) {
    for (unsigned int i = 0; i < node->mNumMeshes; i++) {
        aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
        _meshes.push_back(buildMesh(mesh));
    }
    for (unsigned int i = 0; i < node->mNumChildren; i++) {
        sceneBypass(node->mChildren[i], scene);
    }
}

Mesh ModelLoader::buildMesh(aiMesh *mesh) {

    std::vector<Vertex> vertices{};
    for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
        Vertex vertex;
        // position
        if (mesh->HasPositions())
            vertex.position = glm::vec3(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z);

        // normal
        if (mesh->HasNormals())
            vertex.normal = glm::vec3(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z);

        // texture coords
        if (mesh->HasTextureCoords(0))
            vertex.uv = glm::vec2(mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y);
        else
            vertex.uv = glm::vec2(0.0f, 0.0f);

        if (mesh->HasTangentsAndBitangents()) {
            // tangent
            vertex.tangent = glm::vec3(mesh->mTangents[i].x, mesh->mTangents[i].y, mesh->mTangents[i].z);
            // bitangent
            vertex.bitangent = glm::vec3(mesh->mBitangents[i].x, mesh->mBitangents[i].y, mesh->mBitangents[i].z);
        }

        vertices.push_back(vertex);
    }

    // indices
    std::vector<unsigned int> indices{};
    if (mesh->HasFaces()) {
        for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
            aiFace face = mesh->mFaces[i];
            for (unsigned int j = 0; j < face.mNumIndices; j++)
                indices.push_back(face.mIndices[j]);
        }
    }

    Mesh newMesh;
    newMesh.build(vertices, indices);

    return newMesh;
}

ModelLoader &ModelLoader::getInstacne() {
    static ModelLoader instance;
    return instance;
}

ModelLoader::ModelLoader() = default;
