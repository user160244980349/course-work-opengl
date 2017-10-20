//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_SCENE_H
#define OPENGL_SCENE_H

#include "AbstractScene.h"
#include "ObserverInterface.h"
#include "Subject.h"

namespace application::test {

    class Scene : public AbstractScene {
    public:
        explicit Scene(Subject* subject);
        int prepare() override;
        int draw() override;

    protected:
        Subject* _subject;
    };

}


#endif //OPENGL_SCENE_H
