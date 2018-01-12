//
// Created by user on 07.10.2017.
//

#ifndef OPENGL_KERNEL_H
#define OPENGL_KERNEL_H

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


#endif //OPENGL_KERNEL_H
