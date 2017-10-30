//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_SCENE_H
#define OPENGL_SCENE_H

#include <interfaces/IScene.h>
#include <interfaces/IDrawable.h>
#include <interfaces/IInput.h>

namespace application::graphics {

    class Scene : public interfaces::IScene {
    public:
        explicit Scene(interfaces::IInput* input);
        ~Scene();
        int prepare() override;
        int draw() override;

    protected:
        interfaces::IInput* _input;
        interfaces::ICamera* _camera;
        std::list<interfaces::IDrawable*> _objects{};
    };

}

#endif //OPENGL_SCENE_H
