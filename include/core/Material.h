//
// Created by user on 12.01.2018.
//

#ifndef OPENGL_MATERIAL_H
#define OPENGL_MATERIAL_H


#include <vector>
#include "Shader.h"
#include "Texture.h"
#include "objects/SkyBox.h"

class Material {
public:

    void build(std::vector<Texture> textures);

    void bind(Shader &shader);

protected:
    std::vector<Texture> _textures;

};


#endif //OPENGL_MATERIAL_H
