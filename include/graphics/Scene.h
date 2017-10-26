//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_SCENE_H
#define OPENGL_SCENE_H


#include <interfaces/IDynamicCamera.h>
#include <interfaces/IScene.h>
#include <interfaces/IDrawable.h>

namespace application::graphics {

    class Scene : public objects::IScene {
    public:
        explicit Scene(input::IInput* subject);
        ~Scene();
        int prepare() override;
        int draw() override;

    protected:
        input::IInput* _subject;
        objects::IDynamicCamera* _camera;
        std::list<IDrawable*> _objects{};
    };

}


#endif //OPENGL_SCENE_H
