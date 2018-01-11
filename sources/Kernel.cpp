//
// Created by user on 07.10.2017.
//

#include <core/UserInput.h>
#include <core/Graphics.h>
#include <core/Kernel.h>
#include <commands/QuitCommand.h>

void Kernel::prepare() {
    UserInput::getInstance().addCommand(new QuitCommand());
};

void Kernel::run() {
    _running = true;

    _scene.prepare();

    while (_running) {
        UserInput::getInstance().perform();
        Graphics::getInstance().render(_scene);
    }

}

void Kernel::stop() {
    _running = false;
}

Kernel &Kernel::getInstance() {
    static Kernel instance;
    return instance;
}

Kernel::Kernel() = default;

