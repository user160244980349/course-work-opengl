//
// Created by user on 07.10.2017.
//

#ifndef OPENGL_APPLICATION_H
#define OPENGL_APPLICATION_H

#include <SDL2/SDL.h>
#include <objects/Scene.h>
#include <graphics/Graphics.h>
#include <input/AControlable.h>
#include <input/IInput.h>


class Kernel : public AControlable {
public:
    bool running;

    Kernel();
    int initCommands() override;
    ~Kernel();


protected:
    Graphics* _graphics;
    IInput* _input;
    Scene* _scene;

    int flow();
};


#endif //OPENGL_APPLICATION_H
