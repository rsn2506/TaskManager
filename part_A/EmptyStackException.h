#ifndef EMPTY_STACK_EXCEPTION_H
#define EMPTY_STACK_EXCEPTION_H

#include <stdexcept>
#include <string>

class EmptyStackException : public std::runtime_error {
public:
    explicit EmptyStackException(const std::string& message = "Stack is empty")
        : std::runtime_error(message) {}
};

#endif // EMPTY_STACK_EXCEPTION_H
