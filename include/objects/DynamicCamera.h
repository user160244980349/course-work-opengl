#ifndef OPENGL_DYNAMICCAMERA_H
#define OPENGL_DYNAMICCAMERA_H


#include <SDL_events.h>

#include "../interfaces/ICamera.h"
#include "../commands/LookVertical.h"
#include "../commands/LookHorizontal.h"
#include "../commands/MoveForward.h"
#include "../commands/MoveBack.h"
#include "../commands/MoveRight.h"
#include "../commands/MoveLeft.h"
#include "../commands/MoveUp.h"
#include "../commands/MoveDown.h"
#include "SkyBox.h"

class DynamicCamera : public ICamera, public IControlable {
public:
    ~DynamicCamera() override;
    void update(std::vector<std::reference_wrapper<Shader>> shaders) override;
    void initCommands() override;
    void prepare();
    glm::mat4 getView() override;
    glm::mat4 getProjection() override;
    glm::vec3 getPosition() override;
    void moveForward();
    void moveBack();
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    void accelerate();
    void lookHorizontal(int x);
    void lookVertical(int y);

protected:
    glm::mat4 projection;
    glm::mat4 viewPoint;

    struct {
        bool w = false;
        bool s = false;
        bool a = false;
        bool d = false;
        bool q = false;
        bool e = false;
        bool shift = false;
    } _keys;

    std::list<IInputCommand *> _commands;
    glm::vec3 _cameraPos;
    glm::vec3 _cameraUp;
    glm::vec3 _cameraFront;

    float _sensitivity;
    float _mouseX;
    float _mouseY;
    float _acceleration;
    float _speedFront;
    float _speedUp;
};


#endif //OPENGL_DYNAMICCAMERA_H
