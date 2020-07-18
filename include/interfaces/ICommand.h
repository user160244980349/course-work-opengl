#ifndef OPENGL_ICOMMAND_H
#define OPENGL_ICOMMAND_H


class ICommand {
public:
    virtual ~ICommand() = default;
    virtual void execute() {};
};


#endif //OPENGL_ICOMMAND_H
