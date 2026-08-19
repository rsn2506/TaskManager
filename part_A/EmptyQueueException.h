#ifndef EMPTY_QUEUE_EXCEPTION_H
#define EMPTY_QUEUE_EXCEPTION_H

#include <stdexcept>
#include <string>

class EmptyQueueException : public std::runtime_error {
public:
    explicit EmptyQueueException(const std::string& message = "Queue is empty")
        : std::runtime_error(message) {}
};

#endif // EMPTY_QUEUE_EXCEPTION_H
