//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_GRAPHICS_H
#define OPENGL_GRAPHICS_H

namespace application::graphics {

    class Graphics {
    public:

        Graphics(Uint32 width, Uint32 height, Uint32 fps);
        int swapWindow();
        ~Graphics();

    protected:
        SDL_Window* _window;
        Uint32 _width;
        Uint32 _height;
        Uint32 _fps;
    };

}


#endif //OPENGL_GRAPHICS_H
