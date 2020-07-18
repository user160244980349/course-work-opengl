#ifndef OPENGL_BASEEXCEPTION_H
#define OPENGL_BASEEXCEPTION_H


#include <exception>
#include <string>

class BaseException : public std::exception {
public:
    explicit BaseException(std::string msg);
    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override;

private:
    std::string _msg;
};


#endif //OPENGL_BASEEXCEPTION_H
