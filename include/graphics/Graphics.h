//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_GRAPHICS_H
#define OPENGL_GRAPHICS_H

#include "IOutput.h"
#include <list>
#include <interfaces/IScene.h>

namespace application::graphics {

    class Graphics : public IOutput {
    public:
        Graphics(Uint32 width, Uint32 height);
        int prepare(IScene* scene) override;
        int draw(IScene* scene) override;
        ~Graphics();

    protected:
        std::list<IScene*> _observers{};
        SDL_Window* _window;
        SDL_GLContext _glContext;
        Uint32 _width;
        Uint32 _height;
        Uint32 _fps;
    };

}


#endif //OPENGL_GRAPHICS_H
