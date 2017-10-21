//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_SCENE_H
#define OPENGL_SCENE_H

#include <Interfaces&Abstractions/DynamicCameraInterface.h>
#include "Interfaces&Abstractions/AbstractScene.h"
#include "Interfaces&Abstractions/ObserverInterface.h"
#include "Interfaces&Abstractions/Subject.h"

namespace application::graphics {

    class Scene : public AbstractScene {
    public:
        explicit Scene(templates::Subject* subject);
        int prepare() override;
        int draw() override;

    protected:
        templates::Subject* _subject;
        objects::DynamicCameraInterface* _camera;
    };

}


#endif //OPENGL_SCENE_H
