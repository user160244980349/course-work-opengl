//
// Created by user on 07.10.2017.
//

#include <Kernel.h>
#include <commands/QuitCommand.h>

Kernel::Kernel() {
    Graphics::getInstance();
    UserInput::getInstance().addCommand(new QuitCommand());
};

void Kernel::run() {
    _running = true;
    CubeScene* scene = new CubeScene;

    while(_running) {
        UserInput::getInstance().perform();
        Graphics::getInstance().render(*scene);
    }

    delete(scene);
}

void Kernel::stop() {
    _running = false;
}

Kernel &Kernel::getInstance() {
    static Kernel instance;
    return instance;
}
