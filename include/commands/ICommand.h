//
// Created by user on 30.10.2017.
//

#ifndef OPENGL_ICOMMAND_H
#define OPENGL_ICOMMAND_H

namespace application::commands {

    class ICommand {
    public:
        virtual int execute() = 0;
    };

}


#endif //OPENGL_ICOMMAND_H
