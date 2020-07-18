#ifndef OPENGL_ANGELLUCY_H
#define OPENGL_ANGELLUCY_H


#include <vector>

#include "../core/Vbo.h"
#include "../core/Vao.h"
#include "../core/Ebo.h"
#include "../core/Shader.h"
#include "../core/Mesh.h"
#include "../core/Transform.h"
#include "../core/Model.h"
#include "../interfaces/IDrawable.h"
#include "../interfaces/IObject.h"
#include "../interfaces/ICamera.h"
#include "BaseObject.h"

class AngelLucy : public IDrawable, public BaseObject {
public:
    void prepare(Shader &shader) override;
    void render(Shader &shader, ICamera &camera) override;
    void update() override;

protected:
    Model _model;
};


#endif //OPENGL_ANGELLUCY_H
