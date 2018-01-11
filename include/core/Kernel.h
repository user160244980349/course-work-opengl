//
// Created by user on 07.10.2017.
//

#ifndef OPENGL_APPLICATION_H
#define OPENGL_APPLICATION_H

#include <SDL2/SDL.h>
#include <core/Graphics.h>
#include <core/UserInput.h>


class Kernel {
public:
    static Kernel &getInstance();

    void run();

    void stop();

protected:
    Kernel();

    bool _running;
};


#endif //OPENGL_APPLICATION_H
