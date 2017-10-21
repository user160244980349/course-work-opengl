//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_SCENE_H
#define OPENGL_SCENE_H


#include <interfaces&abstractions/IDynamicCamera.h>
#include <interfaces&abstractions/IScene.h>
#include <interfaces&abstractions/IDrawable.h>

namespace application::graphics {

    class Scene : public IScene {
    public:
        explicit Scene(templates::ISubject* subject);
        int prepare() override;
        int draw() override;

    protected:
        templates::ISubject* _subject;
        objects::IDynamicCamera* _camera;
        std::list<IDrawable*> _objects{};
    };

}


#endif //OPENGL_SCENE_H
