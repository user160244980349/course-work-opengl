//
// Created by user on 07.10.2017.
//

#ifndef OPENGL_APPLICATION_H
#define OPENGL_APPLICATION_H

#include <SDL2/SDL.h>
#include <objects/Scene.h>


class Kernel {
public:
    static Kernel &getInstance();

    void prepare();

    void run();

    void stop();

protected:
    Kernel();

    Scene _scene;
    bool _running;
};


#endif //OPENGL_APPLICATION_H
