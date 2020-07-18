#ifndef OPENGL_ICOMMAND_H
#define OPENGL_ICOMMAND_H


class ICommand {
public:
    virtual ~ICommand() = default;
    virtual void execute() = 0;
};


#endif //OPENGL_ICOMMAND_H
