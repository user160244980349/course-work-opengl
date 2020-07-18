#ifndef OPENGL_KERNEL_H
#define OPENGL_KERNEL_H


#include <SDL.h>

#include "../objects/Scene.h"

class Kernel {
public:
    static Kernel &getInstance();
    void prepare();
    void run();
    void stop();

protected:
    Scene _scene;
    bool _running;

    Kernel();
};


#endif //OPENGL_KERNEL_H
