//
// Created by user on 07.10.2017.
//

#ifndef OPENGL_APPLICATION_H
#define OPENGL_APPLICATION_H

#include <SDL2/SDL.h>
#include <objects/Scene.h>
#include <graphics/Graphics.h>
#include <input/ClientInput.h>


class Kernel {
public:
    static Kernel& getInstance();
    int run();
    int stop();

protected:
    Kernel();

    bool _running;
};


#endif //OPENGL_APPLICATION_H
