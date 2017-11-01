//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_SCENE_H
#define OPENGL_SCENE_H

#include <objects/IScene.h>
#include <graphics/IDrawable.h>
#include <input/IInput.h>

namespace application::graphics {

    class Scene : public objects::IScene {
    public:
        explicit Scene(input::IInput* input);
        ~Scene();
        int prepare() override;
        int draw() override;

    protected:
        input::IInput* _input;
        objects::ICamera* _camera;
        std::list<graphics::IDrawable*> _objects{};
    };

}

#endif //OPENGL_SCENE_H
