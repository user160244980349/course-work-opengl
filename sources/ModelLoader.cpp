//
// Created by user on 11.01.2018.
//

#include <glm/vec3.hpp>
#include <iostream>
#include <core/Model.h>
#include "core/ModelLoader.h"


Model ModelLoader::load(std::string path) {

    Assimp::Importer importer;
    _directory = "../resources/models/";
    const aiScene *scene = importer.ReadFile(_directory + path,
                                             aiProcess_Triangulate | aiProcess_GenUVCoords | aiProcess_FlipUVs |
                                             aiProcess_GenSmoothNormals | aiProcess_CalcTangentSpace);

    if (scene == nullptr) {
        std::cerr << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
        exit(0);
    }

    _directory += path.substr(0, path.find_last_of('/'));

    sceneBypass(scene->mRootNode, scene);

    Model newModel;
    newModel.build(_meshes);
    _meshes.clear();

    return newModel;
}

void ModelLoader::sceneBypass(aiNode *node, const aiScene *scene) {
    if (scene->HasMaterials()) {
        for (unsigned int i = 0; i < node->mNumMeshes; i++) {
            aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
            _meshes.push_back(buildMesh(mesh, scene));
        }
        for (unsigned int i = 0; i < node->mNumChildren; i++) {
            sceneBypass(node->mChildren[i], scene);
        }
    }
}

std::vector<Texture> ModelLoader::loadMaps(aiMaterial *mat, aiTextureType type) {
    std::vector<Texture> textures;
    unsigned int diffuseCounter = 1;
    unsigned int specularCounter = 1;

    for (unsigned int i = 0; i < mat->GetTextureCount(type); i++) {
        aiString str;
        mat->GetTexture(type, i, &str);

        Texture texture;

        switch (type) {
            case aiTextureType_DIFFUSE:
                texture.load(_directory + '/' + str.C_Str(), "material.diffuse");
                break;

            case aiTextureType_SPECULAR:
                texture.load(_directory + '/' + str.C_Str(), "material.specular");
                break;
        }

        textures.push_back(texture);
    }

    return textures;
}

Mesh ModelLoader::buildMesh(aiMesh *mesh, const aiScene *scene) {

    std::vector<Vertex> vertices{};
    for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
        Vertex vertex;

        if (mesh->HasPositions())
            vertex.position = glm::vec3(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z);

        if (mesh->HasNormals())
            vertex.normal = glm::vec3(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z);

        if (mesh->HasTextureCoords(0))
            vertex.uv = glm::vec2(mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y);

        if (mesh->HasTangentsAndBitangents()) {
            vertex.tangent = glm::vec3(mesh->mTangents[i].x, mesh->mTangents[i].y, mesh->mTangents[i].z);
            vertex.bitangent = glm::vec3(mesh->mBitangents[i].x, mesh->mBitangents[i].y, mesh->mBitangents[i].z);
        }

        vertices.push_back(vertex);
    }

    std::vector<unsigned int> indices{};
    if (mesh->HasFaces()) {
        for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
            aiFace face = mesh->mFaces[i];
            for (unsigned int j = 0; j < face.mNumIndices; j++)
                indices.push_back(face.mIndices[j]);
        }
    }
    std::vector<Texture> textures;

    if (mesh->mMaterialIndex) {
        aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];

        std::vector<Texture> diffuseMaps = loadMaps(material, aiTextureType_DIFFUSE);
        textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

        std::vector<Texture> specularMaps = loadMaps(material, aiTextureType_SPECULAR);
        textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
    }

    Mesh newMesh;
    Material newMaterial;

    newMaterial.build(textures);
    newMesh.build(vertices, indices, newMaterial);

    return newMesh;
}

ModelLoader &ModelLoader::getInstacne() {
    static ModelLoader instance;
    return instance;
}
