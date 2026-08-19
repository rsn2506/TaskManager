#include "TaskStack.h"
#include "EmptyStackException.h"
#include <stdexcept>
#include <string>

TaskStack::TaskStack() : top_(nullptr), size_(0) {}

TaskStack::~TaskStack() {
    // TODO: Free all dynamically allocated nodes.
    // Starter stub intentionally does not throw from the destructor.
}

void TaskStack::push(const Task& task) {
    // TODO: Push onto the top in O(1) time.
    (void)task;
    throw std::runtime_error("Not implemented yet");
}

Task TaskStack::pop() {
    // TODO: Pop from the top in O(1) time.
    // Throw EmptyStackException if the stack is empty.
    throw std::runtime_error("Not implemented yet");
}

const Task& TaskStack::top() const {
    // TODO: Return a const reference to the top task without removing it.
    // Throw EmptyStackException if the stack is empty.
    throw std::runtime_error("Not implemented yet");
}

bool TaskStack::isEmpty() const {
    // TODO: Return true iff the stack contains no tasks.
    throw std::runtime_error("Not implemented yet");
}

int TaskStack::size() const {
    // TODO: Return the number of tasks currently on the stack.
    throw std::runtime_error("Not implemented yet");
}

std::string TaskStack::toString() const {
    // TODO: Return "[id1, id2, ...]" from top to bottom (ids only), or "[]" if empty.
    throw std::runtime_error("Not implemented yet");
}
